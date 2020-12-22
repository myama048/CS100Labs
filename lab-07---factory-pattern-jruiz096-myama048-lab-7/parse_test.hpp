#ifndef __PARSE_TEST_HPP__
#define __PARSE_TEST_HPP__

//#include "base.hpp"
//#include "op.hpp"
//#include "Add.hpp"
//#include "sub.hpp"
//#include "Mult.hpp"
//#include "pow.hpp"
//#include "Div.hpp"
#include "parse.hpp"
#include "gtest/gtest.h"
//#include "factory.hpp"

TEST(ParseTest, OneNum){
	char* test_val[2];
	test_val[0] = "./calculator";
	test_val[1] = "3";
	Factory* factory = new Parse();
	EXPECT_EQ("3.000000", factory->parse(test_val, 2)->stringify());
}

TEST(ParseTest, TwoDigitNum){
	char* test_val[2];
	test_val[0] = "./calculator";
	test_val[1] = "12";
	Factory* factory = new Parse();
	EXPECT_EQ("12.000000",factory-> parse(test_val, 2)->stringify());
}

TEST(ParseTest, Addition){
	char* test_val[4];
	test_val[0] = "./calculator";
	test_val[1] = "14";
	test_val[2] = "+";
	test_val[3] = "7";
	Factory* f = new Parse();
	EXPECT_EQ("(14.000000 + 7.000000)", f->parse(test_val, 4)->stringify());
}

TEST(InvalidTest, OneOperand) {
	char* test_val[3];
	test_val[0] = "./calculator";
	test_val[1] = "1";
	test_val[2] = "+";
	Factory* factory = new Parse();
	Base* test = factory->parse(test_val, 3);
	EXPECT_EQ(test, nullptr);	
}

TEST(InvalidTest, NoOperand) {
        char* test_val[3];
        test_val[0] = "./calculator";
        test_val[1] = "-";
        test_val[2] = "+";
        Factory* factory = new Parse();
        Base* test = factory->parse(test_val, 3);
        EXPECT_EQ(test, nullptr);
}

TEST(InvalidTest, TwoOperand) {
        char* test_val[5];
        test_val[0] = "./calculator";
        test_val[1] = "1";
        test_val[2] = "+";
	test_val[3] = "2";
	test_val[4] = "/";
        Factory* factory = new Parse();
        Base* test = factory->parse(test_val, 5);
        EXPECT_EQ(test, nullptr);
}

TEST(InvalidTest, MultAddSubDivMultInv) {
        char* test_val[10];
        test_val[0] = "./calculator";
        test_val[1] = "200";
        test_val[2] = "*";
        test_val[3] = "5";
        test_val[4] = "+";
        test_val[5] = "10";
        test_val[6] = "-";
        test_val[7] = "2";
        test_val[8] = "/";
        test_val[9] = "*";
        Factory* factory = new Parse();
        Base* test = factory->parse(test_val, 10);
        EXPECT_EQ(test, nullptr);
}

TEST(LongerEquation, AddDiv) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "1";
        test_val[2] = "+";
        test_val[3] = "2";
        test_val[4] = "/";
	test_val[5] = "3";
        Factory* factory = new Parse();
        Base* test = factory->parse(test_val, 6);
        EXPECT_EQ(test->evaluate(), 1);
}

TEST(LongerEquation, SubPow) {
        char* test_val[6];
        test_val[0] = "./calculator";
        test_val[1] = "10";
        test_val[2] = "-";
        test_val[3] = "2";
        test_val[4] = "**";
        test_val[5] = "3";
        Factory* factory = new Parse();
        Base* test = factory->parse(test_val, 6);
        EXPECT_EQ(test->evaluate(), 512);
}

TEST(LongerEquation, MultAddSubDiv) {
        char* test_val[10];
        test_val[0] = "./calculator";
        test_val[1] = "200";
        test_val[2] = "*";
        test_val[3] = "5";
        test_val[4] = "+";
        test_val[5] = "10";
	test_val[6] = "-";
        test_val[7] = "2";
	test_val[8] = "/";
	test_val[9] = "10";
        Factory* factory = new Parse();
        Base* test = factory->parse(test_val, 10);
        EXPECT_EQ(test->evaluate(), 100.8);
}

TEST(ParseTest, Subtraction){
	char* test[4];
	test[0] = "./calculator"; test[1] = "8"; test[2] = "-"; test[3] = "3";
	Factory* f = new Parse();
	EXPECT_EQ("(8.000000 - 3.000000)", f->parse(test, 4)->stringify());
}

TEST(ParseTest, SubNegative){
	char* test[4];
	test[0]="./calculator"; test[1]="4"; test[2]="-"; test[3]="7";
	Factory* f = new Parse();
	EXPECT_EQ(-3, f->parse(test,4)->evaluate());
}

TEST(ParseTest, Mult){
	char* test[4];
	test[0]="./calculator"; test[1]="3"; test[2]="\*"; test[3]="5";
	Factory* f = new Parse();
	EXPECT_EQ(15, f->parse(test,4)->evaluate());
}

TEST(ParseTest, Pow){
	char* test[4];
	test[0] = "./calculator"; test[1] =  "2"; test[2] =  "\*\*"; test[3]= "5";
	Factory* f = new Parse();
	EXPECT_EQ(32, f->parse(test,4)->evaluate());
}

TEST(ParseTest, Div){
	char* test[4];
	test[0] = "./calculator"; test[1] = "55"; test[2] = "/"; test[3] = "5";
	Factory* f = new Parse();
	EXPECT_EQ(11, f->parse(test,4)->evaluate());
}
#endif
