#ifndef __VECTOR_TEST_HPP__
#define __VECTOR_TEST_HPP__

#include "gtest/gtest.h"
#include "VectorContainer.hpp"
#include "bubble_sort.hpp"
#include "selection_sort.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Add.hpp"
#include "sub.hpp"

TEST(VectorContainer, SwapTest){
	Op* seven = new Op(7);
	VectorContainer* test_container = new VectorContainer();

	test_container->add_element(seven);

	ASSERT_EQ(test_container->size(), 1);
	EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

TEST(VectorContainer, PrintTest){
	Op* seven = new Op(7);
	Op* two = new Op(2);
	Add* Tree = new Add(seven, two);

	VectorContainer* test = new VectorContainer();
	test->add_element(Tree);
	test->print();
}	

TEST(SortTestSet, SelectionSortTest){
	Op* seven = new Op(7);
	Op* four = new Op(4);
	Mult* TreeA = new Mult(seven, four);

	Op* three = new Op(3);
	Op* two = new Op(2);
	Add* TreeB = new Add(three, two);

	Op* ten = new Op(10);
	Op* six = new Op(6);
	Sub* TreeC = new Sub(ten, six);
	
	VectorContainer* container = new VectorContainer();
	container->add_element(TreeA);
	container->add_element(TreeB);
	container->add_element(TreeC);

	ASSERT_EQ(container->size(), 3);
	EXPECT_EQ(container->at(0)->evaluate(), 28);
	EXPECT_EQ(container->at(1)->evaluate(), 5);
	EXPECT_EQ(container->at(2)->evaluate(), 4);

	container->set_sort_function(new SelectionSort());
	container->sort();

	ASSERT_EQ(container->size(), 3);
	EXPECT_EQ(container->at(0)->evaluate(), 4);
	EXPECT_EQ(container->at(1)->evaluate(), 5);
	EXPECT_EQ(container->at(2)->evaluate(), 28);

}

TEST(SortTestSet, BubbleSortTest){
	Op* seven = new Op(7);
	Op* four = new Op(4);
	Mult* TreeA = new Mult(seven, four);

	Op* three = new Op(3);
	Op* two = new Op(2);
	Add* TreeB = new Add(three, two);
	
	Op* ten = new Op(10);
	Op* six = new Op(6);
	Sub* TreeC = new Sub(ten, six);

	VectorContainer* container = new VectorContainer(new BubbleSort());
	container->add_element(TreeA);
	container->add_element(TreeB);
	container->add_element(TreeC);
	
	ASSERT_EQ(container->size(),3);
	EXPECT_EQ(container->at(0)->evaluate(),28);
	EXPECT_EQ(container->at(1)->evaluate(),5);
	EXPECT_EQ(container->at(2)->evaluate(),4);

	//container->set_sort_function(new BubbleSort());
	container->sort();

	ASSERT_EQ(container->size(),3);
	EXPECT_EQ(container->at(0)->evaluate(), 4);
	EXPECT_EQ(container->at(1)->evaluate(),5);
	EXPECT_EQ(container->at(2)->evaluate(),28);
}


#endif
