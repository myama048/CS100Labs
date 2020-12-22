#ifndef __COUNT_VISITOR_HPP__
#define __COUNT_VISITOR_HPP__

#include <iostream>
using std::cout;
using std::endl;

class CountVisitor{
    private:
        int ops;
        int rands;
        int mult;
        int div;
        int add;
        int sub;
        int pow;

    public:
        CountVisitor() {
		ops = -1; // accounting for dummy
		rands = 0;
		mult = 0;
		div = 0;
		add = 0;
		sub - 0;
		pow = 0;
	};

        void visit_op() { ops++; };
        int op_count() { return ops; }
        void visit_rand() { rands++; };
        int rand_count() { return rands; }
        void visit_mult() { mult++; };
        int mult_count() { return mult; }
        void visit_div() { div++; };
        int div_count() { return div; }
        void visit_add() { add++; };
        int add_count() { return add; }
        void visit_sub() { sub++; };
        int sub_count() { return sub; }
        void visit_pow() { pow++; };
        int pow_count() { return pow; }
	void print_counts() {
		cout << "Op   : " << op_count() << endl;
                cout << "Rands: " << rand_count() << endl;
                cout << "Mults: " << mult_count() << endl;
                cout << "Divs : " << div_count() << endl;
                cout << "Add  : " << add_count() << endl;
                cout << "Sub  : " << sub_count() << endl;
                cout << "Pow  : " << pow_count() << endl;
	} 

};

#endif //__COUNT_VISITOR_HPP__
