/* Exercise : 8
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>
#include <cstring>

using namespace std;

typedef struct polynominal_units{
	int degree;
	int coefficient;
} polynominal_units_t;

bool derivate(polynominal_units_t * polinominal, int max_degree){
	bool ret_val = false;
	for (int i = 0; i < (max_degree + 1); ++i){
		polynominal_units_t * current = polinominal + i;
		if(current){
			current->coefficient = current->coefficient * current->degree;
			current->degree = current->degree - 1;
			ret_val = true;
		}
	}
	return ret_val;
}

bool print_poly(polynominal_units_t * polinominal, int max_degree){
	bool ret_val = false;
	for (int i = (max_degree + 1); i > -1 ; --i){
		polynominal_units_t * current = polinominal + i;
		polynominal_units_t * next = current - 1;
		if(current && current->coefficient){
			cout << current->coefficient;
			if(current->degree){
				cout << "x";
				if(current->degree > 1){
					cout << "^" << current->degree;
				}
			}
			if(next && (next->coefficient > 0 )){
				cout << "+";
			}
			ret_val = true;
		}
	}
	return ret_val;	
}

int main(){
	int n = 0;
	cout << "Please enter the degree n of the polinominal (0 - 10) : ";
	cin >> n;
	polynominal_units_t * polinominal = (polynominal_units_t *)malloc(sizeof(polynominal_units_t) * (n + 2));
	memset(polinominal, 0x00, sizeof(polynominal_units_t) * (n + 2));
	for (int i = n; i > -1; --i){
		polynominal_units_t * current = polinominal + i;
		current->degree = i;
		cout << "coefficient a[" << i << "] : ";
		cin >> current->coefficient;
	}

	int k = 0;
	cout << "Which derivative should be computed? ";
	cin >> k;
	cout << "p";
	for (int i = 0; i < k; ++i){
		cout << "'";
		derivate(polinominal, n);
	}
	cout << "(x) = ";
	print_poly(polinominal, n);
	cout << endl;
	return 0;
}