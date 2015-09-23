//
// Created by Can on 9/1/15.
//

#include <iostream>
#include <TeColor/ColorMatchingFunction.h>
#include <TeColor/EigenUtils.h>

namespace tecolor {

using namespace detail;
using Eigen::MatrixXd;
using Eigen::VectorXd;

ColorMatchingFunction::ColorMatchingFunction(ColorMatchingFunctionObserver obs)
    : spectra_(new Spectra()) {

  auto num_wavelengths = &CMF_1931_2DEG_NUM_WAVELENGTHS;
  auto wavelengths = &CMF_1931_2DEG_WAVELENGTHS;
  auto data = &CMF_1931_2DEG;

  switch (obs) {
    case Observer1931At2Deg:
      wavelengths = &CMF_1931_2DEG_WAVELENGTHS;
      data = &CMF_1931_2DEG;
      break;
    case Observer1931At10Deg:
      break;
  }

  EigenMatrixTransposeInitializer(spectra_->spectra(), *num_wavelengths, 3, data);
  EigenVectorInitializer(spectra_->wavelengths(), *num_wavelengths, wavelengths);

}



const Eigen::MatrixXd& ColorMatchingFunction::m() const {
  return spectra_->m();
}


const Eigen::VectorXd &ColorMatchingFunction::wavelengths() const {
  return spectra_->wavelengths();
}

const Eigen::VectorXd ColorMatchingFunction::x() const {
  return spectra_->spectrum_at(0);
}

const Eigen::VectorXd ColorMatchingFunction::y() const {
  return spectra_->spectrum_at(1);
}

const Eigen::VectorXd ColorMatchingFunction::z() const {
  return spectra_->spectrum_at(2);
}

} // namespace tecolor
