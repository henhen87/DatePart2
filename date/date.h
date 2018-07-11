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
	Date(Date &obj);
	bool operator==(Date obj);
	bool operator>(Date obj);
	Date operator-(Date obj);
	void operator=(Date obj);

	friend ostream &operator>>(istream& in, Date &obj);
	friend istream &operator<<(ostream& out, Date obj);
};
#endif

