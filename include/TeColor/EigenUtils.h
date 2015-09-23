//
// Created by Can on 9/2/15.
//

#ifndef TECOLOR_EIGENUTILS_H
#define TECOLOR_EIGENUTILS_H


#include <vector>
#include <Eigen/Dense>
#include "typedefs.h"

namespace tecolor {

void EigenMatrixTransposeInitializer
    (Eigen::MatrixXd &m, Index rows, Index cols, const std::vector<std::vector<Value>> *data);

void EigenMatrix1ColumnInitializer(Eigen::MatrixXd &m,
                                   Index rows,
                                   const std::vector<Value> *data);

void EigenVectorInitializer(Eigen::VectorXd &v, Index size, const std::vector<Value> *data);

}

#endif //TECOLOR_EIGENUTILS_H
