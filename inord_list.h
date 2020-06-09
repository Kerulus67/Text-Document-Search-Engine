/*
 * LinkedList.h
 *
 *  Created on: Mar 15, 2017
 *      Author: haytham
 */

#ifndef INORD_LIST_H_
#define INORD_LIST_H_

#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef string ListElemType;

class InorderLinkedList {
public:
    InorderLinkedList();
    bool insert(const ListElemType& item, int &line_num);
    bool first(ListElemType& item);
    bool next(ListElemType& item);
    int distWords();
    int countWord(ListElemType &item);
    void frequentWord();
    void starting(ListElemType &item);
    void containing(ListElemType &item);
    void Search(ListElemType &item,int &lineCount);
private:
    struct Node; // Forward declaration of structure
    typedef Node* Link;
    struct Node {
        ListElemType element;
        int linenum;
        Link next;
    };
    Link head;
    Link tail;
    Link current;
};

#endif /* INORDERLINKEDLIST_H_ */
