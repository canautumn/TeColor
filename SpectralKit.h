//
// Created by Can on 9/2/15.
//

#ifndef TECOLOR_SPECTRALKIT_H
#define TECOLOR_SPECTRALKIT_H

#include "Illuminant.h"
#include "ColorMatchingFunction.h"
#include "Tristimulus.h"
#include "ReflectanceSet.h"
#include "CIELAB.h"

namespace tecolor {


Tristimulus Refl2XYZ(const Illuminant &ill, const ColorMatchingFunction &cmf, const SpectraMatrix &refl);
Primaries Rad2Yxy(const Illuminant &ill, const ColorMatchingFunction &cmf);
Primaries Rad2xy(const Illuminant &ill, const ColorMatchingFunction &cmf);
CIELAB XYZ2Lab(const Tristimulus &illXYZ, const Tristimulus &sampleXYZ);
CIELAB XYZ2Lab(const Primaries &illxy, const Tristimulus &sampleXYZ);
CIELAB XYZ2Lab(const Tristimulus &sampleXYZ);
const double CIELAB_FXYZ_LIMIT = 0.008856;
const double CIELAB_FXYZ_C1 = 1.0 / 3.0;
const double CIELAB_FXYZ_C2 = 7.787;
const double CIELAB_LAB_C1 = 116.0;
const double CIELAB_LAB_C2 = 16.0;
const double CIELAB_LAB_C3 = 500.0;
const double CIELAB_LAB_C4 = 200.0;
const double CIELAB_FXYZ_C3 = CIELAB_LAB_C2 / CIELAB_LAB_C1;
const double CIELAB_D65_X = 95.047;
const double CIELAB_D65_Y = 100.00;
const double CIELAB_D65_Z = 108.883;

}

#endif //TECOLOR_SPECTRALKIT_H
