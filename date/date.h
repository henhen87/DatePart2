#pragma once
#include <iostream>
using std::ostream;
using std::istream;
#ifndef DATE_H
#define DATE_H
class Date
{
	int month, day, year;

public:
	Date();
	//Date(Date &obj);
	bool operator==(const Date obj);
	bool operator>(const Date obj);
	Date operator-(const Date date2);
	//void operator=(Date obj);

	friend istream &operator>>(istream& in, Date &obj);
	friend ostream &operator<<(ostream& out, Date obj);
};
#endif

