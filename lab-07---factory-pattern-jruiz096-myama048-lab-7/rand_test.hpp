#ifndef __RAND_TEST_HPP___
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"
#include "rand.hpp"
#include <string>

TEST(RandTest, RandEvaluateLT100) {
	Rand* test = new Rand();
	EXPECT_LT(test->evaluate(), 100);
}

TEST(RandTest, RandEvaluateGT0) {
	Rand* test = new Rand();
	EXPECT_GT(test->evaluate(), 0);
}

TEST(RandTest, RandStringLT100) {
	Rand* test = new Rand();
	EXPECT_LT(stoi(test->stringify()), 100);
}

TEST(RandTest, RnadStringGT0) {
	Rand* test = new Rand();
	EXPECT_GT(stoi(test->stringify()), 0);
}


#endif
