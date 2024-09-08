#ifndef TEST_H
#define TEST_H

#include "common.h"

using std::pair;
using std::cout;
using std::endl;

class Test
{
 
    private:
        int a;
        int b;
 
    public:       

        Test(int x = 10, int y = 20) : a(x), b(y) {}

        void set_value(int x = 0, int y = 0);
        pair<int, int> get_value();
        void print_value();
};

#endif