//
// Created by Can on 9/9/15.
//

#include <TeColor/CIELAB.h>

namespace tecolor {

CIELAB::CIELAB() : primaries_(new Primaries(3, 1, {"L", "a", "b"})) {
  primaries_->m() << 0, 0, 0;
}

CIELAB::CIELAB(Index num_samples)
    : primaries_(new Primaries(3, num_samples, {"L", "a", "b"})) {
  for (Index i = 0; i < 3; ++i) {
    for (Index j = 0; j < num_samples; ++j) {
      primaries_->m()(i, j) = 0;
    }
  }
}

CIELAB::CIELAB(const CIELAB &cielab) {
  primaries_.reset(new Primaries(*cielab.primaries_));
}

CIELAB::CIELAB(const Eigen::MatrixXd &data)
    : primaries_(std::make_shared<Primaries>(Eigen::MatrixXd(data), std::vector<std::string>({"L", "a", "b"}))) {
  if (data.rows() != 3) {
    throw std::invalid_argument("The number of rows of the matrix to construct tristimulus matrix should be 3.");
  }
}

const CIELAB &CIELAB::operator=(const CIELAB &cielab) {
  primaries_.reset(new Primaries(*cielab.primaries_));
  return *this;
}

const Eigen::MatrixXd &CIELAB::m() const {
  return primaries_->m();
}

const Eigen::VectorXd CIELAB::L() const {
  return primaries_->primary("L");
}

const Eigen::VectorXd CIELAB::a() const {
  return primaries_->primary("a");
}

const Eigen::VectorXd CIELAB::b() const {
  return primaries_->primary("b");
}

} // namespace tecolor

