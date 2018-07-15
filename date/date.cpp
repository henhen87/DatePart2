// date.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "date.h"
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

Date::Date() : month(1), day(1), year(2000) {};

bool Date::operator==(const Date obj)
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

bool Date::operator>(const Date obj)
{
	if (year > obj.year)
	{
		return true;
	}
	else if (year == obj.year)
	{
		if (month > obj.month)
		{
			return true;
		}
		else if (month == obj.month)
		{
			if (day > obj.day)
			{
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

Date Date::operator-(const Date date2)
{
	cout << "Month BEFORE CHANGE " << this->month << "month no arrow " << month << endl;
	if (day >= date2.day)
	{
		day = day - date2.day;
	}
	else
	{
		day = day + 30;
		day = day - date2.day;
	}
	if (month > 1)
	{
		month = month - 1;
	}
	else
	{
		month = 12;
		year = year - 1;
	}

	if (month >= date2.month)
	{
		month = month - date2.month;
	}
	else
	{
		month = month + 12;
		month = month - date2.month;
		year = year - 1;
	}

	year = year - date2.year;
	cout << "THIS POINTER MINUS " << this->month << endl;
	cout << "Month" << month << "DAY" << day << "Year" << year << endl;
	return *this;
}

/*void Date::operator=(Date obj)
{

}*/

ostream &operator<<(ostream& out, Date obj)
{
	cout << "\nInside OSTREAM" << endl;
	out << obj.month << "/" << obj.day << "/" << obj.year << endl;
	return out;
}

istream &operator>>(istream& in, Date &obj)
{
	cout << "\nInside ISTREAM" << endl;
	cout << "Enter month (1-12):";
	in >> obj.month;
	cout << "Enter day (1 to maximum days in month):";
	in >> obj.day;
	cout << "Enter year (>= 1800):";
	in >> obj.year;
	return in;
}