#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

long Fraction::GetIntegerPart() const { return integerPart; }
unsigned short Fraction::GetFloatPart() const { return floatPart; }

void Fraction::SetIntegerPart(long integerPart) { this->integerPart = integerPart; }
void Fraction::SetFloatPart(unsigned short floatPart) {
  if (floatPart >= 1000) {
    cout << "Error: float part must be less than 1000!" << endl;
    return;
  }
  this->floatPart = floatPart;
}

void Fraction::Init() {
  this->Read();
  this->Display();
}

void Fraction::Read() {
 cout << "Enter the integer part: ";
  cin >> integerPart;
  SetIntegerPart(integerPart);

  string floatPartStr;
  cout << "Enter the float part (000-999): ";
  cin >> floatPartStr;

  while (floatPartStr.length() != 3 || !isdigit(floatPartStr[0]) || !isdigit(floatPartStr[1]) || !isdigit(floatPartStr[2]) || stoi(floatPartStr) >= 1000) {
    cout << "Invalid input! Enter float part (000-999): ";
    cin >> floatPartStr;
  }

  SetFloatPart(stoi(floatPartStr));
}

std::string Fraction::toString() const {
  return std::to_string(integerPart) + "." + std::to_string(floatPart);
}

void Fraction::Display() const {
  cout << "The fraction is: " << toString() << endl;
}

Fraction Fraction::Add(Fraction r) {
  Fraction t;
  t.integerPart = GetIntegerPart() + r.GetIntegerPart();
  t.floatPart = GetFloatPart() + r.GetFloatPart();

  if (t.floatPart >= 1000) {
    t.integerPart++;
    t.floatPart -= 1000;
  }

  return t;
}

Fraction Fraction::Multiply(Fraction r) {
  Fraction t;

  long long part1 = GetIntegerPart() * r.GetIntegerPart();
  long long part2 = GetIntegerPart() * r.GetFloatPart();
  long long part3 = GetFloatPart() * r.GetIntegerPart();
  long long part4 = GetFloatPart() * r.GetFloatPart();

  long long total = part1 * 1000000 + part2 * 1000 + part3 * 1000 + part4;

  t.integerPart = total / 1000000;
  t.floatPart = (total % 1000000) / 1000;

  if ((total % 1000) >= 500) {
    t.floatPart++;
    if (t.floatPart >= 1000) {
      t.integerPart++;
      t.floatPart -= 1000;
    }
  }

  return t;
}