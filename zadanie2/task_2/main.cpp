
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include "Functions/funct.h"

int main()
{
    std::string str;
    std::cout << "string = " << std::endl;
    getline(std::cin, str);
    output(str);

    return 0;
}
