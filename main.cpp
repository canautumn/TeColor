#include <iostream>
#include "SpectralKit.h"

using namespace std;
using namespace tecolor;

int main() {
  auto cmf19312d = ColorMatchingFunction(Observer1931At2Deg);
  cout << "Color Matching Function of Observer 1931 at 2 Degree:" << endl;
  cout << cmf19312d.cmf() << endl;
  auto d65 = Illuminant(ILLUMINANT_D65);
  cout << "CIE Illuminant D65 Spectrum:" << endl;
  cout << d65.spectrum() << endl;
  auto cc = ReflectanceSet(REFLECTANCE_COLORCHECKER);
  auto xyz = Refl2XYZ(d65, cmf19312d, cc);
  cout << "Calculated ColorChecker Tristimulus Values:" << endl;
  cout << xyz.XYZ() << endl;
  cout << "CIE Illuminant D65 Yxy:" << endl;
  auto Yxy = Rad2Yxy(d65, cmf19312d);
  cout << Yxy.data() << endl;
  cout << "CIE Illuminant D65 xy (chromaticity coordinates):" << endl;
  auto xy = Rad2xy(d65, cmf19312d);
  cout << xy.data() << endl;
  cout << "CIELAB of ColorChecker under D65:" << endl;
  auto lab = XYZ2Lab(xy, xyz);
  cout << lab.Lab() << endl;
  return 0;
}