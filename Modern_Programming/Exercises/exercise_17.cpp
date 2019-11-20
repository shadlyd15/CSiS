/* Exercise : 17
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

#define BUFFER_SIZE		128

class Book{
	public:
		Book(char * title, char * author);
		~Book();

		bool borrowed(char * borrower);
		void returned();
		void print();

	private:
		char title[BUFFER_SIZE];
		char author[BUFFER_SIZE];
		char borrower[BUFFER_SIZE];
};

Book::Book(char * title, char * author){
	if(title && author){
		strncpy(this->title, title, strlen(title));
		strncpy(this->author, author, strlen(author));
		memset(this->borrower, 0x00, strlen(this->borrower));
	}
}

Book::~Book(){
	memset(this->title, 0x00, strlen(this->title));
	memset(this->author, 0x00, strlen(this->author));
	memset(this->borrower, 0x00, strlen(this->borrower));
}

bool Book::borrowed(char * borrower){
	bool ret_val = 0;
	if(borrower){
		strncpy(this->borrower, borrower, strlen(borrower));
		ret_val = true;
	}
	return ret_val;
}

void Book::returned(){
	memset(this->borrower, 0x00, strlen(this->borrower));
}

void Book::print(){
	cout << "Title :\t" << this->title << ",\t" << "Author :\t" << this->author << ",\t" << "Status :\t";
	if(strlen(this->borrower)) cout << "Not Available" << endl;
	else cout << "Available" << endl;
}

int main(){
	Book * test_book = new Book("The Alchemist", "Paulo Coelho");
	test_book->print();
	test_book->borrowed("Shadly");
	test_book->print();
	test_book->returned();
	test_book->print();
	delete test_book;
}

