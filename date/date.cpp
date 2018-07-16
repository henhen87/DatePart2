// date.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "date.h"
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

Date::Date() : month(1), day(1), year(2000) {};

Date::Date(Date &obj)
{
	cout << "INSIDE COPY CONSTRUCTOR" << obj.month << "/" << obj.day << endl;
	datePtr = new Date;
	(*datePtr).month = obj.month;
	(*datePtr).day = obj.day;
	(*datePtr).year = obj.year;
}

bool Date::operator==(const Date& obj)
{
	if (datePtr->month == obj.month && datePtr->day == obj.day && datePtr->year == obj.year)
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
	if (datePtr->year > obj.year)
	{
		return true;
	}
	else if (datePtr->year == obj.year)
	{
		if (datePtr->month > obj.month)
		{
			return true;
		}
		else if (datePtr->month == obj.month)
		{
			if (datePtr->day > obj.day)
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
	cout << "OBJ PARAMETER --- " << obj.month << "/" << obj.day << endl;
	cout << "LOCAL MEMBER --- " << datePtr->month << "/" << datePtr->day << endl;
	cout << "THIS --- " << this->month << "/" << this->day << endl;

	if (this->day >= obj.day)
	{
		this->day = this->day - obj.day;
	}
	else
	{
		this->day = this->day + 30;
		this->day = this->day - obj.day;
	}
	if (this->month > 1)
	{
		this->month = this->month - 1;
	}
	else
	{
		this->month = 12;
		this->year = this->year - 1;
	}

	if (this->month >= obj.month)
	{
		this->month = this->month - obj.month;
	}
	else
	{
		this->month = this->month + 12;
		this->month = this->month - obj.month;
		this->year = this->year - 1;
	}

	this->year = this->year - obj.year;
	return *this;
}

/*Date Date::operator=(const Date& obj)
{
	this->month = obj.month;
	this->day = obj.day;
	this->year = obj.year;

	cout << "DATE PTR " << this->month << "/" << this->day << endl;
	return *this;
}*/

ostream &operator<<(ostream& out, Date &obj)
{
	out << obj.datePtr->month << "/" << obj.datePtr->day << "/" << obj.datePtr->year << endl;
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