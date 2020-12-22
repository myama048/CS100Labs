#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>
#include "visitor.hpp"

using namespace std;

class Op : public Base {
	private:
		double value;
    public:
        Op(double value) : Base() { this->value = value;}
        virtual double evaluate() { return value; }
        virtual string stringify() { return to_string(value); }
	Iterator* create_iterator(){
		Iterator* itr = new NullIterator(this);
		return itr;
	}
	virtual Base* get_left(){ return nullptr;}
	virtual Base* get_right(){ return nullptr;}

	virtual void accept(CountVisitor* cntV){
		cntV->visit_op();
	}
};

#endif //__OP_HPP__
