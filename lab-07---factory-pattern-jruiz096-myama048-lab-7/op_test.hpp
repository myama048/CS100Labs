#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_NEAR(test->evaluate(), 8, 0.001);
}

TEST(OpTest, OpEvaluateZero) {

    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateDecimal) {
    Op* test = new Op(1.23);
    EXPECT_EQ(test->evaluate(), 1.23);
}

TEST(OpTest, OpEvaluateNegative1) {
    Op* test = new Op(-1.23);
    EXPECT_EQ(test->evaluate(), -1.23);
}

TEST(OpTest, OpEvaluateDoube){
	Op* test = new Op(3.333);
	EXPECT_NEAR(test->evaluate(), 3.333, 0.000001);
}

TEST(OpTest, OpEvaluateNegative2){
	Op* test = new Op(-4.5);
	EXPECT_NEAR(test->evaluate(), -4.5, 0.0000000);
}

TEST(OpTest, OpStringNonZero1){
	Op* test = new Op(8);
	EXPECT_EQ(test->stringify(), "8.000000");
}

TEST(OpTest, OpStringZero) {
	Op* test = new Op(0);
	EXPECT_EQ(test->stringify(), "0.000000");
}

TEST(OpTest, OpStringNegative){
	Op* test = new Op(-4.500000);
	EXPECT_EQ(test->stringify(), "-4.500000");
}


#endif //__OP_TEST_HPP__
