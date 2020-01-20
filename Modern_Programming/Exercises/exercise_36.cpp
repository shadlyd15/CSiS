/* Exercise : 36
 * ID       : 1943290
 * Name     : Shadly Salahuddin
 */

#include <iostream> 
#include <string> 
using namespace std; 

// Component 
class Dish{ 
public: 
	virtual string getDescription() = 0; 
	virtual double getPrice() = 0; 
}; 


class VienneseSchnitzel : public Dish{ 
public: 
	string getDescription(){ 
		return "Viennese Schnitzel"; 
	} 

	double getPrice(){ 
		return 3.5; 
	} 
}; 

class RumpSteak : public Dish{ 
public: 
	string getDescription(){ 
		return "Rump Steak";
	} 

	double getPrice(){ 
		return 4.5; 
	} 
}; 

class Salmon : public Dish{ 
public: 
	string getDescription(){ 
		return "Salmon";
	} 

	double getPrice(){ 
		return 3.8; 
	} 
}; 

class Accompaniment: public Dish { 
protected: 
	Dish *m_Dish; 
public: 

	Accompaniment(Dish * dish): m_Dish(dish){} 
	string getDescription(){ 
		return m_Dish->getDescription(); 
	} 
	double getPrice(){ 
		return m_Dish->getPrice(); 
	} 
}; 

class Chips: public Accompaniment{ 
public: 
	Chips(Dish * dish): Accompaniment(dish){}
	string getDescription(){ 
		return m_Dish->getDescription() + ", Chips"; 
	} 
	double getPrice(){ 
		return m_Dish->getPrice() + 0.8; 
	} 
}; 

class Salad: public Accompaniment{ 
public: 
	Salad(Dish * dish): Accompaniment(dish){}
	string getDescription(){ 
		return m_Dish->getDescription() + ", Salad"; 
	} 
	double getPrice(){ 
		return m_Dish->getPrice() + 1.10; 
	} 
}; 

class Pasta: public Accompaniment{ 
public: 
	Pasta(Dish * dish): Accompaniment(dish){}
	string getDescription(){ 
		return m_Dish->getDescription() + ", Pasta"; 
	} 
	double getPrice(){ 
		return m_Dish->getPrice() + 1.55; 
	} 
}; 

class Soup: public Accompaniment{ 
public: 
	Soup(Dish * dish): Accompaniment(dish){}
	string getDescription(){ 
		return m_Dish->getDescription() + ", Soup"; 
	} 
	double getPrice(){ 
		return m_Dish->getPrice() + 2.15; 
	} 
}; 

int main() { 
	Dish *item1 = new VienneseSchnitzel();
	cout << "Item 1 : " << item1->getDescription() << endl; 
	cout << "Price : " << item1->getPrice() << " Euro" << endl;

	Dish *item2 = new Chips(item1);
	cout << "Item 2 : " << item2->getDescription() << endl; 
	cout << "Price : " << item2->getPrice() << " Euro" << endl;

	Dish *item3 = new Salad(item1);
	cout << "Item 3 : " << item3->getDescription() << endl; 
	cout << "Price : " << item3->getPrice() << " Euro" << endl;

	Dish *item4 = new Chips(item3);
	cout << "Item 4 : " << item4->getDescription() << endl; 
	cout << "Price : " << item4->getPrice() << " Euro" << endl;

	Dish *item5 = new RumpSteak();
	cout << "Item 5 : " << item5->getDescription() << endl; 
	cout << "Price : " << item5->getPrice() << " Euro" << endl;

	Dish *item6 = new Salad(item5);
	cout << "Item 6 : " << item6->getDescription() << endl; 
	cout << "Price : " << item6->getPrice() << " Euro" << endl;

	Dish *item7 = new Salmon();
	cout << "Item 7 : " << item7->getDescription() << endl; 
	cout << "Price : " << item7->getPrice() << " Euro" << endl;

	return 0; 
} 
