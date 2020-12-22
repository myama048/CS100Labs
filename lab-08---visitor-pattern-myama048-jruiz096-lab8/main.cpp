#include <iostream>

#include "base.hpp"
#include "Mult.hpp"
#include "Add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "Div.hpp"
#include "factory.hpp"
#include "parse.hpp"
#include "visitor.hpp"
#include "iterator.hpp"

int main(int argv, char** argc) {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    	 Factory* factory = new Parse();
 	 Base* calc = factory->parse(argc, argv);
	 if (calc) { // Add class which have lhs=3 and rhs=2
	 std::cout << calc->stringify() << " = " << calc->evaluate() << std::endl;
	 }
	 else
		std::cout << "Invalid input!" << std::endl;
	 CountVisitor* count = new CountVisitor();
	 Op* dummy1 = new Op(0);
	 calc = new Add(calc, dummy1);
	 Iterator* itr = new PreorderIterator(calc);
	 itr->first();
	 while(!itr->is_done()) {
	 	itr->current()->accept(count);
		itr->next();
	 }
	 count->print_counts();
	
	//std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    	return 0;
}
