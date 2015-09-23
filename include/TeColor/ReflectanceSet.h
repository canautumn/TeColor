//
// Created by Can on 9/2/15.
//

#ifndef TECOLOR_REFLECTANCESET_H
#define TECOLOR_REFLECTANCESET_H

#include "SpectraMatrix.h"
#include "Spectra.h"

namespace tecolor {

enum BuiltInReflectanceSetName {
  REFLECTANCE_COLORCHECKER,
};

class ReflectanceSet : public SpectraMatrix {
  std::shared_ptr<Spectra> spectra_;
 public:
  ReflectanceSet(BuiltInReflectanceSetName refl);
  ReflectanceSet(BuiltInReflectanceSetName refl, std::string database_path);
  const Eigen::MatrixXd& m() const;
  const Eigen::VectorXd spectrum_at(Index index) const;
  const Eigen::VectorXd& wavelengths() const;
  const Spectra& get_spectra_refl() const;
};

} // namespace tecolor

#endif //TECOLOR_REFLECTANCESET_H
