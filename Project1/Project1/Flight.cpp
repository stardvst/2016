#include <iostream>
#include "Flight.h"

Flight::Flight(FlightStatus stat, string aline, string fnumber, 
	string mod, double alt, double spd, string dir,
	double c, Time departure, Time arrival, const char *orig, const char *dest) 
	: origin(orig), destination(dest) {

	status = stat;
	airline = aline;
	flightNumber = fnumber;
	model = mod;
	currentAltitude = ((alt >= 0) ? alt : 0);
	currentAirSpeed = ((spd >= 0) ? spd : 0);
	direction = dir;
	carrier = c;
	departureTime = departure;
	EstimatedArrivalTime = arrival;
}

void Flight::changeAltitude(double newAltitude) {
	std::cout <<
		"Airplane: " << airline << '\n' <<
		"Flight number: " << flightNumber << '\n' <<
		"Speed: " << currentAirSpeed << " km/h\n" <<
		"Current status: " << this->toString() << '\n' <<
		"New status: " << "CHANGING ALTITUDE\n" <<
		"Current altitude: " << currentAltitude << " feet\n" <<
		"New altitude: ";
	currentAltitude += ((newAltitude >= 0) ? newAltitude : 0);
	std::cout << currentAltitude << " feet\n";
}

void Flight::reduceSpeed(double newSpeed) {
	currentAirSpeed -= newSpeed;
}

string Flight::toString() {
	switch (status) {
	case 0:
		return "PARKED";
		break;
	case 1:
		return "TAXIING";
		break;
	case 2:
		return "WAITING TO TAKE OFF";
		break;
	case 3:
		return "TAKING OFF";
		break;
	case 4:
		return "CLIMBING";
		break;
	case 5:
		return "AT THE GATE";
		break;
	case 6:
		return "PREPARING TO TAKE OFF";
		break;
	case 7:
		return "PREPARING TO LAND OFF";
		break;
	case 8:
		return "CHANGING ALTITUDE";
		break;
	default: return "Wrong input.";
	}
}