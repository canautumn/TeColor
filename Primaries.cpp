//
// Created by Can on 9/2/15.
//

#include "Primaries.h"

namespace tecolor {

using Eigen::MatrixXd;

Primaries::Primaries() : data_(new MatrixXd()), primary_names_() { }

Primaries::Primaries(Index num_primaries,
                     Index num_samples,
                     std::vector<std::string> primary_names)
    : data_(new MatrixXd(num_primaries, num_samples)),
      primary_names_(primary_names) {
  if (primary_names.size() != num_primaries) {
    throw std::invalid_argument("The number of primaries provided should be equal to the number of primary names.");
  }
}

Primaries::Primaries(std::shared_ptr<Eigen::MatrixXd> data,
                     std::vector<std::string> primary_names)
    : data_(new MatrixXd(*data)),
      primary_names_(primary_names) { }

Primaries::Primaries(const Eigen::MatrixXd &data,
                     const std::vector<std::string> primary_names)
    : data_(new MatrixXd(data)),
      primary_names_(primary_names) { }

Primaries::Primaries(const Primaries &primaries)
    : data_(new MatrixXd(primaries.data())),
      primary_names_(primaries.primary_names()) { }

const Primaries &Primaries::operator=(const Primaries &primaries) {
  data_.reset(new MatrixXd(primaries.data()));
  primary_names_ = primaries.primary_names();
  return *this;
}

std::shared_ptr<Eigen::MatrixXd> Primaries::get_data_ptr() {
  return data_;
}

const Eigen::MatrixXd &Primaries::data() const {
  return *data_;
}


const std::vector<std::string> &Primaries::primary_names() const {
  return primary_names_;
}

Eigen::MatrixXd &Primaries::data() {
  return *data_;
}

std::vector<std::string> &Primaries::primary_names() {
  return primary_names_;
}

}