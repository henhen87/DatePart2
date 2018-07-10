#pragma once
#include <iostream>
using std::cin;
using std::cout;
#ifndef DATE_H
#define DATE_H
class Date
{
	int month, day, year;

public:
	Date();
	Date(Date &);
	bool operator== (Date obj);
	bool operator> (Date obj);
	Date operator- (Date obj);
	void operator= (Date obj);

	friend Date operator>>(ostream& out, Date a);
};
#endif // !DATE_H

