//
// Created by Can on 9/2/15.
//

#ifndef TECOLOR_SPECTRALKIT_H
#define TECOLOR_SPECTRALKIT_H

#include "Illuminant.h"
#include "ColorMatchingFunction.h"
#include "Tristimulus.h"
#include "ReflectanceSet.h"

namespace tecolor {

Tristimulus Refl2XYZ(const Illuminant &ill, const ColorMatchingFunction &cmf, const SpectraMatrix &refl);

}

#endif //TECOLOR_SPECTRALKIT_H
