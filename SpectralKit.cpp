//
// Created by Can on 9/2/15.
//

#include <iostream>
#include "SpectralKit.h"

using std::cout;
using std::endl;

namespace tecolor {

Tristimulus Refl2XYZ(const Illuminant &ill, const ColorMatchingFunction &cmf, const SpectraMatrix &refl) {
  // Demo; to add interpolation
  auto k = 100.0 / (ill.spectrum().transpose() * cmf.y())(0);
  return Tristimulus(k * cmf.cmf().transpose() * ill.spectrum().asDiagonal() * refl.spectra());
}

Primaries Rad2Yxy(const Illuminant &ill, const ColorMatchingFunction &cmf) {
  // Demo; to add interpolation
  Tristimulus XYZ(683 * cmf.cmf().transpose() * ill.spectrum());
  Mat sumXYZ = XYZ.XYZ().colwise().sum();

  // Do not use type inference for array or matrix calculation.
  // The returning value is a stack-variable to be used for construction temporarily
  Mat x = (XYZ.X().array() / sumXYZ.array()).matrix();
  Mat y = (XYZ.Y().array() / sumXYZ.array()).matrix();

  Mat YxyMat(3, x.cols());
  YxyMat << XYZ.Y(),
      x,
      y;
  return Primaries(YxyMat, {"Y", "x", "y"});
}

Primaries Rad2xy(const Illuminant &ill, const ColorMatchingFunction &cmf) {
  Mat Yxy = Rad2Yxy(ill, cmf).data();
  return Primaries(Eigen::MatrixXd(Yxy.block(1, 0, 2, Yxy.cols())), {"x", "y"});
}

CIELAB XYZ2Lab(const Tristimulus &illXYZ, const Tristimulus &sampleXYZ) {
  if (illXYZ.XYZ().cols() != 1) {
    throw std::invalid_argument("XYZ2Lab only takes one sample of illuminant XYZ.");
  }
  if (illXYZ.Y()[0] != 100) {
    throw std::invalid_argument("XYZ2Lab only takes normalized illuminant XYZ with Y = 100.");
  }
  Mat fXYZ = (1.0 / illXYZ.XYZ().array()).matrix().asDiagonal() * sampleXYZ.XYZ();
  fXYZ = (fXYZ.array() > CIELAB_FXYZ_LIMIT).select(pow(fXYZ.array(), CIELAB_FXYZ_C1),
                                                   fXYZ.array() * CIELAB_FXYZ_C2 + CIELAB_FXYZ_C3);
  Mat Lab(3, sampleXYZ.XYZ().cols());
  Lab << CIELAB_LAB_C1 * fXYZ.row(1).array() - CIELAB_LAB_C2,
      CIELAB_LAB_C3 * (fXYZ.row(0).array() - fXYZ.row(1).array()),
      CIELAB_LAB_C4 * (fXYZ.row(1).array() - fXYZ.row(2).array());
  return CIELAB(Lab);

}


CIELAB XYZ2Lab(const Primaries &illxy, const Tristimulus &sampleXYZ) {
  if (illxy.primary_names().size() != 2 ||
      illxy.primary_names()[0] != "x" ||
      illxy.primary_names()[1] != "y") {
    throw std::invalid_argument("Non-chromaticities Primaries argument passed into where chromaticities are required.");
  }
  double illX = illxy.primary("x")[0] / illxy.primary("y")[0] * 100;
  double illZ = (1.0 - illxy.primary("x")[0] - illxy.primary("y")[0]) / illxy.primary("y")[0] * 100;
  Mat illXYZMat(3, 1);
  illXYZMat << illX,
      100,
      illZ;
  Tristimulus illXYZ(illXYZMat);

  return XYZ2Lab(illXYZ, sampleXYZ);
}

CIELAB XYZ2Lab(const Tristimulus &sampleXYZ) {
  Mat illXYZMat(3, 1);
  illXYZMat << CIELAB_D65_X,
      CIELAB_D65_Y,
      CIELAB_D65_Z;
  Tristimulus illXYZ(illXYZMat);

  return XYZ2Lab(illXYZ, sampleXYZ);
}

}