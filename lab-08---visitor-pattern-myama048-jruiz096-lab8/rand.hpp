#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "op.hpp"
#include <string>

class Rand : public Base{
	private:
		double value;
	public:
		Rand() : Base() {
			this->value = rand() % 100;
		}
		virtual double evaluate() { return value; }
		virtual string stringify() { return to_string(value); }

		virtual Iterator* create_iterator(){
			Iterator* itr = new NullIterator(this);
			return itr;
		}
		virtual Base* get_left(){ return nullptr;}
		virtual Base* get_right(){ return nullptr;}

		virtual void accept(CountVisitor* cntV){
			cntV->visit_rand();
		}
};

#endif
