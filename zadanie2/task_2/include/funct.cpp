#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include "Functions/funct.h"

std::string input(std::string s)
{
    std::getline(std::cin, s);
    return s;
}
std::string DeleteSpace(std::string &s)
{
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    return s;
}
void output(std::string s)

{

    std::string v;
    char first;
    int k = 0;
    try
    {
        if ((s.empty()) || (s.length() > 100))
        {

            throw(s);
        }
        else
        {
            for (int i = 0; i < DeleteSpace(s).length(); i++)
            {
                if (i == 0)
                {
                    first = (char)toupper(s[i]);
                }
                else
                    v += s[i];
            }
           std:: cout << "#" << first << v;
        }
    }
    catch (...)
    {
        std::cout << "X is empty or more than 100 symbols \n";
    }
}
