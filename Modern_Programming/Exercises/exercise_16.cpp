/* Exercise : 16
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>
#include <string.h>

using namespace std;

#define BUFFER_SIZE		128

class Car{
public:
	Car(char * type);
	~Car();
	char type[BUFFER_SIZE];
	double mileage;
	void drive(double distance);
	void tow(Car * towed, double distance);
	char * getType();
	double getMilage();
	void print();
	
};

Car::Car(char * type){
	this->mileage = 0;
	memset(this->type, 0x00, BUFFER_SIZE);
	memcpy(this->type, type, strlen(type));
}

Car::~Car(){

}

void Car::drive(double distance){
	this->mileage = this->mileage + distance;
}

void Car::tow(Car * towed, double distance){
	if(towed){
		this->mileage = this->mileage + distance;
		towed->mileage = towed->mileage + distance;
	}
}

char * Car::getType(){
	return this->type;
}

double Car::getMilage(){
	return this->mileage;
}

void Car::print(){
	cout << "Car Type : " << this->type << ",\tMilage : " << this->mileage << endl;
}

int main(){
	Car * bmw = new Car("BMW");
	Car * tesla = new Car("Tesla");

	bmw->print();
	tesla->print();

	bmw->drive(5);
	tesla->drive(10);

	bmw->print();
	tesla->print();

	tesla->tow(bmw, 5);

	bmw->print();
	tesla->print();
}

