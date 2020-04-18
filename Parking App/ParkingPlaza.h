#ifndef PARKINGPLAZA_H
#define PARKINGPLAZA_H

#include "Vehicle.h"
class ParkingPlaza
{
private:
	int noOfFloors;
	int * floorCapacity;
	int VehicalParked;
	int ParkingCapacity;
	Vehicle***data;
public:
	ParkingPlaza(int floor = 5, ...);
	CString parkVehicle(Vehicle *p, bool payment);

};
#endif
