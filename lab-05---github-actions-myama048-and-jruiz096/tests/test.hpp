#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "../src/rectangle.cpp"
#include "gtest/gtest.h"

TEST(ConstructorTest, PosiPara){
	Rectangle* test = new Rectangle(3,4);
	EXPECT_EQ(test->get_width(), 3);
	EXPECT_EQ(test->get_height(), 4);
}

TEST(ConstructorTest, NegaPara){
	Rectangle* test = new Rectangle(-2,-3);
	EXPECT_EQ(test->get_width(), -2);
	EXPECT_EQ(test->get_height(), -3);
}

TEST(ConstructorTest, ZeroPara){
	Rectangle* test = new Rectangle(0,0);
	EXPECT_EQ(test->get_width(), 0);
	EXPECT_EQ(test->get_height(), 0);
}



 TEST(AreaTest, PosiPara){
  	Rectangle* test = new Rectangle(3,4);
  	EXPECT_EQ(test->area(), 12);
 }
 
 TEST(AreaTest, Area0){
  	Rectangle* test = new Rectangle(5, 0);
  	EXPECT_EQ(test->area(), 0);
 }

 TEST(AreaTest, AreaNeg){
 	Rectangle* test = new Rectangle(-2, 4);
 	EXPECT_EQ(test->area(), -8);
 }
 
 TEST(PerimeterTest, Positive){
  	Rectangle* test = new Rectangle(3,4);
  	EXPECT_EQ(test->perimeter(), 14);
 }

 TEST(PerimeterTest, PerimNeg){
 	Rectangle* test = new Rectangle(-3, 2);
 	EXPECT_EQ(test->perimeter(), -2);
 }
 
 TEST(PerimeterTest, Perim0){
  	Rectangle* test = new Rectangle(0,0);
 	EXPECT_EQ(test->perimeter(), 0);
}



#endif
