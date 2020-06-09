/*
 * InorderLinkedList.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: haytham
 */

#include "inord_list.h"
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cstring>


using namespace std;

InorderLinkedList::InorderLinkedList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}
bool InorderLinkedList::insert(const ListElemType& item, int &line_num)
{
    Link addedNode = new Node;
    addedNode->linenum = line_num;
    Link pred;
    if (addedNode == NULL) {
        return false; // allocation failed
    }
    else {
        addedNode->element = item;
        if (head == NULL || item < head->element) {
            addedNode->next = head;
            head = addedNode;
            return true;
        }
        else {
            pred = head;
            while (pred->next != NULL && pred->next->element <= item) {
                pred = pred->next;
            }
            addedNode->next = pred->next;
            pred->next = addedNode;
            return true;
        }
    }

}

bool InorderLinkedList::first(ListElemType& item)
{
    if (head == NULL) {
        // check if the list is empty
        return false;
    }
    else {
        current = head;
        item = current->element;
        return true;
    }
}

bool InorderLinkedList::next(ListElemType& item)
{
    if (current == NULL || current->next == NULL) {
        // check if first has been called at least once
        // check if end of the list is reached
        return false;
    }
    else {
        current = current->next;
        item = current->element;
        return true;
    }
}

/*int InorderLinkedList::charCount()
{
    int charcount = 0;
    string wordchar;
    Link pred;
    pred = head;
    while(pred != NULL )
    {   wordchar = pred->element;
        charcount = charcount + wordchar.size();
        pred = pred->next;
    }
    return charcount;
}
*/
int InorderLinkedList::countWord(ListElemType &item)
{
    Link pred;
    int count = 0;
    pred = head;
    for(int i = 0; i < item.length(); i++)
    {
        item[i] = tolower(item[i]);
    }
    while (pred != NULL)
    {
        if (pred->element == item)
        {
            count++;
            pred = pred->next;
        }
        else
        {
            pred = pred->next;
        }
    }
    return count;
}

int InorderLinkedList::distWords()
{
    Link pred;
    int count = 0;
    pred = head;
    while(pred != NULL && pred->next != NULL)
    {
        if(pred->element != pred->next->element)
        {
         count++;
        }
        else
            {
                NULL;
            }
        pred = pred->next;
    }
    return count+1;
}


void InorderLinkedList::starting(ListElemType &item)
{   int flag = 0;
    int j = 0;
    int startcount = 0;
    Link pred;
    pred = head;
    for(int i = 0; i < item.length(); i++)
    {
        item[i] = tolower(item[i]);
    }
    while(pred != NULL)
    {
        flag = 0;
        if(pred->element.find(item) == 0)
        {
           flag++;
        }
        else
        {
                NULL;
        }
        if(flag > 0)
        {
            j++;
            startcount = 1;
            while (pred->next != NULL && (pred->element).compare(pred->next->element) == 0)
            {
                startcount = startcount + 1;
                pred = pred->next;
                if(pred->next == NULL)
                    break;
            }
            cout<<pred->element<<": "<<startcount<<" ";
        }
        if(pred->next == NULL)
        {
            break;
        }
        else
        {
            pred = pred->next;
        }

    }
    if (j == 0)
    {
        cout<<"Word not found"<<endl;
    }
    else cout<<endl;
}
void InorderLinkedList::containing(ListElemType &item)
{
    int flag = 0;
    int j = 0;
    int startcount = 0;
    Link pred;
    pred = head;
    for(int i = 0; i < item.length(); i++)
    {
        item[i] = tolower(item[i]);
    }
    while(pred != NULL)
    {
        flag = 0;
        if((pred->element.find(item)) + 1)
        {
           flag++;
        }
        else
        {
                NULL;
        }
        if(flag > 0)
        {
            j++;
            startcount = 1;
            while (pred->next != NULL && (pred->element).compare(pred->next->element) == 0)
            {
                startcount = startcount + 1;
                pred = pred->next;
                if(pred->next == NULL)
                    break;
            }
            cout<<pred->element<<": "<<startcount<<" ";
        }
        if(pred->next == NULL)
        {
            break;
        }
        else
        {
            pred = pred->next;
        }

    }
if (j == 0)
    {
        cout<<"Word not found"<<endl;
    }
    else cout<<endl;
}

void InorderLinkedList::Search(ListElemType &item, int &lineCount)
{
   int line = lineCount;
Link pred=head;
int j=0;
string word;
int num;
for (int i = 0; i < item.length(); i++){
item[i] = tolower(item[i]);
}
while(pred!=NULL){
word=pred->element;
int k=0;
if( ((pred->element).find(item))+1)
 {
        k=1;
}

if (k==1) { j++;
num=pred->linenum;
cout<<pred->element<<": "<<"lines"<<" "<<(num) << " ";

 while (word.compare(pred->next->element) == 0){
 if (num!= pred->next->linenum){
 cout << ((pred->next->linenum)) << " ";
   }
 pred = pred->next;
}
cout << endl;              }

pred = pred->next; }
if(j==0) {
        cout<<"Word not found"<<endl;}
   }
void InorderLinkedList::frequentWord()
{
   Link pred;
   ListElemType word1;
   int compare;
   pred = head;
   int MAX;
   while(pred != NULL)
   {
       compare = countWord(pred->element);
       if (compare > MAX)
       {
          MAX = compare;
          word1 = pred->element;
       }
       pred = pred->next;
   }
   cout<<"Most frequent word is: "<<word1;
   cout<<endl;
}
