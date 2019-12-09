/* Exercise : 23
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>
#include <cmath>

using namespace std;

class Vehicle{
public:
	int number_of_seats;
	int year_of_manufacture;

	Vehicle(int a = 0, int b = 0) 
		: year_of_manufacture(a), number_of_seats(b){
	}

	friend ostream &operator<<( ostream &output, const Vehicle &vehicle ){
		output << "Year of manufacture : " << vehicle.year_of_manufacture << endl;
		output << "Number of seats : " << vehicle.number_of_seats << endl;
		return output;            
	}
};

class MotorVehicle : public Vehicle {
public:
    string licence_plate_number;
    string engine_power;
 
    MotorVehicle(int number_of_seats, int year_of_manufacture, string licence_plate_number, string engine_power)
       : Vehicle{ number_of_seats, year_of_manufacture }, licence_plate_number(licence_plate_number), engine_power(engine_power){
    }

	friend ostream &operator<<( ostream &output, const MotorVehicle &motorVehicle ){
		output << static_cast<Vehicle>(motorVehicle);
		output << "Licence Plate Number : " << motorVehicle.licence_plate_number << endl;
		output << "Engine Power : " << motorVehicle.engine_power << endl;
		return output;            
	}
};

enum class usage_e { Private, Company, Car, Taxi };

class Car : public MotorVehicle {
public:
	usage_e usage;
    Car(int number_of_seats, int year_of_manufacture, string licence_plate_number, string engine_power, usage_e usage)
       : MotorVehicle{ number_of_seats, year_of_manufacture, licence_plate_number, engine_power }, usage(usage){
    }

	friend ostream &operator<<( ostream &output, const Car &car ){
		output << "** Car **" << endl;
		output << static_cast<MotorVehicle>(car);
		output << "Usage : ";
		switch(car.usage){
	        case usage_e::Private   : output << "Private";  	break;
	        case usage_e::Company	: output << "Company"; 		break;
	        case usage_e::Car 		: output << "Car";  		break;
	        case usage_e::Taxi  	: output << "Taxi";   		break;
	        default    				: output << "Undefined";	break;
	    }
	    output << endl;
		return output;            
	}
};

class Bus : public MotorVehicle {
public:
	int max_standing_passengers;
    Bus(int number_of_seats, int year_of_manufacture, string licence_plate_number, string engine_power, int max_standing_passengers)
       : MotorVehicle{ number_of_seats, year_of_manufacture, licence_plate_number, engine_power }, max_standing_passengers(max_standing_passengers){
    }

	friend ostream &operator<<( ostream &output, const Bus &bus ){
		output << "** Bus **" << endl;
		output << static_cast<MotorVehicle>(bus);
		output << "Max Standing Passengers : " << bus.max_standing_passengers << endl;
		return output;            
	}
};

class Train : public Vehicle {
public:
    int number_of_coaches;
    string track_gauge;
 
    Train(int number_of_seats, int year_of_manufacture, int number_of_coaches, string track_gauge)
       : Vehicle{ number_of_seats, year_of_manufacture }, number_of_coaches(number_of_coaches), track_gauge(track_gauge){
    }

	friend ostream &operator<<( ostream &output, const Train &train ){
		output << "** Train **" << endl;
		output << static_cast<Vehicle>(train);
		output << "Number of coaches : " << train.number_of_coaches << endl;
		output << "Track Gauge : " << train.track_gauge << endl;
		return output;            
	}
};

int main(int argc, char const *argv[]){
	Train train(2009, 300, 5, "Broad Gauge");
	Bus bus(2016, 60, "ABCD15", "Diesel", 10);
	Car car(2018, 4, "EADGBE", "Electric", usage_e::Private);
	cout << train << endl;
	cout << bus << endl;
	cout << car << endl;
	return 0;
}