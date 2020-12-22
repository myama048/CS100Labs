#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "op.hpp"

class Sub : public Base {
	private:
		Base* lhs;
		Base* rhs;
	public:
		Sub(Base* lhs, Base* rhs) : Base() {
			this->lhs = lhs;
			this->rhs = rhs;
		}
		virtual double evaluate() { return lhs->evaluate() -  rhs->evaluate(); }
		virtual std::string stringify() { return "(" + lhs->stringify() + " - " + rhs->stringify() + ")";}
		virtual Iterator* create_iterator(){
			Iterator* itr = new BinaryIterator(this);
			return itr;
		}
		virtual Base* get_left(){ return lhs;}
		virtual Base* get_right(){ return rhs;}

		virtual void accept(CountVisitor* cntV){
			cntV->visit_sub();
		}

};


#endif
