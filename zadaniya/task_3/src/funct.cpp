#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "Functions/funct.h"
using namespace std;
// РёР· СЃС‚СЂ РІ С‡РёСЃР»Рѕ
int CharinInt(char x)
{
    // int code;
    // code = x - 'A';
    return (int)x;
}
char IntChar(int x)
{
    return (char)x;
}

// РІ 10СЃСЃ
int InTenCC(string binStr)
{
    int digit = 0;
    // char binary[50];
    int count = 1;

    for (int i = binStr.size(); i > 0; i--, count *= 2)
    {
        if ((binStr[i - 1] != '0') && (binStr[i - 1] != '1'))
        {

            break;
        }
        if (binStr[i - 1] == '1')
        {
            digit += count;
        }
    }
    return digit;
}

int pow(int x, int y)
{
    int n = 1;
    while (y--)
        n *= x;
    return n;
}
// РІ 2СЃСЃ
int InBB(int x)
{

    int bin = 0; // Р�СЃРєРѕРјРѕРµ С‡РёСЃР»Рѕ РІ РґРІРѕРёС‡РЅРѕР№ CC
    int i = 0;   // Р Р°Р·СЂСЏРґ РґРІРѕРёС‡РЅРѕРіРѕ С‡РёСЃР»Р°

    while (x > 1)
    {
        bin += (x % 2) * pow(10, i); // РџСЂРёСЃРІР°РёРІР°РµРј i-С‚РѕРјСѓ СЂР°Р·СЂСЏРґСѓ РѕСЃС‚Р°С‚РѕРє РѕС‚ РґРµР»РµРЅРёСЏ
        x /= 2;
        i++;
    }
    bin += x * pow(10, i);

    return bin;
}
string FullEnd(string &data, char num)
{
    data.insert(data.end(), num);
    return data;
}

// РґРѕР±Р°РІ РЅРµРґРѕСЃС‚ РЅСѓР»Рё
string FullandString(int x, int n)
{ // x = int

    int number = x;
    int precision;

    std::ostringstream ostr;
    ostr << x;

    string str = ostr.str();
    // int n = 8;
    if (n == str.size())
    {
        return str;
    }
    if (n < str.size())
    {
        precision = n - n;
    }
    else if (n > str.size())
    {
        precision = n - str.size();
    }

    str.insert(0, precision, '0');
    return str;
}

// РёР· С‡РёСЃР»РѕР° РІ  РєРѕРґС‹
char TranslateInCode(int n)
{
    char map[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                  'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

    for (auto i = 0; i < 63; i++)
    {
        if (n == i)
        {
            return map[i];
        }
    }
}

int TranslateInNum(char n)
{
    char map[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                  'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

    for (auto i = 0; i < 63; i++)
    {
        if (n == map[i])
        {
            return i;
        }
    }
}

void encode(string s, std::ostream &os)
{

    string buf;
    string encod;
    vector<string> masStr;
    char zero = '0';
    int count;
    vector<int> masDec;

    string result;
    int k = 0;
    for (auto m : s)
    {
        result += FullandString(InBB(CharinInt(m)), 8); // re="010011101000001010001011010" full string
    }

    //% on 6
    for (auto i = 0; i < result.size(); i++)
    {
        if (i == k + 5)
        {

            for (int j = k; j <= i; j++)
            {
                buf = buf + result[j];
            }
            masStr.push_back(buf); //["000000 "  000000  000000 ........]= masStr
            buf = "";
            k += 6;
        }
    }

    if (result.size() - k == 2)
        count = 3;
    if (result.size() - k == 4)
        count = 2;
    if (result.size() - k != 0) // 2
    {
        for (int l = k; l < result.size(); l++)
        {
            buf = buf + result[l]; //[  01   ]
        }

        for (int n = 0; n < (6 - buf.size()) + count; n++)
        {

            FullEnd(buf, zero);
        }
        masStr.push_back(buf);
    }

    for (int r = 0; r < masStr.size(); r++)
    {
        masDec.push_back(InTenCC(masStr[r])); // [17 , 25 , 2 ... ]
    }

    if (result.size() - k == 2)
    {
        for (auto num : masDec)
        {
            os << TranslateInCode(num);
        }
        os << "==";
    }
    else if (result.size() - k == 4)
    {
        for (auto num : masDec)
        {
            os << TranslateInCode(num);
        }
        os << "=";
    }
    else if (result.size() - k == 0)
    {
        for (auto num : masDec)
        {
            os << TranslateInCode(num);
        }
    }
}

string base64_decode(string s, std::ostream &os)
{
    char map[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                  'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

    string buf;
    string encod;
    vector<string> masStr;
    char zero = '0';
    int count;
    vector<int> masDec;

    string result;
    int k = 0;
    int countEqual = 0;
    int lenStr = s.size();

    if (s[lenStr - 1] == '=')
    { // last
        countEqual++;
        // lenStr--; // 3
    }

    if (s[lenStr - countEqual - 1] == '=')
    { // predlast
        countEqual++;
        // lenStr--; // 2
    }

    for (auto m = 0; m < lenStr - countEqual; m++)
    {

        result = result + FullandString(InBB(TranslateInNum(s[m])), 6); //[000101010101110101]
        // os << result << endl;
    }
    // os << result << endl;
    //       /8
    for (auto i = 0; i < result.size(); i++)
    {
        if (i == k + 7)
        {

            for (int j = k; j <= i; j++)
            {
                buf = buf + result[j];
            }
            masStr.push_back(buf); //["00000000 "  00000000  00000000 ........]= masStr
            buf = "";
            k += 8;
        }
    }
    // os << masStr[0] << endl;
    // os << masStr[1] << endl;
    // os << masStr[2] << endl;
    for (int l = 0; l < masStr.size(); l++)
    {
        if (masStr[l] == "00" || masStr[l] == "0000")
        {
            masStr.erase(masStr.begin() + l);
        }
    }

    for (int r = 0; r < masStr.size(); r++)
    {
        masDec.push_back(InTenCC(masStr[r])); // [17 , 25 , 2 ... ]
    }

    for (auto num : masDec)
    {
        os << IntChar(num);
    }

    // os << masStr[0];
}

