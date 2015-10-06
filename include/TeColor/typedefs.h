//
// Created by Can on 9/1/15.
//

#ifndef TECOLOR_TYPEDEFS_H
#define TECOLOR_TYPEDEFS_H

#include <cstddef>
#include <vector>
#include <Eigen/Dense>

namespace tecolor {

typedef std::ptrdiff_t Index;
typedef const Index kIndex;
typedef double Value;
typedef const Value kValue;
typedef const std::vector<kValue> kValueArray;
typedef Eigen::MatrixXd Mat;
typedef const Eigen::MatrixXd kMat;
typedef Eigen::VectorXd Vec;
typedef const Eigen::VectorXd kVec;
typedef Eigen::RowVectorXd RVec;
typedef const Eigen::RowVectorXd kRVec;

} // namespace tecolor

#endif //TECOLOR_TYPEDEFS_H
