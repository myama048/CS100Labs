#include "gtest/gtest.h"

#include "rand_test.hpp"
#include "pow_test.hpp"
#include "op_test.hpp"
#include "mult_test.hpp"
#include "div_test.hpp"
#include "add_tests.hpp"
#include "sub_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
