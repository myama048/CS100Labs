#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "Mult.hpp"

TEST(MultTest, MultEvaluateNonZero) {
    Op* a = new Op(10);
    Op* b = new Op(2);
    Mult* test = new Mult(a,b);
    EXPECT_NEAR(test->evaluate(), 20, 0.001);

}

TEST(MultTest, MultEvaluateDouble) {
    Op* a = new Op(5.5);
    Op* b = new Op(2.5);
    Mult* test = new Mult(a,b);
    EXPECT_NEAR(test->evaluate(), 13.75, 0.001);   
}

TEST(MultTest, MultEvaluateMultZero) {
    Op* a = new Op(5.5);
    Op* b = new Op(0);
    Mult* test = new Mult(a,b);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultEvaluateMultNegative) {
    Op* a = new Op(5);
    Op* b = new Op(-10);
    Mult* test = new Mult(a,b);
    EXPECT_NEAR(test->evaluate(), -50, 0.001);
}

TEST(MultTest, MultEvaluateMultTwoNegative) {
    Op* a = new Op(-5);
    Op* b = new Op(-10);
    Mult* test = new Mult(a,b);
    EXPECT_NEAR(test->evaluate(), 50, 0.001);
}

TEST(MultTest, MultStringifyNonZero) {
    Op* a = new Op(5);
    Op* b = new Op(10);
    Mult* test = new Mult(a,b);
    EXPECT_EQ(test->stringify(), "(5.000000 * 10.000000)");
}

TEST(MultTest, MultStringifyDouble) {
    Op* a = new Op(5.234);
    Op* b = new Op(10.123);
    Mult* test = new Mult(a,b);
    EXPECT_EQ(test->stringify(), "(5.234000 * 10.123000)");
}

TEST(MultTest, MultStringifyNegatives) {
    Op* a = new Op(-5);
    Op* b = new Op(-10);
    Mult* test = new Mult(a,b);
    EXPECT_EQ(test->stringify(), "(-5.000000 * -10.000000)");
}



#endif
