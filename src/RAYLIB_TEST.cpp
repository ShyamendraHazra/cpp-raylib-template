#include "RAYLIB_TEST.h"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{  
    Test test_one;
    Test test_two(20, 40);

    test_one.print_value();
    test_two.print_value();

    return 0;
}