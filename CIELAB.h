//
// Created by Can on 9/9/15.
//

#ifndef TECOLOR_CIELAB_H
#define TECOLOR_CIELAB_H

#include "Primaries.h"

namespace tecolor {

class CIELAB {
  std::shared_ptr<Primaries> primaries_;
 public:
  CIELAB();
  CIELAB(Index num_samples);
  CIELAB(const CIELAB &);
  CIELAB(const Eigen::MatrixXd &data);
  const CIELAB &operator=(const CIELAB &);
  const Eigen::MatrixXd &Lab() const;
  const Eigen::VectorXd L() const;
  const Eigen::VectorXd a() const;
  const Eigen::VectorXd b() const;
};

} // namespace tecolor

#endif //TECOLOR_CIELAB_H
