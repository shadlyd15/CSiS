/* Exercise : 9
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>

using namespace std;

int main(){
	double iterations = 0;
	cout << "Enter the number of iteration : ";
	cin >> iterations;
	srand(time(NULL));

	double g = 100;
	double number_of_points = 0;
	double points_in_circle = 0;
	double step_size = 1 / g;
	cout << "Step Size : " << step_size << endl;

	for (double i = 0; i < g; i++){
		for (double j = 0; j < g; j++){
			double bottom_left_x = i * step_size;
			double bottom_left_y = j * step_size;
			double top_right_x = (i + 1) * step_size;
			double top_right_y = (j + 1) * step_size;

			if((pow(bottom_left_x, 2) + pow(bottom_left_y, 2) <= 1)  && (pow(top_right_x, 2) + pow(top_right_y, 2) > 1)){
				float rand_point_x = bottom_left_x + (float)rand()/(float)(RAND_MAX * top_right_x);
				float rand_point_y = bottom_left_y + (float)rand()/(float)(RAND_MAX * top_right_y);

				cout << "rand_point_x : " << rand_point_x << endl;
				cout << "rand_point_y : " << rand_point_y << endl;

				number_of_points = number_of_points + 1;
				for (double k = 0; k < iterations; k++){
					if(pow(rand_point_x, 2) + pow(rand_point_y, 2) <= 1){
						points_in_circle = points_in_circle + 1;
					}
				}
			}
		}
	}


	cout << "points_in_circle : " << points_in_circle << endl;
	cout << "number_of_points : " << number_of_points << endl;
	cout << "Approximation of PI : " << (points_in_circle/number_of_points) * 4 << endl;
}

