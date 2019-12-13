/* Exercise : 26
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T> 
T power(T x, unsigned int n){
   	if(0 == n) return 1;
	if(n & 1){
		return x*power(x, n - 1);
	} else{
		T a = power(x, n/2);
		return a*a;
	}
}

std::string power(std::string s, unsigned int n) {
	std::string multi;
    for(int i = 0; i < n; i++){
        multi = multi + s;
    }
	return multi;
}

int main(int argc, char const *argv[]){
	std::cout << power(2, 10) << std::endl;
	std::cout << power(12.351, 10) << std::endl;
	std::cout << power(string{"ABC"}, 3) << std::endl;
	return 0;
}