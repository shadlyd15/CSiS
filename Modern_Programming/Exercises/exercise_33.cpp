/* Exercise : 33
 * ID       : 1943290
 * Name     : Shadly Salahuddin
 */

#include <list> 
#include <iterator>
#include <iostream>
#include <stdexcept>

using namespace std;

class Paper;
class Journal;

class Literature{
public:
    Literature(){
        this->title.clear();
    }

    std::string getTitle(){
        return this->title;
    }
protected:
    std::string title;
};

class Paper : public Literature{
public:
    Paper(std::string title, std::string author){
        this->title = title;
        this->author = author;
        this->journal = nullptr;
    }

    bool publishedIn(Journal &journal);
    friend ostream &operator<<(ostream &output, const Paper &paper);

private:
    std::string author;
    Journal * journal;
};

class Journal : public Literature{
public:
    Journal(std::string title, int volume){
        this->volume = volume;
        this->title = title;
    }

    void publish(Paper &p);
    void addToTOC(Paper &p);
    void printTOC();

    friend ostream &operator<<(ostream &output, const Journal &journal);

private:
    int volume;
    list<Paper> paperList;
};

bool Paper::publishedIn(Journal &journal){
    bool ret = false;
    if(!this->journal){
        this->journal = &journal;
        journal.addToTOC(*this);
        ret = true;
    } else{
        cout << "This paper already published in : " << this->journal->getTitle() << endl;
        throw "Already published in a journal";
        ret = false;
    }
    return ret;
}

void Journal::publish(Paper &p){
    try{p.publishedIn(*this);}
    catch(const char * c){cout << c << endl;}
}

void Journal::addToTOC(Paper &p){
    if(&p){
        this->paperList.push_back(p);
    }
}

void Journal::printTOC(){
    int index = 0;
    cout << "Table of Content" << " ( Title : " << this->title << ", Volume : " << this->volume << " )" << endl;
    for(Paper paper : this->paperList){
        cout << "[" << ++index << "] :: " << paper << endl;
    }
}


ostream &operator<<(ostream &output, const Paper &paper){
    output << "[Paper] Title : " << paper.title << ", Author : " << paper.author << ", Journal : " << (paper.journal?paper.journal->getTitle():"Not published in any journal yet");
    return output;       
}

ostream &operator<<(ostream &output, const Journal &journal){
    output << "[ Journal ] :: Title : " << journal.title << ", Volume : " << journal.volume;
    return output;       
}

int main() {
    Journal myJournal("Nature", 10);
    Paper myFirstPaper("How to submit assignment", "Shadly Salahuddin");
    Paper mySecondPaper("How to pass in exam", "Shadly Salahuddin");
    myFirstPaper.publishedIn(myJournal);
    myJournal.publish(mySecondPaper);
    try{myFirstPaper.publishedIn(myJournal);}
    catch(const char * c){cout << c << endl;}

    myJournal.printTOC();
    return 0;
} 