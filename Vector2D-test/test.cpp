#include "gtest/gtest.h"
#include "Vector2D.h"



//ALL THe functionality that has been asked to be done are implemented
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

TEST(Vector2DTestSuite, lessThanTest01) {
	Vector2D v1(1, 1);
	Vector2D v2(3, 1);

	EXPECT_TRUE(v1 < v2);

}
TEST(Vector2DTestSuite, notEqualThanTest01) {
	Vector2D v1(1, 1);
	Vector2D v2(3, 1);

	EXPECT_TRUE(v1 != v2);

}
TEST(Vector2DTestSuite, LessThanOrEqualTest01) {
	Vector2D v1(1, 1);
	Vector2D v2(3, 1);

	EXPECT_TRUE(v1 <= v2);

}
TEST(Vector2DTestSuite, BiggerThanOrEqualTest01) {
	Vector2D v1(5, 8);
	Vector2D v2(3, 1);
	EXPECT_TRUE(v1 >= v2);

}
TEST(Vector2DTestSuite, BiggerThanOrEqualTest02 ) {
	Vector2D v1(5, 8);
	Vector2D v2(3, 1);
	EXPECT_FALSE(v1 <= v2);

}

TEST(Vector2DTestSuite, LessThanOrEqualTest02) {
	Vector2D v1(1, 1);
	Vector2D v2(3, 1);

	EXPECT_FALSE(v1 >= v2);

}