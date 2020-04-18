#include "ParkingPlaza.h"

ParkingPlaza::ParkingPlaza(int floor ,...)
{
	if (floor <= 0)
	{
		noOfFloors = 0;
		floorCapacity = 0;
		return;
	}
	noOfFloors = floor;
	floorCapacity = new int[noOfFloors];
	va_list vl;
	va_start(vl , floor);
	for (int i = 0; i < noOfFloors; i++)
		floorCapacity[i] = va_arg(vl, int);
	va_end(vl);
}
CString parkVehicle(Vehicle *p, bool payment)
{

}