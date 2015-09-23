//
// Created by Can on 9/2/15.
//

#ifndef TECOLOR_SPECTRAMATRIX_H
#define TECOLOR_SPECTRAMATRIX_H

#include <Eigen/Dense>
#include "typedefs.h"

namespace tecolor {


class SpectraMatrix {
 public:
  virtual const Eigen::MatrixXd &m() const = 0;
  virtual const Eigen::VectorXd spectrum_at(Index index) const = 0;
  virtual const Eigen::VectorXd &wavelengths() const = 0;
};

}

#endif //TECOLOR_SPECTRAMATRIX_H
