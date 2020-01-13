/* Exercise : 31
 * ID       : 1943290
 * Name     : Shadly Salahuddin
 */

#include <list> 
#include <iterator>
#include <iostream> 

using namespace std;

template <typename T>
void print_list(list <T> l){
    for (T n : l) {
        std::cout << n << ' ';
    }
    std::cout << endl;
}

template <typename T>
void bubble_sort(list <T> &numbers){
    if(!(&numbers)) return;
    bool swapped = false;
    typename list <T> :: iterator end = --numbers.end();
    for(typename list <T> :: iterator i = numbers.begin(); i != end; --end){
        swapped = false;
        for(typename list <T> :: iterator current = i; current != end; current++){
            typename list <T> :: iterator next = current; ++next;
            if(*next < *current){
                std::iter_swap(current, next);
                swapped = true;
            }
            if(!swapped) { return; }
        }
    }
}
  
int main() {
    std::list<int> int_list = { 7, 2, 1, 43, 5, 16, 8 };
    cout << "Before Sorting Int List : ";
    print_list(int_list);
    bubble_sort(int_list);    
    cout << "After Sorting Int List : ";
    print_list(int_list);

    std::list<float> float_list = { 7.01, 2.01, 1.01, 43.01, 5.01, 16.01, 8.01 };
    cout << "Before Sorting Float List : ";
    print_list(float_list);
    bubble_sort(float_list);
    cout << "After Sorting Float List : ";
    print_list(float_list);
    return 0;
} 