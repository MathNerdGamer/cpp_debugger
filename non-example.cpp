#include <iostream>

int main(int argc, char **argv)
{
    int num = 1;
    std::string str = "string";
    std::string another_great_variable_name = "What am I doing with my life?";

    std::cout << "num = " << num << ", str = " << str
              << ", another_great_variable_name = "
              << another_great_variable_name << '\n';
    // So much work! And if I ever change a variable name, I have to change two
    // things in there!

    return 0;
}