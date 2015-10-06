//
// Created by Can on 9/29/15.
//

#include <TeColor/AppearanceKit.h>
#include <TeColor/EigenUtils.h>

namespace tecolor {

Primaries CIECAM02(const Tristimulus &sampleXYZ,
                   const Tristimulus &illXYZ,
                   const Value La,
                   const Value Yb,
                   const Value F,
                   const Value c,
                   const Value Nc) {

  // White point luminance
  if (illXYZ.m().cols() != 1) {
    throw std::invalid_argument("XYZ2Lab only takes one sample of illuminant XYZ.");
  }
  kValue Yw = illXYZ.Y()[0];

  // Viewing condition parameters
  kValue kQuartic = pow(1 / (5 * La + 1), 4);
  kValue Fl = 0.2 * kQuartic * (5 * La) + 0.1 * pow((1 - kQuartic), 2) * pow(5 * La, 1.0 / 3.0);
  kValue n = Yb / Yw;
  kValue Ncb = 0.725 * pow(1 / n, 0.2);
  kValue Nbb = Ncb;
  kValue z = 1.48 + sqrt(n);

  // Incorporate illuminant (white point) into the tristimulus m matrix to simplify code
  Mat XYZMat(3, sampleXYZ.m().cols() + 1);
  XYZMat << sampleXYZ.m(), illXYZ.m();

  // Prepare const matrices
  kMat CIECAT02Mat = EigenMatrixRowMajorInitializer(CIECAT02_M, 3);
  kMat CIECAT02_INVMat = EigenMatrixRowMajorInitializer(CIECAT02_M_INV, 3);
  kMat MHMat = EigenMatrixRowMajorInitializer(CIECAM02_MH, 3);

  // Chromatic adaptation
  kMat RGBMat = CIECAT02Mat * XYZMat;
  kValue D = F * (1 - (1 / 3.6) * std::exp((-La - 42) / 92));
  // RGBMat.rightCols<1>() is the white point RGB
  kMat RGBcMat = ((Yw * D) / RGBMat.rightCols<1>().array() + 1 - D).matrix().asDiagonal() * RGBMat;
  kMat RGBpMat = MHMat * CIECAT02_INVMat * RGBcMat;

  // Nonlinear response compression
  kMat RGBpMatSign = RGBpMat.unaryExpr([](double x) { return (x > 0) - (x < 0); });
  kMat RGBpMatAbs = RGBpMat.unaryExpr(std::function<double(double)>(std::abs<double>));
  kMat RGBpaMatIntermediate = (Fl * RGBpMatAbs.array() / 100).pow(0.42).matrix();
  kMat RGBpaMat = (RGBpMatSign.array() * (400 * RGBpaMatIntermediate.array())
      / (27.13 + RGBpaMatIntermediate.array()) + 0.1).matrix();
  // Sepatate sample and white point m
  kRVec RGBpawVec = RGBpaMat.rightCols<1>();
  kMat RGBpacMat = RGBpaMat.leftCols(RGBpaMat.cols() - 1);

  kRVec a = RGBpacMat.row(0).array() - 12 * RGBpacMat.row(1).array() / 11 + RGBpacMat.row(2).array() / 11;
  kRVec b = (RGBpacMat.row(0).array() + RGBpacMat.row(1).array() - 2 * RGBpacMat.row(2).array()) / 9;
  kRVec hAtan2 = b.binaryExpr(a, [](double x, double y) { return std::atan2(x, y); });
  kRVec h = hAtan2.unaryExpr([](double x) { return x < 0 ? x * 180.0 / M_PI + 360 : x * 180.0 / M_PI; });

  // Eccentricity factor
  kRVec et = (cos(h.array() * M_PI / 180.0 + 2) + 3.8) / 4;

  // Achromatic response
  kRVec A = (2 * RGBpacMat.row(0).array() + RGBpacMat.row(1).array() + RGBpacMat.row(2).array() / 20 - 0.305) * Nbb;
  kValue Aw = (2 * RGBpawVec(0) + RGBpawVec(1) + RGBpawVec(2) / 20 - 0.305) * Nbb;

  // Lightness
  kRVec J = 100 * pow(A.array() / Aw, c * z);

  // Brightness
  kRVec Q = (4 / c) * sqrt(J.array() / 100) * (Aw + 4) * pow(Fl, 0.25);

  // Chroma
  kRVec t = (50000.0 / 13.0 * Nc * Ncb) * et.array() * pow(pow(a.array(), 2) + pow(b.array(), 2), 0.5)
      / (RGBpacMat.row(0).array() + RGBpacMat.row(1).array() + 21.0 * RGBpacMat.row(2).array() / 20.0);
  kRVec C = pow(t.array(), 0.9) * sqrt(J.array() / 100.0) * pow(1.64 - pow(0.29, n), 0.73);

  // Colorfulness
  kRVec M = C * pow(Fl, 0.25);

  // Saturation
  kRVec s = 100.0 * sqrt(M.array() / Q.array());

  // Cartesian coordinates
  kRVec ac = C.array() * cos(h.array() / 180.0 * M_PI);
  kRVec bc = C.array() * sin(h.array() / 180.0 * M_PI);
  std::shared_ptr<Mat> resultMatPtr(new Mat(8, sampleXYZ.m().cols()));
  *resultMatPtr << J, C, h, ac, bc, Q, M, s;
  Primaries result(resultMatPtr, std::vector<std::string>({"J", "C", "h", "ac", "bc", "Q", "M", "s"}));
  return result;
}

} // namespace tecolor