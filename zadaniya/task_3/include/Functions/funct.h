
#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
int CharinInt(char x);
char IntChar(int x);
int InTenCC(std::string binStr);
int pow(int x, int y);
int InBB(int x);
std::string FullEnd(std::string &data, char num);
std::string FullandString(int x, int n);
int TranslateInNum(char n);
char TranslateInCode(int n);

void encode(std::string s, std::ostream &os);

std::string base64_decode(std::string s, std::ostream &os);
