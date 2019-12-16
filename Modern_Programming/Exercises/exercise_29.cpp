/* Exercise : 28
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>
#include <complex>

using namespace std;

template <int N>
class ZmodnZ{
private:
	int n;
public:
	int value;
	ZmodnZ(int x = 0){
		value = x % N;
	}

	int getValue(){
		return value;
	}

	void setValue(int n){
		this->value = n;
	}

	ZmodnZ operator + (ZmodnZ const &y) { 
		ZmodnZ<N> res(y); 
		res.value = y.value + this->value;
		res.value = res.value % N;
		return res; 
    }

    ZmodnZ operator * (ZmodnZ const &y) { 
		ZmodnZ<N> res(y); 
		res.value = y.value * this->value;
		res.value = res.value % N;
		return res; 
    }

    ZmodnZ operator ++ () {
    	++this->value;
		this->value = this->value % N;
		return *this; 
    } 

    ZmodnZ operator ++ (int){
		this->value = this->value % N;
    	this->value++;
		return *this; 
    } 

	friend ostream &operator<<( ostream &output, const ZmodnZ &x ) { 
		output << x.value;
		return output;
	}

	friend istream &operator>>( istream  &input, ZmodnZ &x ) {
		int in;
		input >> in;
		x.value = in;
		return input;            
	}
};

int main(){
	ZmodnZ<3> x(12);
	ZmodnZ<3> y(34);
	ZmodnZ<3> z(45);

  	cout << "x : " << x << endl;
  	cout << "y : " << y << endl;
  	cout << "x * y : " << x * y << endl;
  	cout << "++x : " << ++x << endl;
  	cout << "++y : " << y++ << endl;
  	
  	cout << "Enter the value of z : ";
  	cin >> z ;
  	cout << "z : " << z.getValue() << endl;
  	
}
