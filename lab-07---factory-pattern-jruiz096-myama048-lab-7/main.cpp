#include <iostream>

#include "base.hpp"
#include "Mult.hpp"
#include "Add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "Div.hpp"
#include "factory.hpp"
#include "parse.hpp"


int main(int argv, char** argc) {
	 Factory* factory = new Parse();
 	 Base* calc = factory->parse(argc, argv);
	 if (calc) {
	 std::cout << calc->stringify() << " = " << calc->evaluate() << std::endl;
	 }
	 else
		std::cout << "Invalid input!" << std::endl;
	//std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
	return 0;
}
