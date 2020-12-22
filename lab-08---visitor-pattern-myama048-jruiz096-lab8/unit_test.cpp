#include "gtest/gtest.h"
/*
#include "rand_test.hpp"
#include "pow_test.hpp"
#include "op_test.hpp"
#include "mult_test.hpp"
#include "div_test.hpp"
#include "add_tests.hpp"
#include "sub_test.hpp"
*/
//#include "sort.hpp"
//#include "selection_sort.hpp"
//#include "bubble_sort.hpp"
//#include "VectorContainer_test.hpp"
//#include "ListContainer_test.hpp"
#include "visit_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
