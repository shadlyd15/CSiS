/* Exercise : 20
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>

using namespace std;

class Duration{

public:
	Duration(int hours = 0, int minutes = 0, double seconds = 0){
		this->set(hours, minutes, seconds);
		this->correctTime();
	}
	void set(int h, int m, double s){
		this->hours = h;
		this->minutes = m;
		this->seconds = s;
	}
	double getAsHours();
	double getAsSeconds();
	void print(){
		cout << "Hours : " << this->hours << ", Minutes : " << this->minutes << ", Seconds : " << this->seconds << endl;
	}

private:
	int hours;
	int minutes;
	double seconds;
	void correctTime(){
		Duration * offset = new Duration(0, 0, 0);

		this->seconds = (int)this->seconds % 60;
		offset->seconds = (int)this->seconds % 60;
		offset->minutes = ((int)(this->seconds/60) + this->minutes) % 60;
		offset->hours = ((int)(this->minutes/60) + this->hours) % 24;

		this->hours = ((int)(this->minutes/60) + this->hours) % 24;
		this->minutes = ((int)(this->seconds/60) + this->minutes) % 60;

		delete duration;
	}
};

int main(int argc, char const *argv[]){
	Duration * duration = new Duration(0, 0, 97565);
	duration->print();


	delete duration;
	return 0;
}