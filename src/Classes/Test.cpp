#include "Test.h"

using std::pair;
using std::cout;
using std::endl;

void Test::set_value(int x, int  y) {
    a = x;
    b = y;
}

pair<int, int> Test::get_value() {
    return pair<int, int>(a, b);
}

void Test::print_value() {
    cout << "a : " << a << " b : " << b << endl;
}