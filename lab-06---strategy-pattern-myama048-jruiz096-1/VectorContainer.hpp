#ifndef __VECTOR_CONTAINER__
#define __VECTOR_CONTAINER__

#include "container.hpp"
#include <vector>
#include <iostream>
#include "base.hpp"
#include "sort.hpp"
using namespace std;

class VectorContainer : public Container{
	protected:
		Sort* sort_function;	
		vector<Base*> v;
	public:
		VectorContainer() : sort_function(nullptr) { };
		VectorContainer(Sort* function) : sort_function(function) { };
		
		void set_sort_function(Sort* sort_function){
			this->sort_function = sort_function;
		}
		virtual void add_element(Base* element){
			this->v.push_back(element); // top ptr of the tree is thelast posi of v
		}
		virtual void print() { // this is probablly wrong NEED TO CHECK AGAIN
			for(unsigned int i = 0; i < v.size(); i++){
				cout<< v.at(i)->stringify() << endl;
			}	
		}
		virtual void sort() {
			if(sort_function == nullptr){
				throw "sort_function is null";
			}
			this->sort_function->sort(this);		
		}	

		virtual void swap(int i, int j){ 
			Base* cpy = v.at(i);
			v.at(i) = v.at(j);
			v.at(j) = cpy;
		}
		virtual Base* at(int i){
			return v.at(i);
		}
		virtual int size(){
			return v.size();
		}
};

#endif
