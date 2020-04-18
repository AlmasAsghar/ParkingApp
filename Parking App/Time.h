#ifndef TIME_H
#define TIME_H
#include<iostream>
#include<atltime.h>
using namespace std;
class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time();
	Time(int h, int m, int s);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	int getHour();
	int getMinute();
	int getSecond();
	void incMin(int);
	void incSec(int);
	void incHour(int);
	Time & operator= (const Time &);
	void setTime(int s, int m, int h);
	void printTwentyFourHourFormat();
	void printTwelveHourFormat();
	void getCurrentTime(int &h, int &m, int &s);
};
#endif

