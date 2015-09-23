//
// Created by Can on 9/1/15.
//

#ifndef TECOLOR_SPECTRA_H
#define TECOLOR_SPECTRA_H

#include <Eigen/Dense>
#include "SpectraMatrix.h"
#include "typedefs.h"

namespace tecolor {

class Spectra: public SpectraMatrix {
  std::shared_ptr<Eigen::MatrixXd> data_;
  std::shared_ptr<Eigen::VectorXd> wavelengths_;
 public:
  Spectra();
  Spectra(Index num_wavelengths, Index num_samples);
  Spectra(std::shared_ptr<Eigen::MatrixXd> data,
          std::shared_ptr<Eigen::VectorXd> wavelengths);
  Spectra(const Eigen::MatrixXd &data,
          const Eigen::VectorXd &wavelengths);
  Spectra(const Spectra &);
  const Spectra &operator=(const Spectra &spectra);
  std::shared_ptr<Eigen::MatrixXd> get_data_ptr();
  std::shared_ptr<Eigen::VectorXd> get_wavelengths_ptr();
  const Eigen::MatrixXd &m() const;
  const Eigen::VectorXd spectrum_at(Index index) const;
  const Eigen::VectorXd &wavelengths() const;
  Eigen::MatrixXd &spectra();
  Eigen::VectorXd &wavelengths();
};

} // namespace tecolor

#endif //TECOLOR_SPECTRA_H
