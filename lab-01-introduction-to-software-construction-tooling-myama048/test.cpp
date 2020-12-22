#include "c-echo.h"
#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld){
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
	EXPECT_EQ("hello world", echo(3, test_val));
}

TEST(EchoTest, EmptyStrig){
	char* test_val[1]; test_val[0] = "./c-echo";
	EXPECT_EQ("", echo(1, test_val));
}

//TEST1
TEST(EchoTest, OneLetterMissing){
	char* test_val[4]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world"; test_val[3] = "!";
	EXPECT_NE("hello world", echo(4, test_val));
}

//TEST2
TEST(EchoTest, GoodbyeWorld){
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "goodbye"; test_val[2] = "world";
	EXPECT_NE("hello world", echo(3, test_val));
}

//TEST3
TEST(EchoTest, NUMS_WRONG_ORDER){
	char* test_val[2]; test_val[1] = "./c-echo"; test_val[0] = "333";
	EXPECT_NE("333", echo(2, test_val));  
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
