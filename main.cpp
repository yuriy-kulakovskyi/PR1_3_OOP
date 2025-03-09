#include <iostream>
#include "./classes/Fraction.h"

using namespace std;


int main() {
  Fraction a, b;

  a.Init();
  b.Init();

  Fraction sum = a.Add(b);
  Fraction product = a.Multiply(b);

cout << "Sum: " << sum.toString() << endl;
cout << "Product: " << product.toString() << endl;

  return 0;
}
