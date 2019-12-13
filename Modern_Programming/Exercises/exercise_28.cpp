/* Exercise : 28
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>
#include <complex>

template <class T> 
class Averager{
	private:
		T total;
		T total_elements;
		
	public:
		Averager():total{0}, total_elements{0}{};
		Averager & nextElement(T element);
		T getAverage();
};

template <class T>
Averager<T> & Averager<T>::nextElement(T element){
	this->total = this->total + element;
	this->total_elements = this->total_elements + (T)1;
	return (*this);
}

template <class T> 
T Averager<T>::getAverage(){
	return total / total_elements;
}

int main(){
  Averager<int> int_test;
  int_test.nextElement(2).nextElement(3).nextElement(5);
  std::cout << "Int Average = " << int_test.getAverage() << std::endl;

  Averager<double> double_test;
  double_test.nextElement(2.678).nextElement(3.678).nextElement(5.678);
  std::cout << "Double Average = " << double_test.getAverage() << std::endl;

  Averager<std::complex<double>> complex_test;
  std::complex<double> x (1.0, 3.0);
  std::complex<double> y (2.0, 2.0);
  std::complex<double> z (3.0, 1.0);
  complex_test.nextElement(x).nextElement(y).nextElement(z);
  std::cout << "Complex Average = " << complex_test.getAverage() << std::endl;
}
