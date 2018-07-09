#pragma once

#ifndef DATE_H
#define DATE_H
class Date
{
	int month, day, year;

public:
	Date();
	Date(Date &);
	bool operator== (Date);
	bool operator> (Date);
	Date operator- (Date);
	void operator= (Date);
};
#endif // !DATE_H

