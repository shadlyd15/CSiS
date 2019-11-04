/* Exercise : 7
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
	int iterations = 0;
	cout << "Enter the number of iteration : ";
	cin >> iterations;
	int in_circle_count = 0;

	for (int i = 0; i < iterations; ++i){
		double x = ((double) rand() / (RAND_MAX));
		double y = ((double) rand() / (RAND_MAX));
		if((pow(x, 2) + pow(y, 2)) <= 1){
			in_circle_count++;
		}
	}

	cout << "Approximation of PI : " << ((double)in_circle_count/iterations) * 4 << endl;
}

