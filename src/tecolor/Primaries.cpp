//
// Created by Can on 9/2/15.
//

#include <TeColor/Primaries.h>

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
  init_primary_indexes();

}

Primaries::Primaries(std::shared_ptr<Eigen::MatrixXd> data,
                     std::vector<std::string> primary_names)
    : data_(new MatrixXd(*data)),
      primary_names_(primary_names) {
  init_primary_indexes();
}

Primaries::Primaries(const Eigen::MatrixXd &data,
                     const std::vector<std::string> primary_names)
    : data_(new MatrixXd(data)),
      primary_names_(primary_names) {
  init_primary_indexes();
}

Primaries::Primaries(const Primaries &primaries)
    : data_(new MatrixXd(primaries.m())),
      primary_names_(primaries.primary_names()) {
  init_primary_indexes();
}

const Primaries &Primaries::operator=(const Primaries &primaries) {
  data_.reset(new MatrixXd(primaries.m()));
  primary_names_ = primaries.primary_names();
  primary_indexes_ = primaries.primary_indexes_;

  return *this;
}

std::shared_ptr<Eigen::MatrixXd> Primaries::get_data_ptr() {
  return data_;
}

const Eigen::MatrixXd &Primaries::m() const {
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

const Eigen::VectorXd Primaries::primary(std::string primary_name) const {
  auto index_pair = primary_indexes_.find(primary_name);
  if (index_pair == primary_indexes_.end()) {
    throw std::invalid_argument("Wrong primary name.");
  }
  return data_->row(index_pair->second);
}

void Primaries::init_primary_indexes() {
  for (size_t i = 0; i < primary_names_.size(); ++i) {
    primary_indexes_.insert(make_pair(primary_names_[i], i));
  }
}

}