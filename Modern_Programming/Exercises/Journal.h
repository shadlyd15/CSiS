#ifndef JOURNAL_H
#define JOURNAL_H


#include <list> 
#include <iterator>
#include <iostream>
#include "Literature.h"
#include "Paper.h"

using namespace std;

class Journal : public Literature{
public:
    Journal(std::string title){
        this->title = title;
    }

    void publish(Paper &p){
        try{
            if(p.publishedIn(this)){
                this->paperList.push_back(p);
                this->volume = this->volume + 1;
            }
        } catch(char * c){
            cout << c << endl;
        }
    }

    void printTOC(){
        if(this->paperList.size()){
            for(Paper paper : paperList){
                cout << paper;
            }
        }
    }
private:
    int volume;
    list<Paper> paperList;
};

#endif // JOURNAL_H