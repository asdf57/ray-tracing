#include <gtest/gtest.h>
#include <cmath>
#include "../src/vec3.h"

TEST(Vec3Test, DefaultConstructor) {
  vec3 v;
  EXPECT_EQ(v.v0(), 0.0);
  EXPECT_EQ(v.v1(), 0.0);
  EXPECT_EQ(v.v2(), 0.0);
}

TEST(Vec3Test, ParameterizedConstructor) {
  vec3 v(1.0, 2.0, 3.0);
  EXPECT_EQ(v.v0(), 1.0);
  EXPECT_EQ(v.v1(), 2.0);
  EXPECT_EQ(v.v2(), 3.0);
}

TEST(Vec3Test, UnaryMinusOperator) {
  vec3 v(1.0, 2.0, 3.0);
  vec3 neg_v = -v;
  EXPECT_EQ(neg_v.v0(), -1.0);
  EXPECT_EQ(neg_v.v1(), -2.0);
  EXPECT_EQ(neg_v.v2(), -3.0);
}

TEST(Vec3Test, SubscriptOperator) {
  vec3 v(1.0, 2.0, 3.0);
  EXPECT_EQ(v[0], 1.0);
  EXPECT_EQ(v[1], 2.0);
  EXPECT_EQ(v[2], 3.0);
}

TEST(Vec3Test, AdditionOperator) {
  vec3 v1(1.0, 2.0, 3.0);
  vec3 v2(4.0, 5.0, 6.0);
  vec3 result = v1 + v2;
  EXPECT_EQ(result.v0(), 5.0);
  EXPECT_EQ(result.v1(), 7.0);
  EXPECT_EQ(result.v2(), 9.0);
}

TEST(Vec3Test, SubtractionOperator) {
  vec3 v1(1.0, 2.0, 3.0);
  vec3 v2(4.0, 5.0, 6.0);
  vec3 result = v1 - v2;
  EXPECT_EQ(result.v0(), -3.0);
  EXPECT_EQ(result.v1(), -3.0);
  EXPECT_EQ(result.v2(), -3.0);
}

TEST(Vec3Test, PlusEqualOperator) {
  vec3 v1(1.0, 2.0, 3.0);
  v1 += v1;
  EXPECT_EQ(v1.v0(), 2.0);
  EXPECT_EQ(v1.v1(), 4.0);
  EXPECT_EQ(v1.v2(), 6.0);
}

TEST(Vec3Test, TimesEqualOperator) {
  vec3 v1(1.0, 2.0, 3.0);
  v1 *= v1;
  EXPECT_EQ(v1.v0(), 1.0);
  EXPECT_EQ(v1.v1(), 4.0);
  EXPECT_EQ(v1.v2(), 9.0);
}

TEST(Vec3Test, DivideEqualOperator) {
  vec3 v1(1.0, 2.0, 3.0);
  v1 /= v1;
  EXPECT_EQ(v1.v0(), 1.0);
  EXPECT_EQ(v1.v1(), 1.0);
  EXPECT_EQ(v1.v2(), 1.0);
}

TEST(Vec3Test, VectorLength) {
  vec3 v1(1.0, 2.0, 3.0);
  double length = v1.length();
  EXPECT_DOUBLE_EQ(length, sqrt(14));
}

TEST(Vec3Test, LengthSquared) {
  vec3 v1(1.0, 2.0, 3.0);
  double length_squared = 17;
  EXPECT_DOUBLE_EQ(length_squared, 17);
}

TEST(Vec3Test, UnitVectorXAxis) {
  vec3 v1(1,0,0);
  vec3 result = unit_vector(v1);
  EXPECT_EQ(result.v0(), 1);
  EXPECT_EQ(result.v1(), 0);
  EXPECT_EQ(result.v2(), 0);
}

TEST(Vec3Test, UnitVectorYAxis) {
  vec3 v1(0,1,0);
  vec3 result = unit_vector(v1);
  EXPECT_EQ(result.v0(), 0);
  EXPECT_EQ(result.v1(), 1);
  EXPECT_EQ(result.v2(), 0);
}

TEST(Vec3Test, UnitVectorZAxis) {
  vec3 v1(0,0,1);
  vec3 result = unit_vector(v1);
  EXPECT_EQ(result.v0(), 0);
  EXPECT_EQ(result.v1(), 0);
  EXPECT_EQ(result.v2(), 1);
}

TEST(Vec3Test, UnitVector) {
  vec3 v1(2,3,4);
  double magnitude = sqrt(2*2 + 3*3 + 4*4);
  vec3 result = unit_vector(v1);
  EXPECT_DOUBLE_EQ(result.v0(), 2/magnitude);
  EXPECT_DOUBLE_EQ(result.v1(), 3/magnitude);
  EXPECT_DOUBLE_EQ(result.v2(), 4/magnitude);
}

TEST(Vec3Test, PlusOperator) {
  vec3 v1(1,2,3);
  vec3 v2(2,3,4);
  vec3 result = v1 + v2;
  EXPECT_DOUBLE_EQ(result.v0(), 3);
  EXPECT_DOUBLE_EQ(result.v1(), 5);
  EXPECT_DOUBLE_EQ(result.v2(), 7);
}

TEST(Vec3Test, MinusOperator) {
  vec3 v1(1,2,3);
  vec3 v2(2,3,4);
  vec3 result = v1 - v2;
  EXPECT_DOUBLE_EQ(result.v0(), -1);
  EXPECT_DOUBLE_EQ(result.v1(), -1);
  EXPECT_DOUBLE_EQ(result.v2(), -1);
}

TEST(Vec3Test, TimesOperatorVectorVector) {
  vec3 v1(1,2,3);
  vec3 v2(2,3,4);
  vec3 result = v1 * v2;
  EXPECT_DOUBLE_EQ(result.v0(), 2);
  EXPECT_DOUBLE_EQ(result.v1(), 6);
  EXPECT_DOUBLE_EQ(result.v2(), 12);
}

TEST(Vec3Test, TimesOperatorConstantVector) {
  vec3 v1(1,2,3);
  vec3 result = 5 * v1;
  EXPECT_DOUBLE_EQ(result.v0(), 5);
  EXPECT_DOUBLE_EQ(result.v1(), 10);
  EXPECT_DOUBLE_EQ(result.v2(), 15);
}

TEST(Vec3Test, TimesOperatorConstantVector2) {
  vec3 v1(1,2,3);
  vec3 result = (1.0/3.0) * v1;
  EXPECT_DOUBLE_EQ(result.v0(), 1.0/3.0);
  EXPECT_DOUBLE_EQ(result.v1(), 2.0/3.0);
  EXPECT_DOUBLE_EQ(result.v2(), 3.0/3.0);
}

TEST(Vec3Test, TimesOperatorVectorConstant) {
  vec3 v1(1,2,3);
  vec3 result = v1 * 5;
  EXPECT_DOUBLE_EQ(result.v0(), 5);
  EXPECT_DOUBLE_EQ(result.v1(), 10);
  EXPECT_DOUBLE_EQ(result.v2(), 15);
}

TEST(Vec3Test, DivideOperator) {
  vec3 v1(1,2,3);
  vec3 result = v1 / 3.0;
  EXPECT_DOUBLE_EQ(result.v0(), 1.0/3.0);
  EXPECT_DOUBLE_EQ(result.v1(), 2.0/3.0);
  EXPECT_DOUBLE_EQ(result.v2(), 3.0/3.0);
}

TEST(Vec3Test, DotProductOrthogonal) {
  vec3 v1(1,0,0);
  vec3 v2(0,1,0);
  double result = dot(v1,v2);
  EXPECT_DOUBLE_EQ(result, 0.0);
}

TEST(Vec3Test, DotProductSameDirection) {
  vec3 v1(1,0,0);
  vec3 v2(1,0,0);
  double result = dot(v1,v2);
  EXPECT_DOUBLE_EQ(result, 1.0);
}

TEST(Vec3Test, DotProductOppositeDirection) {
  vec3 v1(1,0,0);
  vec3 v2(-1,0,0);
  double result = dot(v1,v2);
  EXPECT_DOUBLE_EQ(result, -1.0);
}

TEST(Vec3Test, DotProductSameDirectionDifferentVectors) {
  vec3 v1(1,0,0);
  vec3 v2(3,0,0);
  double result = dot(v1,v2);
  EXPECT_DOUBLE_EQ(result, 3.0);
}

TEST(Vec3Test, DotProductNonUnitVectors) {
  vec3 v1(1.0, 2.0, 3.0);
  vec3 v2(4.0, 5.0, 6.0);
  double result = dot(v1,v2);
  EXPECT_DOUBLE_EQ(result, 1.0 * 4.0 + 2.0 * 5.0 + 3.0 * 6.0);
}

TEST(Vec3Test, CrossProductUnitVectors) {
  vec3 v1(1.0, 0.0, 0.0);
  vec3 v2(0.0, 1.0, 0.0);
  vec3 result = cross(v1, v2);
  EXPECT_DOUBLE_EQ(result.v0(), 0.0);
  EXPECT_DOUBLE_EQ(result.v1(), 0.0);
  EXPECT_DOUBLE_EQ(result.v2(), 1.0);
}

TEST(Vec3Test, CrossProductNonUnitVectors) {
  vec3 v1(1.0, 2.0, 3.0);
  vec3 v2(4.0, 5.0, 6.0);
  vec3 result = cross(v1, v2);
  EXPECT_DOUBLE_EQ(result.v0(), -3.0);
  EXPECT_DOUBLE_EQ(result.v1(), 6.0);
  EXPECT_DOUBLE_EQ(result.v2(), -3.0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
