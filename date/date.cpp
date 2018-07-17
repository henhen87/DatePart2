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
	cout << "INSIDE MINUS" << this.month << "/" << this.day << endl;
	Date tempDate = *this;
	cout << "11111" << endl;

	if (tempDate.datePtr->day >= obj.day)
	{
		tempDate.datePtr->day = tempDate.datePtr->day - obj.day;
	}
	else
	{
		tempDate.datePtr->day = tempDate.datePtr->day + 30;
		tempDate.datePtr->day = tempDate.datePtr->day - obj.day;
	}
	if (tempDate.datePtr->month > 1)
	{
		tempDate.datePtr->month = tempDate.datePtr->month - 1;
	}
	else
	{
		tempDate.datePtr->month = 12;
		tempDate.datePtr->year = tempDate.datePtr->year - 1;
	}

	if (tempDate.datePtr->month >= obj.month)
	{
		tempDate.datePtr->month = tempDate.datePtr->month - obj.month;
	}
	else
	{
		tempDate.datePtr->month = tempDate.datePtr->month + 12;
		tempDate.datePtr->month = tempDate.datePtr->month - obj.month;
		tempDate.datePtr->year = tempDate.datePtr->year - 1;
	}

	tempDate.datePtr->year = tempDate.datePtr->year - obj.year;
	return tempDate;
}

Date Date::operator=(const Date& obj)
{
	this->month = obj.month;
	this->day = obj.day;
	this->year = obj.year;

	cout << "DATE PTR " << this->month << "/" << this->day << endl;
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