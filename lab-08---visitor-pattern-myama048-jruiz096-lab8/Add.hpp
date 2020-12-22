#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "op.hpp"

class Add : public Base {
    private:
	Base* lhs;
	Base* rhs;
    public:
	Add(Base* lhs, Base* rhs) : Base(){
	    this->lhs = lhs;
	    this->rhs = rhs;
	}
	virtual double evaluate() {return lhs->evaluate() + rhs->evaluate();}
	virtual std::string stringify()  {return "(" + lhs->stringify() + " + " + rhs->stringify() +  ")";};
	virtual Iterator* create_iterator(){
		Iterator* itr = new BinaryIterator(this);
		return itr;	
	}
	virtual Base* get_left(){return lhs;}
	virtual Base* get_right(){return rhs;}
	
	virtual void accept(CountVisitor* cntV){
		cntV->visit_add();
	}
};

#endif
