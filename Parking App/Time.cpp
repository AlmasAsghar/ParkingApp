#include"Time.h"
Time::Time() :Time(10, 10, 10)
{
}
Time::Time(int h, int m, int s)
{
	if (h >= 1 && h <= 23)
		hour = h;
	else
		hour = 12;
	if (m >= 1 && m <= 59)
		minute = m;
	else
		minute = 12;
	if (s >= 1 && s <= 59)
		second = s;
	else
		second = 12;
}
void Time::setHour(int h)
{
	if (h >= 1 && h <= 23)
		hour = h;
}
void Time::setMinute(int m)
{
	if (m >= 1 && m <= 59)
		minute = m;
}
void Time::setSecond(int s)
{
	if (s >= 1 && s <= 59)
		second = s;
}
Time & Time::operator= (const Time & ref)
{
	second = ref.second;
	minute = ref.minute;
	hour = ref.hour;
	return *this;
}
void Time::setTime(int s, int m, int h)
{
	setSecond(s);
	setMinute(m);
	setHour(h);
}
int Time::getHour()
{
	return hour;
}
int Time::getMinute()
{
	return minute;
}
int Time::getSecond()
{
	return second;
}
void Time::printTwentyFourHourFormat()
{
	cout << "\n" << getHour() << ":" << getMinute() << ":" << getSecond();
}
void Time::printTwelveHourFormat()
{
	if (getHour()>12)
	{
		int hour = getHour() - 12;
		cout << "\n" << hour << ":" << getMinute() << ":" << getSecond();
		cout << " p.m\n";
	}
	else
	{
		cout << "\n" << getHour() << ":" << getMinute() << ":" << getSecond();
		cout << " a.m\n";
	}
}
void Time::incMin(int m)
{
	if ((getMinute() + m) <= 59)
	{
		minute = minute + m;
	}
	else
	{
		int min = minute + m;
		minute = min % 60;
		incHour(min / 60);
	}
}
void Time::incHour(int h)
{
	if ((getHour() + h) <= 59)
	{
		hour = hour + h;
	}
	else
	{
		int hor = hour + h;
		hour = hor % 60;
	}
}
void Time::incSec(int s)
{
	if ((getSecond() + s) <= 59)
	{
		second = second + s;
	}
	else
	{
		int sec = second + s;
		second = (sec) % 60;
		incMin(sec / 60);
	}
}
void Time::getCurrentTime(int &h, int &m, int &s)
{
	CTime t = CTime::GetCurrentTime();
	h = t.GetHour();
	m = t.GetMinute();
	s = t.GetSecond();
}