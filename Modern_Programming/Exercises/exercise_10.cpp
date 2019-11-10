/* Exercise : 10
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */
#include <iostream>
#include <cmath>

using namespace std;

typedef struct roots{
	bool is_real;
	double root_1;
	double root_2;
} roots_t;

bool quad(double a, double b, double c, roots_t * roots){
	bool ret_val = false;
	double root_check = (b * b) - (4 * a * c);
	if(root_check >= 0){
		roots->is_real = ret_val = true;
        roots->root_1 = (-b + sqrt(root_check)) / (2 * a);
        roots->root_2 = (-b - sqrt(root_check)) / (2 * a);
	}
	return ret_val;
}

int main() {
	double a, b, c;
    cout << "Please Enter The Coefficients a, b and c : ";
    cin >> a >> b >> c;
    double root_check = b*b - 4*a*c;
    
    roots_t result = {0};
    if(quad(a, b, c, &result)){
    	cout << "Root 1 = " << result.root_1 << " & Root 2 = " << result.root_2 << endl;
    } else{
    	cout << "Roots are complex" << endl;
    }
    return 0;
}