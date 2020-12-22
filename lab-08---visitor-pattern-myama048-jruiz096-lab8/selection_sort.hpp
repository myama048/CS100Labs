#ifndef __SELECTIONSORT_HPP__
#define __SELECTIONSORT_HPP__

#include "container.hpp"
#include "sort.hpp"

class Container;

class SelectionSort : public Sort {
    public:
        /* Constructors */
        SelectionSort(){};

        void sort(Container* container){
		int min_index;
		for (unsigned i = 0; i < container->size(); i++){
			min_index = i;
			for (unsigned j = i; j < container->size(); j++){
				if (container->at(j)->evaluate() < container->at(min_index)->evaluate()) {
					min_index = j;
				}
			}
			container->swap(i,min_index);	
		}
	};
};

#endif //__SORT_HPP__

