/* Exercise : 34
 * ID       : 1943290
 * Name     : Shadly Salahuddin
 */

#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <float.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MAX_ERROR     (10E-14)
#define MAX_ITERATION (100)

using namespace std;

class Polynomial{
private:
  vector<double> coeffs;
public:
  Polynomial(){
    coeffs.clear(); // empty vector of coefficients
  }

  Polynomial(double c0){
    coeffs.push_back(c0);
    /*
    Polynomial(double c0) : creates the polynomial p(x) = x + c0
    Somme says, we should assume p(x) = c0.
    But if we put p(x) = c0, it becomes 0 = c0. Which is not true.
    So assuming that the question is correct :: p(x) = x + c0
    */
    coeffs.push_back(1);
  }

  Polynomial(int d, double* c){
    for (int i = 0; i < (d + 1); i++){
        coeffs.push_back(c[i]);
    }
  }

  template <unsigned long N> Polynomial(const array<double, N> &c){
    for (auto coeff : c){
        coeffs.push_back(coeff);
    }
  }
  
  int degree() const{
    if(!coeffs.size()) return coeffs.size();
    if((coeffs[coeffs.size() - 1] != 0)) return (coeffs.size() - 1);
    return 0;
  }

  double operator()(double x) const{
      double retVal = 0;
      if(this->degree()){
        for(int i = (int)this->degree(); i > -1; i--)  {
          retVal = retVal * x + this->coeffs[i];
        }
    }
      return retVal;
  }

  void printPoly(Polynomial &polynomial){
    for (int i = 0; i < polynomial.coeffs.size(); i++) 
    cout << polynomial.coeffs[i] << " "; 
  }

    Polynomial deriv() const {
        int deg = this->degree() - 1;
        double c[deg + 1]{};
        
        auto it{coeffs.crbegin()};
        for (int i = coeffs.size() - 1; i >= 0; ++it, --i){
            double val= i*(*it);
            c[i-1]=val;
        }
          
        Polynomial p( deg, c ); 
        return p;
    }

  friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2){
    Polynomial p;
    int p1Size = p1.degree();
    int p2Size = p2.degree();
    int largest = MAX(p1Size, p2Size);

    for (int i = 0; i < largest + 1; i++){
        p.coeffs.push_back(p1.coeffs[i] + p2.coeffs[i]);
    }
    return p;
  }

  friend Polynomial operator*(const Polynomial& p1, const Polynomial& p2){
    int p1Size = p1.degree();
    int p2Size = p2.degree();

    if(!p1Size || !p2Size) {
        Polynomial p0;
        // p0.coeffs.push_back(p1.coeffs[0] * p2.coeffs[0]);
        return p0;
    }

    double c[p1Size + p2Size + 2]{};
    if(c){
        int index = 0;
        for (int i = 0; i < p1Size + 1; i++){
            for (int j = 0; j < p2Size + 1; j++){
                c[i + j] =  (p1.coeffs[i] * p2.coeffs[j]) + c[i + j];
            }
        }
    }
    Polynomial p(p1Size + p2Size, c);
    return p;
  }

  friend ostream& operator<<(ostream& os, const Polynomial& p);
};

string asExponent(int i){
  string res;
  string expTab[] = { string{"⁰"}, string{"¹"}, string{"²"}, string{"³"},
                      string{"⁴"}, string{"⁵"}, string{"⁶"}, string{"⁷"},
                      string{"⁸"}, string{"⁹"} };
  while (i != 0)
    {
      res.insert(0, expTab[i % 10]);
      i /= 10;
    }
  return res;
}

ostream& operator<<(ostream& os, const Polynomial& p){
  if (p.coeffs.size() > 0)
    {
      auto it{p.coeffs.crbegin()};
      for (int i = p.coeffs.size() - 1; i >= 0; ++it, --i)
        {
          if (i < static_cast<int>(p.coeffs.size()) - 1 && *it > 0)
            os << '+';
          else if (*it < 0)
            os << '-';
          if (*it != 0 && (abs(*it) != 1 || i == 0))
            os << abs(*it);
          if (*it != 0 && i > 0)
            os << 'x';
          if (*it != 0 && i > 1)
            os << asExponent(i);
        }
    }
  else
    os << '0';
  return os;
}

double newton(const Polynomial& p, double x0){
    int n = 0;
    double error = DBL_MAX;
    double root = x0;
    do{
        double prev = root;
        root = prev - ((double)p(prev)/p.deriv()(prev));
        error = abs(prev - root);
        n++;
    } while((n < MAX_ITERATION) && (error > MAX_ERROR));
    if(error > MAX_ERROR) throw( std::string("Could Not Find a Root") );
    return root;
}

int main(){
  // a)
  
    Polynomial p0;
    cout << "p0(x) = " << p0 << endl;
    double p1coeff[]{ 2, -3, -5, 4 };
    Polynomial p1{3, p1coeff};
    cout << "p1(x) = " << p1 << endl;
    cout << "deg(p1) = " << p1.degree() << endl;
    Polynomial p1a{array<double, 4>{ 2, -3, -5, 4 }};
    cout << "p1a(x) = " << p1a << endl;
    double p2coeff[]{ 1, 1, 1 };
    Polynomial p2(2, p2coeff);
    cout << "p2(x) = " << p2 << endl;
    double p3coeff[]{ -1, -1, -1 };
    Polynomial p3(2, p3coeff);
    cout << "p3(x) = " << p3 << endl;
    double p4coeff[]{ 0, 0, 1 };
    Polynomial p4(2, p4coeff);
    cout << "p4(x) = " << p4 << endl;
    double p5coeff[]{ 1, 0, 0 };
    Polynomial p5(2, p5coeff);
    cout << "p5(x) = " << p5 << endl;
    Polynomial p6{1};
    cout << "p6(x) = " << p6 << endl;
    Polynomial p7{-2};
    cout << "p7(x) = " << p7 << endl;
  

  // b)
  
    cout << "p1(x) + p1(x) = " << p1 + p1 << endl;
    cout << "p1(x) + p2(x) = " << p1 + p2 << endl;
    cout << "p2(x) + p1(x) = " << p2 + p1 << endl;
    cout << "p4(x) + p3(x) = " << p4 + p3 << endl;
    cout << "p6(x) * p7(x) = " << p6 * p7 << endl;
    cout << "p1(x) * p1(x) = " << p1 * p1 << endl;
    cout << "p1(x) * p4⁵(x) = " << p1 * (p4 * p4 * p4 * p4 * p4) << endl;
    cout << "p1(x) * p0(x) = " << p1 * p0 << endl;
  

  // c)
  
    cout << "p2(1) = " << p2(1) << endl;
    cout << "p1(-2) = " << p1(-2) << endl;
  

  // d)
  
    cout << "p0'(x) = " << p0.deriv() << endl;
    cout << "p1'(x) = " << p1.deriv() << endl;
  

  // e)
  
    cout << "newton(p6 * p7, 0) = " << newton(p6 * p7, 0) << endl;
    cout << "newton(p6 * p7, 1) = " << newton(p6 * p7, 1) << endl;
    double x0;
    cout << "x0 = newton(p1, 2) = " << (x0 = newton(p1, 2)) << endl;
    cout << "p1(x0) = " << p1(x0) << endl;
    try { x0 = newton(p3, 2); }
    catch (const string& msg)
    { cout << "Caught for newton(p3, 2): " << msg << endl; }
}
