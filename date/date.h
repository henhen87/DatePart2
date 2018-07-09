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
	bool operator==(Date);
	bool operator>(Date);
	Date operator-(Date);
	void operator=(Date);

	friend Date operator>>(int, int, int);
};
#endif // !DATE_H

