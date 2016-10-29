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


std::istream& operator >> (std::istream& is, Sex& i)
{
	int tmp;
	if (is >> tmp)
		i = static_cast<Sex>(tmp);
	return is;
}