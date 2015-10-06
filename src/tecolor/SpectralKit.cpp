//
// Created by Can on 9/2/15.
//

#include <iostream>
#include <TeColor/SpectralKit.h>

using std::cout;
using std::endl;

namespace tecolor {

Tristimulus Refl2XYZ(const Illuminant &ill, const ColorMatchingFunction &cmf, const SpectraMatrix &refl) {
  // Demo; to add interpolation
  auto k = 100.0 / (ill.m().transpose() * cmf.y())(0);
  return Tristimulus(k * cmf.m().transpose() * ill.m().asDiagonal() * refl.m());
}

Primaries Rad2Yxy(const Illuminant &ill, const ColorMatchingFunction &cmf) {
  // Demo; to add interpolation
  Tristimulus XYZ(683 * cmf.m().transpose() * ill.m());
  Mat sumXYZ = XYZ.m().colwise().sum();

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
  Mat Yxy = Rad2Yxy(ill, cmf).m();
  return Primaries(Mat(Yxy.block(1, 0, 2, Yxy.cols())), {"x", "y"});
}



} // namespace tecolor