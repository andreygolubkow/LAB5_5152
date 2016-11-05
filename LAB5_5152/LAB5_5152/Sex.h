#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>

enum Sex
{
	Male, Female
};

std::string SexToStr(Sex sex);
Sex StrToSex(std::string sex);
std::istream& operator >> (std::istream& is, Sex& sex);
std::ostream& operator << (std::ostream& os, Sex& sex);