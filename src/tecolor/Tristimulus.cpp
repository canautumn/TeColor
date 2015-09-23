//
// Created by Can on 9/2/15.
//

#include <TeColor/Tristimulus.h>

namespace tecolor {


Tristimulus::Tristimulus() : primaries_(new Primaries(3, 1, {"X", "Y", "Z"})) {
  primaries_->data() << 0, 0, 0;
}


Tristimulus::Tristimulus(Index num_samples)
    : primaries_(new Primaries(3, num_samples, {"X", "Y", "Z"})) {
  for (Index i = 0; i < 3; ++i) {
    for (Index j = 0; j < num_samples; ++j) {
      primaries_->data()(i, j) = 0;
    }
  }
}


Tristimulus::Tristimulus(const Tristimulus &tristimulus) {
  primaries_.reset(new Primaries(*tristimulus.primaries_));
}


const Tristimulus &Tristimulus::operator=(const Tristimulus &tristimulus) {
  primaries_.reset(new Primaries(*tristimulus.primaries_));
  return *this;
}

const Eigen::MatrixXd &Tristimulus::m() const {
  return primaries_->m();
}

Tristimulus::Tristimulus(const Eigen::MatrixXd &data)
    : primaries_(std::make_shared<Primaries>(Eigen::MatrixXd(data), std::vector<std::string>({"X", "Y", "Z"}))) {
  if (data.rows() != 3) {
    throw std::invalid_argument("The number of rows of the matrix to construct tristimulus matrix should be 3.");
  }
}
const Eigen::VectorXd Tristimulus::X() const {
  return primaries_->primary("X");
}

const Eigen::VectorXd Tristimulus::Y() const {
  return primaries_->primary("Y");
}

const Eigen::VectorXd Tristimulus::Z() const {
  return primaries_->primary("Z");
}

}