// averager
// author:  Holger Arndt
// version: 13.11.2019
// framework for sheet 6, exercise 18

#include <iostream>

using namespace std;

class Averager{
public:
	Averager nextElement(double element);
	double getAverage();

private:
	double total;
	double total_elements;
};

Averager Averager::nextElement(double element){
	this->total = this->total + element;
	this->total_elements = this->total_elements + 1;
	return (*this);
}

double Averager::getAverage(){
	cout << "Total :" << total << endl;
	return total / total_elements;
}

int main()
{
  Averager a;
  a.nextElement(2).nextElement(3).nextElement(5);
  cout << "average = " << a.getAverage() << endl; // -> 3.33333
  a.nextElement(12);
  cout << "average = " << a.getAverage() << endl; // -> 5.5
}
