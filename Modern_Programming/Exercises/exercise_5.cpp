/* Exercise : 5
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    for (int i = 1; i < 20; ++i) {
        if(i&1) {
        	cout << setw(i) << setfill('*') << "" << endl;
        }
    }
    return 0;
}