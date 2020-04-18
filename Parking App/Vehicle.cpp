#include"Vehicle.h"


Vehicle::Vehicle():number(),dateIn(),timeIn()
{
}
Vehicle::Vehicle(myCString n, Date d, Time t):dateIn(d),timeIn(t)
{
	if (n.getLength() != 0)
		number = n;
}
void Vehicle::setNumber(myCString n)
{
	if (n.getLength() != 0)
		number = n;
}
void Vehicle::setDate(Date d)
{
	d.setDate(d.getDay(),d.getMonth(),d.getYear());	
	dateIn = d;
}
void Vehicle::setTime(Time t)
{
	t.setTime(t.getSecond(), t.getMinute(), t.getHour());
	timeIn = t;
}
myCString Vehicle::getNumber()const
{
	return number;
}
Date Vehicle::getDate()const
{
	return dateIn;
}
Time Vehicle::getTime()const
{
	return timeIn;
}
float Vehicle::calcVehicleFare()
{
	return 0.0;
}
