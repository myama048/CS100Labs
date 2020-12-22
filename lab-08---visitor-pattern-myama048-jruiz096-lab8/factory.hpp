#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__


#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "pow.hpp"
#include "Div.hpp"
#include "Add.hpp"
#include "sub.hpp"

class Factory{
	public:
		virtual Base* parse(char** input, int length) = 0;
};
#endif
