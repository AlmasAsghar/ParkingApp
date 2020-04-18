#include<iostream>
#include<iomanip>
using namespace std;

#include "Date.h"

const int Date::daysInMonth[13] = { 0, 31, 28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date() :Date(25, 11, 2017)
{

}
bool Date::isLeapYear(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return true;
	else
		return false;
}
Date::Date(int d, int m, int y)
{
	if (y >= 1990 && y <= 2100)
		year = y;
	else
		year = 0000;
	if (d >= 1 && d <= daysInMonth[m] || m == 2 && d <= 29 && isLeapYear(y))
		day = d;
	else
		day = 00;
	if (m >= 1 && m <= 12)
		month = m;
	else
		month = 00;
}
Date & Date::operator=(const Date & ref)
{
	day = ref.day;
	month = ref.month;
	year = ref.year;
	return *this;
}
void Date::setDate(int d, int m, int y)
{
	setDay(d);
	setMonth(m);
	setYear(y);
}
void Date::setDay(int d)
{
	if (d >= 1 && d <= daysInMonth[month] || month == 2 && d <= 29 && isLeapYear(year))
		day = d;
}
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
		month = m;
}
void Date::setYear(int y)
{
	if (y >= 1990 && y <= 2100)
		year = y;
}
int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}
void Date::printFormat1()const
{
	cout.fill('0');
	cout << setw(2) << day << "/" << setw(2) << month << "/" << setw
		(4) << year;
}
void Date::printFormat2() const
{
	static char *name[] = { "null", "January", "February", "March", "April",
		"May", "June", "July", "August", "September", "October",
		"November", "December" };
	cout << "\n" << name[month] << ' ' << day << "," << year << '\n';
}
void Date::printFormat3() const
{
	static char *name[] = { "null", "January", "February", "March", "April",
		"May", "June", "July", "August", "September", "October",
		"November", "December" };
	cout << "\n" << day << ' ' << name[month] << "," << year;
}
void Date::incDay(int d)
{
	/*int m;
	d = getDay() + d;
	if (d>daysInMonth[month])
	{
	m = d / daysInMonth[month];
	d = d - daysInMonth[month];
	incMonth(m);

	}
	setDay(d);*/

	if ((day + d) <= daysInMonth[month] || month == 2 && (day + d) <= 29 && isLeapYear(year))
	{
		day = day + d;
	}
	else
	{
		int dy = day + d;
		day = dy % daysInMonth[month];
		incMonth(dy / daysInMonth[month]);
	}
}
void Date::incMonth(int m)
{
	if ((month + m) <= 12)
	{
		month = month + m;
	}
	else
	{
		int mth = month + m;
		month = mth % 12;
		incYear(mth / 12);
	}
}
void Date::incYear(int y)
{
	if (getYear() + y >= 2100)
	{
		year = y + year;
	}
	else
	{
		int yr = year + y;
		year = yr % 2100;
	}
}
myCString Date::getDateInFormat1() const
{
	int n = getDay();
	myCString s(tomyCString(n));
	s.concatEqual("/");
	int n2 = getMonth();
	s.concatEqual(tomyCString(n2));
	s.concatEqual("/");
	int n3 = getYear();
	s.concatEqual(tomyCString(n3));
	return s;
}
myCString Date::getDateInFormat2() const
{
	char str[12][10] = { "junuary","February","March","April","May","June","July","August","September","October","NOvember","December" };
	int n = getDay();
	myCString s2(tomyCString(n));
	s2.concatEqual(" ");
	s2.concatEqual(str[getMonth() - 1]);
	s2.concatEqual(" ");
	int n2 = getYear();
	s2.concatEqual(tomyCString(n2));
	return s2;
}
myCString Date::getDateInFormat3() const
{
	char str[12][10] = { "junuary","February","March","April","May","June","July","August","September","October","NOvember","December" };
	myCString copy(str[getMonth() - 1]);
	copy.concatEqual(" ");
	int n = getDay();
	copy.concatEqual(tomyCString(n));
	copy.concatEqual(",");
	int n2 = getYear();
	copy.concatEqual(tomyCString(n2));
	return copy;
}
myCString Date::tomyCString(long long int num)const
{
	char str[10];
	int i, rem, len = 0, n;
	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
	return myCString(str);
}