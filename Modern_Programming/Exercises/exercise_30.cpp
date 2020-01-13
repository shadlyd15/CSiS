/* Exercise : 30
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <list> 
#include <tuple>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]){
    list<tuple<int, int, int>> triangle; 
    std::list<int> l = { 7, 5, 16, 8 };  
    // Add an integer to the front of the list
    l.push_front(25);
    // Add an integer to the back of the list
    l.push_back(13);
 
    // // Insert an integer before 16 by searching
    // auto it = std::find(l.begin(), l.end(), 16);
    // if (it != l.end()) {
    //     l.insert(it, 42);
    // }
 
    // Iterate and print values of the list
    for (int n : l) {
        std::cout << n << '\n';
    }
	return 0;
}