#include <iostream>
#include "debugger.h"

int main(int argc, char **argv)
{
    int num = 1;
    std::string str = "string";
    std::string another_great_variable_name = "What am I doing with my life?";

    DEBUG_OUTPUT(num, str, another_great_variable_name);
    // Yes, it is that easy.

    return 0;
}

/*
Output:

num = 1, str = string, another_great_variable_name = What am I doing with my life?

*/