#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>

class Fraction {
private:
  long integerPart;
  unsigned short floatPart;

public:
  long GetIntegerPart() const;
  unsigned short GetFloatPart() const;

  void SetIntegerPart(long integerPart);
  void SetFloatPart(unsigned short floatPart);

  void Init();
  void Read();
  std::string toString() const;
  void Display() const;

  Fraction Add(Fraction r);
  Fraction Multiply(Fraction r);
};

#endif // FRACTION_H