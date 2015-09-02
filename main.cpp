#include <iostream>
#include "ColorMatchingFunction.h"
#include "Illuminant.h"
#include "ReflectanceSet.h"
#include "SpectralKit.h"

using namespace std;
using namespace tecolor;

int main() {
  cout << "Hello, World!" << endl;
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
  return 0;
}