#include <iostream>
#include <TeColor/TeColor>

using namespace std;
using namespace tecolor;

int main() {
  auto cmf19312d = ColorMatchingFunction(Observer1931At2Deg);
  cout << "Color Matching Function of Observer 1931 at 2 Degree:" << endl;
  cout << cmf19312d.m() << endl;
  auto d65 = Illuminant(ILLUMINANT_D65);

  cout << "CIE Illuminant D65 Spectrum:" << endl;
  cout << d65.m() << endl;
  auto cc = ReflectanceSet(REFLECTANCE_COLORCHECKER);
  auto xyz = Refl2XYZ(d65, cmf19312d, cc);

  cout << "Calculated ColorChecker Tristimulus Values:" << endl;
  cout << xyz.m() << endl;

  cout << "CIE Illuminant D65 Yxy:" << endl;
  auto Yxy = Rad2Yxy(d65, cmf19312d);
  cout << Yxy.m() << endl;

  cout << "CIE Illuminant D65 xy (chromaticity coordinates):" << endl;
  auto xy = Rad2xy(d65, cmf19312d);
  cout << xy.m() << endl;

  cout << "CIELAB of ColorChecker under D65:" << endl;
  auto lab = XYZ2Lab(xy, xyz);
  cout << lab.m() << endl;

  cout << "CIECAM02 of ColorChecker under certain condition:" << endl;
  auto cam = CIECAM02(xyz, Illuminantxy2XYZ(xy, 100.0), 0.2 * 1500 / M_PI, 0.43 * 100, 1.0, 0.69, 1.0);
  cout << cam.m() << endl;

  return 0;
}