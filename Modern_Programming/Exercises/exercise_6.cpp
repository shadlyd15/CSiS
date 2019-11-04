/* Exercise : 6
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>
#include <iomanip>

using namespace std;

double add(double x, double y){
	return x + y;
}

double substract(double x, double y){
	return x - y;
}

double multiply(double x, double y){
	return x * y;
}

double divide(double x, double y){
	return y ? (x / y) : 0;
}

int main() {
	char operation;
	double x, y;
	cin >> x >> operation >> y;
	switch(operation){
		case '+':{
			cout << add(x, y) << endl;
			break;
		}
		case '-':{
			cout << substract(x, y) << endl;
			break;
		}
		case '*':{
			cout << multiply(x, y) << endl;
			break;
		}
		case '/':{
			if(y){
				cout << divide(x, y) << endl;
			} else{
				cout << "error : division by zero" << endl;
			}
			break;
		}
		default:{
			cout << "error : unknown operator" << endl;
		}
	}
	cout << (2 ^ 2) << endl;
}