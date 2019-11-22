// averager
// author:  Holger Arndt
// version: 13.11.2019
// framework for sheet 6, exercise 18

#include <iostream>

using namespace std;

class Averager{
public:
	Averager();
	~Averager();
	int next_element;
	
};

int main()
{
  Averager a;
  a.nextElement(2).nextElement(3).nextElement(5);
  cout << "average = " << a.getAverage() << endl; // -> 3.33333
  a.nextElement(12);
  cout << "average = " << a.getAverage() << endl; // -> 5.5
}
