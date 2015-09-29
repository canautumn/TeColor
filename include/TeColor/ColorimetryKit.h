//
// Created by Can on 9/29/15.
//

#ifndef TECOLOR_COLORIMETRYKIT_H
#define TECOLOR_COLORIMETRYKIT_H

#include "Primaries.h"
#include "Tristimulus.h"
#include "CIELAB.h"
namespace tecolor {

CIELAB XYZ2Lab(const Tristimulus &illXYZ, const Tristimulus &sampleXYZ);
CIELAB XYZ2Lab(const Primaries &illxy, const Tristimulus &sampleXYZ);
CIELAB XYZ2Lab(const Tristimulus &sampleXYZ);
const double CIELAB_FXYZ_LIMIT = 0.008856;
const double CIELAB_FXYZ_INVERSE_LIMIT = 0.206893;
const double CIELAB_FXYZ_C1 = 1.0 / 3.0;
const double CIELAB_FXYZ_C1_INVERSE = 3.0;
const double CIELAB_FXYZ_C2 = 7.787;
const double CIELAB_LAB_C1 = 116.0;
const double CIELAB_LAB_C2 = 16.0;
const double CIELAB_LAB_C3 = 500.0;
const double CIELAB_LAB_C4 = 200.0;
const double CIELAB_FXYZ_C3 = CIELAB_LAB_C2 / CIELAB_LAB_C1;
const double CIELAB_D65_X = 95.047;
const double CIELAB_D65_Y = 100.00;
const double CIELAB_D65_Z = 108.883;
Tristimulus Lab2XYZ(const Tristimulus &illXYZ, const CIELAB &Lab);
Tristimulus Lab2XYZ(const Primaries &illxy, const CIELAB &Lab);
Tristimulus Lab2XYZ(const CIELAB &Lab);

Tristimulus Illuminantxy2XYZ(const Primaries &illxy, double normalizedY = 100.0);


} // namespace tecolor

#endif //TECOLOR_COLORIMETRYKIT_H
