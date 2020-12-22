#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "op.hpp"
#include <stdexcept>

class Div : public Base {
    private:
	Base* lhs;
	Base* rhs;
    public:
	Div(Base* lhs, Base* rhs) : Base() {
	    this->lhs = lhs;
	    this->rhs = rhs;
	}
	virtual double evaluate() {
		if (rhs->evaluate() == 0) {
			//std::cout << "Zero in denominator" << std::endl;
			return 0;
		}
		return lhs->evaluate() / rhs->evaluate();
	}
	virtual std::string stringify() {return "(" + lhs->stringify() + " / " + rhs->stringify() + ")";}

	virtual Iterator* create_iterator(){
		Iterator* itr = new BinaryIterator(this);
		return itr;
	}
	virtual Base* get_left(){return lhs;}
	virtual Base* get_right(){return rhs;}

	virtual void accept(CountVisitor* cntV){
		cntV->visit_div();
	}
};

#endif
