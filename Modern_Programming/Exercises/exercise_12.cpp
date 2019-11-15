/* Exercise : 11
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream> 
#include <vector> 
#include <cmath>

using namespace std; 
  
int main(){ 
    double n, sum = 0;
    cout << "Please Enter A Range : ";
    cin >> n;
    
    vector<double> steps; 
  
    for (int i = 0; i < n; i++){
        steps.push_back(1.0 + (1.0 / (pow((1.0 + i), 2)))); 
    }
  
    cout << "Output of begin and end: ";
    auto ptr = steps.begin();
    for (int i = 0; i < n; i++){
        sum = sum + *(ptr++);
    }
  
    cout << "Summation : " << sum << endl;  
    return 0; 
} 

  
