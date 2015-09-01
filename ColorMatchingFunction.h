//
// Created by Can on 9/1/15.
//

#ifndef TECOLOR_COLORMATCHINGFUNCTION_H
#define TECOLOR_COLORMATCHINGFUNCTION_H

#include <Eigen/Dense>
#include "Spectra.h"
#include "builtin_database.h"

namespace tecolor {

enum ColorMatchingFunctionObserver {
  Observer1931At2Deg,
  Observer1931At10Deg
};

class ColorMatchingFunction {
  std::shared_ptr<Spectra> spectra_;
  void EigenMatrixTransposeInitializer(Eigen::MatrixXd &m, Index rows, Index cols, const std::vector<std::vector<Value>> * data);
  void EigenVectorInitializer(Eigen::VectorXd &v, Index size, const std::vector<Value> * data);
 public:
  ColorMatchingFunction(ColorMatchingFunctionObserver obs);
  ColorMatchingFunction(ColorMatchingFunctionObserver obs, std::string database_path);
  const Eigen::MatrixX3d cmf() const;
  const Eigen::VectorXd& x() const;
  const Eigen::VectorXd& y() const;
  const Eigen::VectorXd& z() const;
  const Eigen::VectorXd& wavelengths() const;
};

}

#endif //TECOLOR_COLORMATCHINGFUNCTION_H
