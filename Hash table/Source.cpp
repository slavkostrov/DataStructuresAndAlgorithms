#include "Header.h"

registration::registration(int32_t number, std::string title, std::string founder)
{
	this->number = number;
	this->title = title;
	this->founder = founder;
}

registration::operator int()
{
	return this->number;
}

bool operator==(const int& c2, const registration& c1)
{
	return c1.number == c2;
}

std::ostream& operator<<(std::ostream& out, const registration& obj)
{
	out << "Number: " << obj.number << " Title: " << obj.title << " Founder: " << obj.founder << '\n';
	return out;
}

bool operator==(const registration& c1, const int& c2)
{
	return c1.number == c2;
}





