#pragma once
#include <iostream>
using std::ostream;
using std::istream;
#ifndef DATE_H
#define DATE_H
class Date
{
	int month, day, year;
	Date *datePtr = this;
public:
	Date();
	Date(Date &);
	bool operator==(const Date& obj);
	bool operator>(const Date& obj);
	Date operator-(const Date& obj);
	Date operator=(const Date& obj);

	friend istream &operator>>(istream& in, Date &obj);
	friend ostream &operator<<(ostream& out, Date &obj);
};
#endif

