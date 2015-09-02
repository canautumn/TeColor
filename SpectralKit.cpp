//
// Created by Can on 9/2/15.
//

#include "SpectralKit.h"

namespace tecolor {

Tristimulus Refl2XYZ(const Illuminant &ill, const ColorMatchingFunction &cmf, const SpectraMatrix &refl) {
  // Demo; to add interpolation
  auto k = 100.0 / (ill.spectrum().transpose() * cmf.y())(0);
  return Tristimulus(k * cmf.cmf().transpose() * ill.spectrum().asDiagonal() * refl.spectra());
}

}