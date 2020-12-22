#ifndef _MULT_HPP_
#define _MULT_HPP_

#include <string>
#include "base.hpp"
//#include "binary_iterator.cpp"

class Mult : public Base {
	private:
		Base* lhs;
		Base* rhs;
	public:
		// constructor
		Mult(Base* lhs, Base* rhs) : Base() {
			this->lhs = lhs;
			this->rhs = rhs;
		}
	
		// member functions
		virtual double evaluate() {return lhs->evaluate() * rhs->evaluate(); };
		virtual std::string stringify() {return "(" + lhs->stringify() +  " * "  + rhs->stringify() + ")";}
		virtual Iterator* create_iterator(){
			Iterator* itr = new BinaryIterator(this);
			return itr;
		}
		virtual Base* get_left(){return lhs;}
		virtual Base* get_right(){return rhs;}

		virtual void accept(CountVisitor* cntV){
			cntV->visit_mult();
		}
};

#endif
