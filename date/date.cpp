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
	cout << "\nOPERATOR EQUAL DATE PARAMETER\n" << obj.month << obj.day << obj.year << endl;
	cout << "\nOPERATOR EQUAL DATE LOCAL" << month << day << year;

	if (month == obj.month && day == obj.day && year == obj.year)
	{
		return true;
	}
	else
	{
		return false;
	}
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
	out << obj.month << obj.day << obj.year << endl;
	return out;
}

istream &operator>>(istream& in, Date &obj)
{
	cout << "\nInside ISTREAM" << endl;
	in >> obj.month;
	in >> obj.day;
	in >> obj.year;
	return in;
}