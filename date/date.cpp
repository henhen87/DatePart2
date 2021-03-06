// date.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "date.h"
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

Date::Date() : month(1), day(1), year(2000) {};

Date::Date(const Date &obj)
{
	month = obj.month;
	day = obj.day;
	year = obj.year;
}

bool Date::operator==(const Date& obj)
{
	if (month == obj.month && day == obj.day && year == obj.year)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator>(const Date& obj)
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

Date Date::operator-(const Date& obj)
{
	Date tempDate = *this;

	if (tempDate.day >= obj.day)
	{
		tempDate.day = tempDate.day - obj.day;
	}
	else
	{
		tempDate.day = tempDate.day + 30;
		tempDate.day = tempDate.day - obj.day;
	}
	if (tempDate.month > 1)
	{
		tempDate.month = tempDate.month - 1;
	}
	else
	{
		tempDate.month = 12;
		tempDate.year = tempDate.year - 1;
	}

	if (tempDate.month >= obj.month)
	{
		tempDate.month = tempDate.month - obj.month;
	}
	else
	{
		tempDate.month = tempDate.month + 12;
		tempDate.month = tempDate.month - obj.month;
		tempDate.year = tempDate.year - 1;
	}

	tempDate.year = tempDate.year - obj.year;
	return tempDate;
}

Date Date::operator=(const Date& obj)
{
	month = obj.month;
	day = obj.day;
	year = obj.year;

	return *this;
}

ostream &operator<<(ostream& out, Date &obj)
{
	out << obj.month << "/" << obj.day << "/" << obj.year << endl;
	return out;
}

istream &operator>>(istream& in, Date &obj)
{
	cout << "Enter month (1-12):";
	in >> obj.month;
	cout << "Enter day (1 to maximum days in month):";
	in >> obj.day;
	cout << "Enter year (>= 1800):";
	in >> obj.year;
	return in;
}