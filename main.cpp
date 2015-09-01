#include <iostream>
#include "ColorMatchingFunction.h"

using namespace std;
int main() {
  cout << "Hello, World!" << endl;
  auto cmf19312d = tecolor::ColorMatchingFunction(tecolor::Observer1931At2Deg);
  cout << cmf19312d.cmf();
  return 0;
}