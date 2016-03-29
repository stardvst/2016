#ifndef FLIGHT_H
#define FLIGHT_H

#include "Time.h"
#include <string>
using std::string;

enum FlightStatus 
		{ PARKED, TAXIING, WAITING_TO_TAKE_OFF, TAKING_OFF, CLIMBING,
			AT_THE_GATE, PREPARING_TO_TAKE_OFF, PREPARING_TO_LAND_OFF, 
			CHANGING_ALTITUDE };

class Flight {
public:
	Flight(FlightStatus, string, string, string, double, double,
		string, double, Time, Time, const char *, const char *);
	void changeAltitude(double);
	void reduceSpeed(double);
	void beginLandingApproach();
	string toString();
private:
	FlightStatus status;
	string airline;
	string flightNumber;
	string model;
	double currentAirSpeed;
	double currentAltitude;
	string direction;
	double carrier;
	Time departureTime;
	Time EstimatedArrivalTime;
	const char *origin;
	const char *destination;
};

#endif // !FLIGHT_H
