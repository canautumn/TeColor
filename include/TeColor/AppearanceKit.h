//
// Created by Can on 9/2/15.
//

#ifndef TECOLOR_APPEARANCEKIT_H
#define TECOLOR_APPEARANCEKIT_H

#include "Primaries.h"
#include "Tristimulus.h"

namespace tecolor {

Primaries CIECAM02(const Tristimulus &sampleXYZ,
                   const Tristimulus &illXYZ,
                   kValue La,
                   kValue Yb,
                   kValue F,
                   kValue c,
                   kValue Nc);

kValueArray CIECAT02_M = {0.7328, 0.4296, - 0.1624, -0.7036, 1.6975, 0.0061, 0.0030, 0.0136, 0.9834};
kValueArray
    CIECAT02_M_INV = {1.096124, -0.278869, 0.182745, 0.454369, 0.473533, 0.072098, -0.009628, -0.005698, 1.015326};

kValueArray CIECAM02_MH = {0.38971, 0.68898, -0.07868, -0.22981, 1.18340, 0.04641, 0.0, 0.0, 1.0};


} // namespace tecolor

#endif //TECOLOR_APPEARANCEKIT_H
