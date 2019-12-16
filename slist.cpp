#include "slist.h"

/*
Class Library File
*/
#include <iostream>
#include <fstream>
#include <cmath> 

using namespace std;

#include <iostream>
#include <cstdlib>

// Constructor
// Initialize the lists management information
LinkedList::LinkedList(){
    length = 0; // Your code here
    head = NULL; // Your code here
}

// Destructor
LinkedList::~LinkedList(){
   Node* current = head;
    while(current){
        head = current->next;
        length -= 1;
		delete current;
		current = head;
    }
    std::cout << "LIST DELETED: " << length << std::endl;
}

// add(value)				//Adds a new value to the end of this list.
void LinkedList::add(Airport* val){ //changed "data" to "dat"
   /* 
    Node* p = new Node;
  
  p->data = val; //send help pls SOS
  p->next = head;
  head = p;
  length++;
  */
  // Your code here
  Node* p = new Node;
  
  p->data = val; //send help pls SOS

  Node* current = new Node;
  current = head;
  if(current==NULL){
    head = p;
  }
  else{
    while(current->next){
    current = current->next;
  }
  current->next = p;
  
  }
  length++;
  
  
}

// clear()					//Removes all elements from this list.
// Clear the list management information and release all allocated Nodes
void LinkedList::clear(){
   Node* current = this->head;
    while(current){
        this->head = current->next;
        this->length -= 1;
		delete current;
    }
}
/*
bool equals(LinkedList* list){     //Returns true if the two lists contain the same elements in the same order.
  if(this->length==list->length){
    for(int i = 0; i < length; i++){
      if(list->Node!=this->Node){
        return false;
      }
    }
    return true;
  }
  return false;
}				
*/
Airport* LinkedList::get(int index){		//Returns the element at the specified index in this list.
  
  Node* current = new Node;
  current = head;
  for(int i = 0; i < index; i++){
    //cout << "getting" << endl;
    current = current->next;
   // cout << "done getting" << endl;
  
  }
  return current->data;
}

void LinkedList::insert(int index, Node* value){		//Inserts the element into this list before the specified index.
  Node* current = new Node;
  for(int i = 0; i < index; i++){
    current = this->head;
  }
    current->next = value;
}
//exchg(index1, index2)		//Switches the payload data of specified indexex.

//swap(index1,index2)		//Swaps node located at index1 with node at index2

// isEmpty()				//Returns true if this list contains no elements.

/* remove(index)			//Removes the element at the specified index from this list.
void remove(int val){
  
  // Your code here
  Node* current = head;
  Node* previous = new Node;
  while(current && current->data != val){
    previous = current;
    current = current->next;
  }
  if (current){
    if(current->next == head){
      head = current->next;
    }
    else if(current->next != head){
      previous->next = current->next;
    }
  }
  delete current;
  length--;
}

// set(index, value)		//Replaces the element at the specified index in this list with a new value.

// size()					//Returns the number of elements in this list.

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

// toString()				//Converts the list to a printable string representation.
// print the entire list's data
*/
void LinkedList::toString(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << i << ": " << head->data->code << " long: " << head->data->longitude << " lat: " << head->data->latitude << std::endl;
        head = head->next;
        i++;
    }
}

void Airport::toString(){
  std::cout << code << " long: " << longitude << " lat: " << latitude << std::endl;
}

