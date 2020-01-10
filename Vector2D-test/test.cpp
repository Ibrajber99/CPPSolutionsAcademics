#include "gtest/gtest.h"
#include "Vector2D.h"




TEST(Vector2DTestSuite, constructorTest01) {
	Vector2D v1(1, 1);

	

	std::string expectedResult = "(1,1)";
	std::string result = v1.toString();

	EXPECT_EQ(expectedResult, result);
	
}

TEST(Vector2DTestSuite, equalsTest02) {
	Vector2D v1(1, 1);
	Vector2D v2(3, 1);

	std::string expectedResult = "(1,1)";
	std::string result = v1.toString();

	EXPECT_FALSE(v1 ==  v2);

}

TEST(Vector2DTestSuite, biggerThanTest02) {
	Vector2D v1(1, 1);
	Vector2D v2(3, 1);

	EXPECT_FALSE(v1 > v2);

}

TEST(Vector2DTestSuite, lessThanTest02) {
	Vector2D v1(1, 1);
	Vector2D v2(3, 1);

	EXPECT_TRUE(v1 < v2);

}
TEST(Vector2DTestSuite, notEqualThanTest02) {
	Vector2D v1(1, 1);
	Vector2D v2(3, 1);

	EXPECT_TRUE(v1 != v2);

}

