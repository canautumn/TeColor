//
// Created by Can on 9/9/15.
//


#include <TeColor/EigenUtils.h>

namespace tecolor {


void EigenMatrixTransposeInitializer(Eigen::MatrixXd &m,
                                     Index rows,
                                     Index cols,
                                     const std::vector<std::vector<Value>> *data) {
  m.resize(rows, cols);
  for (Index i = 0; i < rows; ++i) {
    for (Index j = 0; j < cols; ++j) {
      m(i, j) = (*data)[j][i];
    }
  }
}

void EigenMatrix1ColumnInitializer(Eigen::MatrixXd &m,
                                   Index rows,
                                   const std::vector<Value> *data) {
  m.resize(rows, 1);
  for (Index i = 0; i < rows; ++i) {
    m(i, 0) = (*data)[i];
  }
}

void EigenVectorInitializer(Eigen::VectorXd &v, Index size, const std::vector<Value> *data) {
  v.resize(size);
  for (Index i = 0; i < size; ++i) {
    v(i) = (*data)[i];
  }
}

Mat EigenMatrixRowMajorInitializer(kValueArray &data, kIndex cols) {
  kIndex rows = data.size() / cols + (data.size() % cols ? 1 : 0);
  Mat mat(rows, cols);
  for (Index r = 0; r < rows; ++r) {
    for (Index c = 0; c < cols; ++c) {
      Index idx = r * cols + c;
      mat(r, c) = idx < data.size() ? data[idx] : 0;
    }
  }
  return mat;
}

} // namespace tecolor