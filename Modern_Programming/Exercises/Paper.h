#ifndef PAPER_H
#define PAPER_H

#include <list> 
#include <iterator>
#include <iostream>
#include "Literature.h"
#include "Journal.h"


using namespace std;

class Paper : public Literature{
public:
    Paper(std::string title, std::string author){
        this->title = title;
        this->author = author;
        this->journal = nullptr;
    }

    bool publishedIn(Journal * journal){
        bool ret = false;
        if(!this->journal){
            this->journal = journal;
            ret = true;
        } else{
            throw "Already published in a journal";
            ret = false;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &output, const Paper &paper){
        output << "Title : " << paper.title << ", Author : " << paper.author << ", Published In : " << paper.journal->title; //(paper.journal?paper.journal->title:"Not Published Yet");
        return output;       
    }

private:
    std::string author;
    Journal * journal;
};

#endif // PAPER_H