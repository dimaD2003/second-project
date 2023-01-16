#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <Functions/funct.h>
using namespace std;

int main()
{cout<<endl;
    encode("DEV", std::cout);
	cout<<endl;

    base64_decode("SQ==", std::cout);
cout<<endl;
    return 0;
}
