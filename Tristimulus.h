//
// Created by Can on 9/2/15.
//

#ifndef TECOLOR_TRISTIMULUS_H
#define TECOLOR_TRISTIMULUS_H

#include "Primaries.h"

namespace tecolor {


class Tristimulus {
  std::shared_ptr<Primaries> primaries_;
 public:
  Tristimulus();
  Tristimulus(Index num_samples);
  Tristimulus(const Tristimulus&);
  Tristimulus(const Eigen::MatrixXd &data);
  const Tristimulus& operator=(const Tristimulus&);
  const Eigen::MatrixXd& XYZ() const;
};


}

#endif //TECOLOR_TRISTIMULUS_H
