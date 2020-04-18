#ifndef DATE_H
#define DATE_H

#include "CString.h"

class Date
{
private:
	int day;
	int month;
	int year;
	static const int daysInMonth[13];
	bool isLeapYear(int y);
	myCString tomyCString(long long int num)const;
public:
	Date();
	Date(int, int, int);
	void setDate(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	Date & operator=(const Date &);
	void printFormat1()const;
	void printFormat2() const;
	void printFormat3() const;
	myCString getDateInFormat1() const;
	myCString getDateInFormat2() const;
	myCString getDateInFormat3() const;
	void incDay(int);
	void incMonth(int);
	void incYear(int);
};

#endif

