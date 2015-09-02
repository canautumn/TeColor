#include <iostream>
#include "ColorMatchingFunction.h"
#include "Illuminant.h"

using namespace std;
int main() {
  cout << "Hello, World!" << endl;
  auto cmf19312d = tecolor::ColorMatchingFunction(tecolor::Observer1931At2Deg);
  cout << cmf19312d.cmf();
  auto d65 = tecolor::Illuminant(tecolor::ILLUMINANT_D65);
  cout << d65.spectrum();

  return 0;
}