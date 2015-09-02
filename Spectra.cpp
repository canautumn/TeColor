//
// Created by Can on 9/1/15.
//

#include "Spectra.h"

namespace tecolor {

using Eigen::MatrixXd;
using Eigen::VectorXd;

Spectra::Spectra(Index num_wavelengths, Index num_samples)
    : data_(new MatrixXd(num_wavelengths, num_samples)),
      wavelengths_(new VectorXd(num_wavelengths)) { }

Spectra::Spectra(std::shared_ptr<Eigen::MatrixXd> data,
                 std::shared_ptr<Eigen::VectorXd> wavelengths)
    : data_(new MatrixXd(*data)),
      wavelengths_(new VectorXd(*wavelengths)) {
  if (data_->rows() != wavelengths_->rows()) {
    throw std::invalid_argument("Data and wavelengths should have same number of rows.");
  }
  if (wavelengths_->cols() != 1) {
    throw std::invalid_argument("Wavelengths should have exact one column.");
  }
}


Spectra::Spectra(const Eigen::MatrixXd &data,
                 const Eigen::VectorXd &wavelengths)
    : data_(new MatrixXd(data)),
      wavelengths_(new VectorXd(wavelengths)) {
  if (data_->rows() != wavelengths_->rows()) {
    throw std::invalid_argument("Data and wavelengths should have same number of rows.");
  }
  if (wavelengths_->cols() != 1) {
    throw std::invalid_argument("Wavelengths should have exact one column.");
  }
}

Spectra::Spectra(const Spectra &spectra)
    : data_(new MatrixXd(spectra.spectra())),
      wavelengths_(new VectorXd(spectra.wavelengths())) { }


const Spectra &Spectra::operator=(const Spectra &spectra) {
  data_.reset(new MatrixXd(spectra.spectra()));
  wavelengths_.reset(new VectorXd(spectra.wavelengths()));
  return *this;
}


std::shared_ptr<Eigen::MatrixXd> Spectra::get_data_ptr() {
  return data_;
}


std::shared_ptr<Eigen::VectorXd> Spectra::get_wavelengths_ptr() {
  return wavelengths_;
}


const Eigen::MatrixXd &Spectra::spectra() const {
  return *data_;
}


const Eigen::VectorXd &Spectra::wavelengths() const {
  return *wavelengths_;
}

Eigen::MatrixXd &Spectra::spectra() {
  return *data_;
}

Eigen::VectorXd &Spectra::wavelengths() {
  return *wavelengths_;
}

Spectra::Spectra() : data_(new MatrixXd()), wavelengths_(new VectorXd()) { }

const Eigen::VectorXd Spectra::spectrum_at(Index index) const {
  return data_->col(index);
}

} // namespace tecolor
