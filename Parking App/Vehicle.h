#ifndef VEHICLE_H
#define VEHICLE_H

#include"Date.h"
#include"Time.h"

class Vehicle
{
private:
	myCString number;
	Date dateIn;
	Time timeIn;
public:
	Vehicle();
	Vehicle(myCString,Date,Time);
	void setNumber(myCString );
	void setDate(Date);
	void setTime(Time);
	myCString getNumber()const;
	Date getDate()const;
	Time getTime()const;
	virtual float calcVehicleFare();
};
#endif
