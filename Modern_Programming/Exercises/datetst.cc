/* Exercise : 26
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>
#include <iomanip>
#include "dates.h"

using namespace std;
using namespace dates;

ostream& operator<<(ostream& os, const Date& d)
{
  os << setw(2) << setfill('0') << d.getDay() << '.'
     << setw(2) << d.getMonth() << '.'
     << d.getYear() << setfill(' ');
  return os;
}

istream& operator>>(istream& is, Date& d)
{
  int dd, mm, yy;
  is >> dd;
  is.ignore(1, '.');
  is >> mm;
  is.ignore(1, '.');
  is >> yy;
  d.setDate(dd, mm, yy);
  return is;
}

int main()
{
  Date d;

  cout << "Enter a date: ";
  cin >> d;
  cout << d << endl;
}
