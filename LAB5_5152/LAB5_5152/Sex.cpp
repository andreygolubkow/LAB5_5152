#include "Sex.h"

std::string SexToStr(Sex sex)
{
	switch (sex)
	{
	case (Male):
		return "Male";
	case (Female):
		return "Female";
	default:
			return "Female";
	}
}

Sex StrToSex(std::string sex)
{
	//std::transform(sex.begin(), sex.end(), sex.begin(), ::tolower);
	if (sex == "m")
	{
		return Male;
	}
	else
	{
		return Female;
	}
}


std::istream& operator >> (std::istream& stream, Sex &sex)
{
	std::string s;
	stream >> s;
	if (s.compare("Male") == 0)
	{
		sex = Male;
	}
	else
	{
		sex = Female;
	}
	  return stream;
}

std::ostream & operator<<(std::ostream & os, Sex & sex)
{
	switch (sex)
	{
	case (Male):
		os<< "Male";
	case (Female):
		os<< "Female";
	default:
		os<<"";
	}
	return os;
	// TODO: вставьте здесь оператор return
}
