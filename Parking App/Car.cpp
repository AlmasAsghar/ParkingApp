#include "Car.h"


Car::Car(Vehicle & v):Vehicle(v)
{
}
float Car::calcVehicalFare()
{
	CTime t = CTime::GetCurrentTime();
	float fare;
    fare=20*(getTime().getHour()-t.GetHour());
	return fare;
}