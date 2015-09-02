//
// Created by Can on 9/1/15.
//

#include <iostream>
#include "ColorMatchingFunction.h"
#include "EigenUtils.h"

namespace tecolor {

using namespace detail;
using Eigen::MatrixXd;
using Eigen::VectorXd;

ColorMatchingFunction::ColorMatchingFunction(ColorMatchingFunctionObserver obs)
    : spectra_(new Spectra()) {

  auto num_samples = &CMF_1931_2DEG_NUM_SAMPLES;
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

  EigenMatrixTransposeInitializer(spectra_->spectra(), *num_samples, 3, data);
  EigenVectorInitializer(spectra_->wavelengths(), *num_samples, wavelengths);

}



const Eigen::MatrixXd& ColorMatchingFunction::cmf() const {
  return spectra_->spectra();
}


const Eigen::VectorXd &ColorMatchingFunction::wavelengths() const {
  return spectra_->wavelengths();
}

}
