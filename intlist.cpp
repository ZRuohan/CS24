// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;
    Node* curtarget = source.head;
    while(curtarget){
      push_back(curtarget->info);
      curtarget = curtarget->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    while(curr){
      Node* nx = curr->next;
      delete curr;
      curr = nx;

    }
    head = nullptr;
    tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int res = 0;
    Node* curr = head;
    while(curr){
      res += curr->info;
      curr = curr->next;
    }
    return res;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr =head;
    while(curr){
      if(curr->info == value){
        return true;
      }
      curr = curr->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(head){
      int max = head->info;
      Node* curr = head;
      while(curr){
        if(curr->info > max){
          max = curr->info;
        }
        curr = curr->next;
      }
      return max;
    }
    return 0;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
  if(head){ return (double) sum()/count();
  }
  return 0.0;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
  Node* topushb = new Node;
  topushb->info = value;
  topushb->next = head;
  if(!tail){

    tail = topushb;
  }
  head= topushb;
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMEN
    Node* topushb = new Node;
    topushb->info = value;
    topushb->next = nullptr;
    if(!head){
      head = topushb;
      tail = topushb;
    } else {
      tail->next = topushb;
      tail = topushb;
    }

}

// return count of values
int IntList::count() const {
   int c = 0;
   Node* curr = head;
   while(curr){
     c = c+1;
     curr = curr->next;
   }
   return c;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if(this == &source){ return *this;}





    Node* opt = head;
    while(opt){
      Node* nxt = opt->next;
      delete opt;
      opt = nxt;
    }
    head = nullptr;
    tail = nullptr;


        Node* curtarget = source.head;
        while(curtarget){
          push_back(curtarget->info);
          curtarget = curtarget->next;
        }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}
