//
// Created by Can on 9/2/15.
//

#ifndef TECOLOR_PRIMARIES_H
#define TECOLOR_PRIMARIES_H

#include <Eigen/Dense>
#include <vector>
#include <unordered_map>
#include "typedefs.h"

namespace tecolor {


class Primaries {
  std::shared_ptr<Eigen::MatrixXd> data_;
  std::vector<std::string> primary_names_;
  std::unordered_map<std::string, Index> primary_indexes_;
  void init_primary_indexes();
 public:
  Primaries();
  Primaries(Index num_primaries,
            Index num_samples,
            std::vector<std::string> primary_names);
  Primaries(std::shared_ptr<Eigen::MatrixXd> data,
            std::vector<std::string> primary_names);
  Primaries(const Eigen::MatrixXd &data,
            const std::vector<std::string> primary_names);
  Primaries(const Primaries &);
  const Primaries &operator=(const Primaries &primaries);
  std::shared_ptr<Eigen::MatrixXd> get_data_ptr();
  const Eigen::MatrixXd &m() const;
  const std::vector<std::string> &primary_names() const;
  Eigen::MatrixXd &data();
  std::vector<std::string> &primary_names();
  const Eigen::VectorXd primary(std::string primary_name) const;
};

} // namespace tecolor

#endif //TECOLOR_PRIMARIES_H
