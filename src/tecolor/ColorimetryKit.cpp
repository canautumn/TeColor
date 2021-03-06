//
// Created by Can on 9/2/15.
//

#include <TeColor/ColorimetryKit.h>

namespace tecolor {

CIELAB XYZ2Lab(const Tristimulus &illXYZ, const Tristimulus &sampleXYZ) {
  if (illXYZ.m().cols() != 1) {
    throw std::invalid_argument("XYZ2Lab only takes one sample of illuminant XYZ.");
  }
  if (illXYZ.Y()[0] != 100) {
    throw std::invalid_argument("XYZ2Lab only takes normalized illuminant XYZ with Y = 100.");
  }
  Mat fXYZ = (1.0 / illXYZ.m().array()).matrix().asDiagonal() * sampleXYZ.m();
  fXYZ = (fXYZ.array() > CIELAB_FXYZ_LIMIT).select(pow(fXYZ.array(), CIELAB_FXYZ_C1),
                                                   fXYZ.array() * CIELAB_FXYZ_C2 + CIELAB_FXYZ_C3);
  Mat LabMat(3, sampleXYZ.m().cols());
  LabMat << CIELAB_LAB_C1 * fXYZ.row(1).array() - CIELAB_LAB_C2,
      CIELAB_LAB_C3 * (fXYZ.row(0).array() - fXYZ.row(1).array()),
      CIELAB_LAB_C4 * (fXYZ.row(1).array() - fXYZ.row(2).array());
  return CIELAB(LabMat);

}


CIELAB XYZ2Lab(const Primaries &illxy, const Tristimulus &sampleXYZ) {
  return XYZ2Lab(Illuminantxy2XYZ(illxy), sampleXYZ);
}

CIELAB XYZ2Lab(const Tristimulus &sampleXYZ) {
  Mat illXYZMat(3, 1);
  illXYZMat << CIELAB_D65_X,
      CIELAB_D65_Y,
      CIELAB_D65_Z;
  return XYZ2Lab(Tristimulus(illXYZMat), sampleXYZ);
}

Tristimulus Lab2XYZ(const Tristimulus &illXYZ, const CIELAB &Lab) {
  if (illXYZ.m().cols() != 1) {
    throw std::invalid_argument("Lab2XYZ only takes one sample of illuminant XYZ.");
  }
  if (illXYZ.Y()[0] != 100) {
    throw std::invalid_argument("Lab2XYZ only takes normalized illuminant XYZ with Y = 100.");
  }
  Vec fL = (Lab.L().array() + CIELAB_LAB_C2) / CIELAB_LAB_C1;
  Mat fXYZ(3, Lab.m().cols());
  fXYZ << fL.array() + Lab.a().array() / CIELAB_LAB_C3,
      fL,
      fL.array() - Lab.b().array() / CIELAB_LAB_C4;

  fXYZ = (fXYZ.array() <= CIELAB_FXYZ_INVERSE_LIMIT).select(
      (fXYZ.array() - CIELAB_FXYZ_C3) / CIELAB_FXYZ_C2,
      pow(fXYZ.array(), CIELAB_FXYZ_C1_INVERSE));

  fXYZ = illXYZ.m().asDiagonal() * fXYZ;
  return Tristimulus(fXYZ);
}

Tristimulus Lab2XYZ(const Primaries &illxy, const CIELAB &Lab) {
  return Lab2XYZ(Illuminantxy2XYZ(illxy), Lab);
}

Tristimulus Lab2XYZ(const CIELAB &Lab) {
  Mat illXYZMat(3, 1);
  illXYZMat << CIELAB_D65_X,
      CIELAB_D65_Y,
      CIELAB_D65_Z;
  return Lab2XYZ(Tristimulus(illXYZMat), Lab);
}

Tristimulus Illuminantxy2XYZ(const Primaries &illxy, double normalizedY) {
  if (illxy.primary_names().size() != 2 ||
      illxy.primary_names()[0] != "x" ||
      illxy.primary_names()[1] != "y") {
    throw std::invalid_argument("Non-chromaticities Primaries argument passed into where chromaticities are required.");
  }
  Vec illX = illxy.primary("x").array() / illxy.primary("y").array() * normalizedY;
  Vec illY(illxy.m().cols());
  illY.setOnes();
  illY = illY.array() * normalizedY;
  Vec illZ = (1.0 - illxy.primary("x").array() - illxy.primary("y").array()) / illxy.primary("y").array() * normalizedY;
  Mat illXYZMat(3, illxy.m().cols());
  illXYZMat << illX,
      illY,
      illZ;
  return Tristimulus(illXYZMat);

}

} // namespace tecolor