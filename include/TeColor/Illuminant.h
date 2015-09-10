//
// Created by Can on 9/2/15.
//

#ifndef TECOLOR_ILLUMINANT_H
#define TECOLOR_ILLUMINANT_H


#include "Spectra.h"
#include "EigenUtils.h"
#include "builtin_database.h"
namespace tecolor {

enum IlluminantName {
  ILLUMINANT_D50,
  ILLUMINANT_D65,
  ILLUMINANT_E
};

class Illuminant {
  std::shared_ptr<Spectra> spectra_;
 public:
  Illuminant(IlluminantName ill);
  Illuminant(IlluminantName ill, std::string database_path);
  const Eigen::VectorXd spectrum() const;
  const Eigen::VectorXd& wavelengths() const;
};

} // namespace tecolor

#endif //TECOLOR_ILLUMINANT_H
