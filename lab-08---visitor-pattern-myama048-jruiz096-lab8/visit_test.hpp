#ifndef __VISIT_TEST__
#define __VISIT_TEST__

#include "gtest/gtest.h"
#include "visitor.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include "container.hpp"
#include "Add.hpp"
#include "Div.hpp"
#include "Mult.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "op.hpp"

TEST(VisitTest, OpVisit) {
	Op* seven = new Op(7);
	Op* four = new Op(4);
	Base* treeA = new Mult(seven, four);
	
	EXPECT_EQ(seven->get_left(), nullptr);
}

TEST(VisitTest, VisitRight) {
	Base* seven = new Op(7);
	Base* four = new Op(4);
	Base* treeA = new Div(seven, four);

	EXPECT_EQ(treeA->get_right(), four);
}

TEST(VisitTest, VisitLeft) {
	Base* seven = new Op(7);
        Base* four = new Op(4);
        Base* treeA = new Add(seven, four);

        EXPECT_EQ(treeA->get_left(), seven);
}

TEST(CountVisitorTest, OneNum){
	Base* three = new Op(3);
	Base* dummy = new Op(0);
	Add* dum = new Add(dummy, three);
	CountVisitor* count = new CountVisitor();
	Iterator* itr = dum->create_iterator();
	itr->first();
	while(!itr->is_done()){
		itr->current()->accept(count);
		itr->next();
	}
	EXPECT_EQ(1, count->op_count());
	EXPECT_EQ(0, count->add_count());
	EXPECT_EQ(0, count->pow_count());
}

TEST(CountVisitorTest, TwoDigitNum){
	Base* ten = new Op(10);
	Base* dum1 = new Op(0);
	Add* dum2 = new Add(dum1, ten);
	CountVisitor* count = new CountVisitor();
	Iterator* itr = dum2->create_iterator();
	itr->first();
	while(!itr->is_done()){
		itr->current()->accept(count);
		itr->next();
	}
	EXPECT_EQ(1, count->op_count());
	EXPECT_EQ(0, count->sub_count());
	EXPECT_EQ(0, count->div_count());
}

TEST(CountVisitorTest, ADD){
	Base* two = new Op(2);
	Base* four = new Op(4);
	Base* dum = new Op(0);
	Add* add = new Add(two, four);
	Add* dummy = new Add(add, dum);
	CountVisitor* count = new CountVisitor();
	Iterator* itr = new PreorderIterator(dummy);
	itr->first();
	while(!itr->is_done()){
		itr->current()->accept(count);
		itr->next();
	}
	EXPECT_EQ(2, count->op_count());
	EXPECT_EQ(1, count->add_count());
	EXPECT_EQ(0, count->mult_count());
}

TEST(CountVisitorTest, SUB){
	Base* ten = new Op(10);
	Base* five = new Op(5);
	Base* dum = new Op(0);
	Base* sub = new Sub(ten,five);
	Base* dummy = new Sub(sub,dum);
	CountVisitor* count = new CountVisitor();
	Iterator* itr = new PreorderIterator(dummy);
	itr->first();
	while(!itr->is_done()){
		itr->current()->accept(count);
		itr->next();
	}
	EXPECT_EQ(2, count->op_count());
	EXPECT_EQ(1, count->sub_count());
	EXPECT_EQ(0, count->add_count());
}

TEST(CountVisitorTest, MULT){
	Base* two = new Op(2);
	Base* six = new Op(6);
	Base* mult = new Mult(two,six);
	Base* dum = new Op(0);
	Base* dummy = new Mult(mult,dum);
	CountVisitor* count = new CountVisitor();
	Iterator* itr = new PreorderIterator(dummy);
	itr->first();
	while(!itr->is_done()){
		itr->current()->accept(count);
		itr->next();
	}
	EXPECT_EQ(2, count->op_count());
	EXPECT_EQ(1, count->mult_count());
}

TEST(CountVisitorTest, DIV){
	Base* eight = new Op(8);
	Base* two = new Op(2);
	Base* div = new Div(eight,two);
	Base* dum = new Op(0);
	Base* dummy = new Div(div, dum);
	CountVisitor* count = new CountVisitor();
	Iterator* itr = new PreorderIterator(dummy);
	itr->first();
	while(!itr->is_done()){
		itr->current()->accept(count);
		itr->next();
	}
	EXPECT_EQ(2, count->op_count());
	EXPECT_EQ(1, count->div_count());
}

TEST(CountVisitorTest, POW){
	Base* three = new Op(3);
	Base* th2 = new Op(3);
	Base* pow = new Pow(three, th2);
	Base* dum = new Op(0);
	Base* dummy = new Add(dum, pow);
	CountVisitor* count = new CountVisitor();
	Iterator* itr = new PreorderIterator(dummy);
	itr->first();
	while(!itr->is_done()){
		itr->current()->accept(count);
		itr->next();
	}
	EXPECT_EQ(2, count->op_count());
	EXPECT_EQ(1, count->pow_count());
}

TEST(CountVisitorTest, MultipleNums) {
        Base* three = new Op(3);
        Base* two = new Op(2);
	Base* five = new Op(5);
	Base* dum = new Op(0);
	Base* mult = new Mult(two, three);
	Base* div = new Div(mult, five);
	Base* dummy = new Add(div, dum);
        CountVisitor* count = new CountVisitor();
        Iterator* itr = new PreorderIterator(dummy);
        itr->first();
        while(!itr->is_done()){
                itr->current()->accept(count);
                itr->next();
        }
        EXPECT_EQ(3, count->op_count());
        EXPECT_EQ(0, count->add_count());
	EXPECT_EQ(1, count->mult_count());
	EXPECT_EQ(1, count->div_count());
}

TEST(CountVisitorTest, MultipleNumsPow) {
        Base* three = new Op(3);
        Base* two = new Op(2);
        Base* five = new Op(5);
	Base* twenty_five = new Op(25);
        Base* dum = new Op(0);
        Base* mult = new Mult(two, three);
        Base* div = new Div(mult, five);
	Base* pow = new Pow(twenty_five, div);
        Base* dummy = new Add(pow, dum);
        CountVisitor* count = new CountVisitor();
        Iterator* itr = new PreorderIterator(dummy);
        itr->first();
        while(!itr->is_done()){
                itr->current()->accept(count);
                itr->next();
        }
        EXPECT_EQ(4, count->op_count());
        EXPECT_EQ(0, count->add_count());
        EXPECT_EQ(1, count->mult_count());
        EXPECT_EQ(1, count->div_count());
	EXPECT_EQ(1, count->pow_count());
}

TEST(CountVisitorTest, MultipleNumsSub) {
        Base* three = new Op(3);
        Base* two = new Op(2);
        Base* five = new Op(5);
        Base* twenty_five = new Op(25);
        Base* fifteen = new Op(15);
        Base* nine = new Op(9);
        Base* dum = new Op(0);
        Base* mult = new Mult(two, three);
        Base* div = new Div(mult, five);
        Base* pow = new Pow(twenty_five, div);
	Base* sub = new Sub(pow, fifteen);
	Base* sub2 = new Sub(sub, nine);
        Base* dummy = new Add(sub2, dum);
        CountVisitor* count = new CountVisitor();
        Iterator* itr = new PreorderIterator(dummy);
        itr->first();
        while(!itr->is_done()){
                itr->current()->accept(count);
                itr->next();
        }
        EXPECT_EQ(6, count->op_count());
        EXPECT_EQ(2, count->sub_count());
        EXPECT_EQ(0, count->add_count());
        EXPECT_EQ(1, count->mult_count());
        EXPECT_EQ(1, count->div_count());
        EXPECT_EQ(1, count->pow_count());
}

#endif
