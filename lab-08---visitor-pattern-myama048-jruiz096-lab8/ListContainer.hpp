#ifndef __LIST_CONTAINER__
#define __LIST_CONTAINER__
#include "container.hpp"
#include <list>
#include <iostream>
using namespace std;

class Sort;
class Base;
class Container;


class ListContainer : public Container {
    private:
	list<Base*> l;
	Sort* sort_function;
    public:
	// constructors
	ListContainer() : sort_function(nullptr) {};
	ListContainer(Sort* function) : sort_function(function) {};

	void set_sort_function(Sort* sort_function) {
	    this->sort_function = sort_function;
	}


	void add_element(Base* element) {
	    l.push_back(element);
	}
	
	void print() {
	    for (auto const& i : l) {
		cout << i->stringify() << endl;
	    }
	}
	
	void sort() {
	    this->sort_function->sort(this);
	}

	void swap(int i, int j) {
	    list<Base*>::iterator it = l.begin();
	    list<Base*>::iterator iter = l.begin();
	    advance(it, i);
	    advance(iter, j);
	    iter_swap(it, iter);

	}

	Base* at(int i) {
	    list<Base*>::iterator it = l.begin();
	    advance(it, i);
	    return *it;
	}

	int size() {
	    return l.size();
	}
};

#endif
