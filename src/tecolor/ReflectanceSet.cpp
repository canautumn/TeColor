//
// Created by Can on 9/2/15.
//

#include <TeColor/ReflectanceSet.h>
#include <TeColor/builtin_database.h>
#include <TeColor/EigenUtils.h>

namespace tecolor {

using namespace detail;
using Eigen::MatrixXd;
using Eigen::VectorXd;

ReflectanceSet::ReflectanceSet(tecolor::BuiltInReflectanceSetName refl)
    : spectra_(new Spectra()){

  auto num_samples = &REFL_SET_COLORCHECKER_NUM_SAMPLES;
  auto num_wavelengths = &REFL_SET_COLORCHECKER_NUM_WAVELENGTHS;
  auto wavelengths = &REFL_SET_COLORCHECKER_WAVELENGTHS;
  auto data = &REFL_SET_COLORCHECKER_SPECTRA;

  switch (refl) {
    case REFLECTANCE_COLORCHECKER:
      num_wavelengths = &REFL_SET_COLORCHECKER_NUM_WAVELENGTHS;
      num_samples = &REFL_SET_COLORCHECKER_NUM_SAMPLES;
      wavelengths = &REFL_SET_COLORCHECKER_WAVELENGTHS;
      data = &REFL_SET_COLORCHECKER_SPECTRA;
      break;
  }

  EigenMatrixTransposeInitializer(spectra_->spectra(), *num_wavelengths, *num_samples, data);
  EigenVectorInitializer(spectra_->wavelengths(), *num_wavelengths, wavelengths);
}

const Eigen::MatrixXd &ReflectanceSet::m() const {
  return spectra_->m();
}

const Eigen::VectorXd &ReflectanceSet::wavelengths() const {
  return spectra_->wavelengths();
}

const Eigen::VectorXd ReflectanceSet::spectrum_at(Index index) const {
  return spectra_->spectrum_at(index);
}

} // namespace tecolor
