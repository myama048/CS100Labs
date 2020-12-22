#ifndef __BUBBLESORT_HPP__
#define __BUBBLESORT_HPP__

#include "container.hpp"

class Container;

class BubbleSort: public Sort {
    public:
        /* Constructors */
        BubbleSort(){};

        /* Pure Virtual Functions */
        virtual void sort(Container* container) {
	  for(unsigned i = 0; i < container->size() - 1; i++){
	     for(unsigned j = 0; j < container->size()- 1; j++){
	         if(container->at(j)->evaluate() > container->at(j+1)->evaluate()) {
	            container->swap(j, j+1);
	         }
	     }       
	  }
        }
};

#endif //__BUBBLESORT_HPP__

