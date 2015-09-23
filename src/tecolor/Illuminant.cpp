//
// Created by Can on 9/2/15.
//

#include <Eigen/Dense>
#include <TeColor/Illuminant.h>

namespace tecolor {

Illuminant::Illuminant(IlluminantName ill)
    : spectra_(new Spectra()) {

  auto num_wavelengths = &detail::ILL_D65_NUM_WAVELENGTHS;
  auto wavelengths = &detail::ILL_D65_WAVELENGTHS;
  auto data = &detail::ILL_D65_SPECTRUM;

  switch (ill) {
    case ILLUMINANT_D50:
      break;
    case ILLUMINANT_D65:
      num_wavelengths = &detail::ILL_D65_NUM_WAVELENGTHS;
      wavelengths = &detail::ILL_D65_WAVELENGTHS;
      data = &detail::ILL_D65_SPECTRUM;
      break;
    case ILLUMINANT_E:
      break;
  }

  EigenMatrix1ColumnInitializer(spectra_->spectra(), *num_wavelengths, data);
  EigenVectorInitializer(spectra_->wavelengths(), *num_wavelengths, wavelengths);
}

const Eigen::VectorXd Illuminant::m() const {
  return spectra_->spectrum_at(0);
}


const Eigen::VectorXd &Illuminant::wavelengths() const {
  return spectra_->wavelengths();
}

}