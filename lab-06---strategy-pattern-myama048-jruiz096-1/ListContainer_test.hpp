#ifndef __LISTCONTAINER_TEST_HPP__
#define __LISTCONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include "ListContainer.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "sub.hpp"

TEST(ListContainerTestSet, AddElementTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);

    Mult* TreeA = new Mult(seven, four);

    Op* two = new Op(2);
    Op* three = new Op(3);

    Div* TreeB = new Div(two, three);

    ListContainer* test_container = new ListContainer();
    test_container->add_element(TreeA);
    test_container->add_element(TreeB);
    EXPECT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->stringify(), "(7.000000 * 4.000000)");
}

TEST(ListContainerTestSet, Check2ndElement) {
    Op* seven = new Op(7);
    Op* four = new Op(4);

    Mult* TreeA = new Mult(seven, four);

    Op* two = new Op(2);
    Op* three = new Op(3);

    Div* TreeB = new Div(two, three);

    ListContainer* test_container = new ListContainer();
    test_container->add_element(TreeA);
    test_container->add_element(TreeB);
    EXPECT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(1)->stringify(), "(2.000000 / 3.000000)");
}

TEST(ListContainerTestSet, SwapTestOne) {
    Op* seven = new Op(7);
    Op* four = new Op(4);

    Mult* TreeA = new Mult(seven, four);

    Op* two = new Op(2);
    Op* three = new Op(3);

    Div* TreeB = new Div(two, three);

    ListContainer* test_container = new ListContainer();
    test_container->add_element(TreeA);
    test_container->add_element(TreeB);

    test_container->swap(0,1);

    EXPECT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(1)->stringify(), "(7.000000 * 4.000000)");
}

TEST(ListContainerTestSet, SwapTestTwo) {
    Op* seven = new Op(7);
    Op* four = new Op(4);

    Mult* TreeA = new Mult(seven, four);

    Op* two = new Op(2);
    Op* three = new Op(3);

    Div* TreeB = new Div(two, three);

    Op* nine = new Op(9);
    Op* five = new Op(5);

    Sub* TreeC = new Sub(nine, five);


    ListContainer* test_container = new ListContainer();
    test_container->add_element(TreeA);
    test_container->add_element(TreeB);
    test_container->add_element(TreeC);

    test_container->swap(0,2);

    EXPECT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->stringify(), "(9.000000 - 5.000000)");
    EXPECT_EQ(test_container->at(1)->stringify(), "(2.000000 / 3.000000)");
    EXPECT_EQ(test_container->at(2)->stringify(), "(7.000000 * 4.000000)");
}

TEST(ListContainerTestSet, BubbleSort) {
    Op* seven = new Op(7);
    Op* four = new Op(4);

    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);

    Add* TreeB = new Add(two, three);

    Op* ten = new Op(10);
    Op* six = new Op(6);

    Sub* TreeC = new Sub(ten, six);


    ListContainer* test_container = new ListContainer();
    test_container->add_element(TreeA);
    test_container->add_element(TreeB);
    test_container->add_element(TreeC);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 28.000000);
    EXPECT_EQ(test_container->at(1)->evaluate(), 5.000000);
    EXPECT_EQ(test_container->at(2)->evaluate(), 4.000000);

    test_container->set_sort_function(new BubbleSort());
    test_container->sort();

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 4.000000);
    EXPECT_EQ(test_container->at(1)->evaluate(), 5.000000);
    EXPECT_EQ(test_container->at(2)->evaluate(), 28.000000);

}

TEST(ListContainerTestSet, SelectionSort) {
    Op* seven = new Op(7);
    Op* four = new Op(4);

    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);

    Add* TreeB = new Add(two, three);

    Op* ten = new Op(10);
    Op* six = new Op(6);

    Sub* TreeC = new Sub(ten, six);


    ListContainer* test_container = new ListContainer();
    test_container->add_element(TreeA);
    test_container->add_element(TreeB);
    test_container->add_element(TreeC);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 28.000000);
    EXPECT_EQ(test_container->at(1)->evaluate(), 5.000000);
    EXPECT_EQ(test_container->at(2)->evaluate(), 4.000000);

    test_container->set_sort_function(new SelectionSort());
    test_container->sort();

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 4.000000);
    EXPECT_EQ(test_container->at(1)->evaluate(), 5.000000);
    EXPECT_EQ(test_container->at(2)->evaluate(), 28.000000);

}


#endif
