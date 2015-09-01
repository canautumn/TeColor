//
// Created by Can on 9/1/15.
//

#include <iostream>
#include "ColorMatchingFunction.h"

namespace tecolor {

using namespace detail;
using Eigen::MatrixXd;
using Eigen::VectorXd;

ColorMatchingFunction::ColorMatchingFunction(ColorMatchingFunctionObserver obs)
    : spectra_(new Spectra()) {

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

  EigenMatrixTransposeInitializer(spectra_->spectra(), CMF_1931_2DEG_NUM_SAMPLES, 3, data);
  EigenVectorInitializer(spectra_->wavelengths(), CMF_1931_2DEG_NUM_SAMPLES, wavelengths);

}

void ColorMatchingFunction::EigenMatrixTransposeInitializer(Eigen::MatrixXd &m,
                                                            Index rows,
                                                            Index cols,
                                                            const std::vector<std::vector<Value>> * data) {
  m.resize(rows, cols);
  std::cout << rows << " " << cols << " "<< std::endl;
  for (Index i = 0; i < rows; ++i) {
    for (Index j = 0; j < cols; ++j) {
      m(i, j) = (*data)[j][i];
    }
  }
}

void ColorMatchingFunction::EigenVectorInitializer(Eigen::VectorXd &v, Index size, const std::vector<Value> * data) {
  v.resize(size);
  for (Index i = 0; i < size; ++i) {
    v(i) = (*data)[i];
  }
}


const Eigen::MatrixX3d ColorMatchingFunction::cmf() const {
  return spectra_->spectra();
}




}
