#include <gtest/gtest.h>
#include "../classes/Fraction.h"

TEST(Test_Adding, Fraction_test) {
  Fraction a, b, sum;
  a.SetIntegerPart(2);
  a.SetFloatPart(500);
  b.SetIntegerPart(2);
  b.SetFloatPart(000);
  sum = a.Add(b);
  EXPECT_EQ(sum.GetIntegerPart(), 4);
}

TEST(Test_Multiplying, Fraction_test) {
  Fraction a, b, product;
  a.SetIntegerPart(2);
  a.SetFloatPart(500);
  b.SetIntegerPart(2);
  b.SetFloatPart(000);
  product = a.Multiply(b);
  EXPECT_EQ(product.GetIntegerPart(), 5);
}