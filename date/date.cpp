// date.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "date.h"
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

Date::Date() : month(1), day(1), year(2000) {};

bool Date::operator==(Date obj)
{

}

bool Date::operator>(Date obj)
{

}

Date Date::operator-(Date obj)
{

}

void Date::operator=(Date obj)
{

}

ostream &operator<<(ostream& out, Date obj)
{
	cout << "\nInside OSTREAM" << endl;
	out << obj.month << obj.day << obj.year;
	return out;
}

istream &operator>>(istream& in, Date &obj)
{
	cout << "\nInside ISTREAM" << endl;
}