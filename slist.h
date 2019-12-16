/*
Header file for single linked list class library
*/
class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    void toString();
    
};

class Node
{
public:
    Node* next;
    Airport* data;
};


class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(Airport* val);
    void remove(Airport* data);
	  int sum();
    void clear();
    Airport* get(int index);
    void insert(int index, Node* value);
    void display();
    void toString();
};


//void add(Airport* dat);				//Adds a new value to the end of this list.

//void clear();				//Removes all elements from this list.

//bool equals(LinkedList list);				//Returns true if the two lists contain the same elements in the same order.

// get(int index);				//Returns the element at the specified index in this list.

//void insert(int index, Node value);		//Inserts the element into this list before the specified index.

//void exchg(index1, index2);		//Switches the payload data of specified indexex.

//void swap(index1,index2);		//Swaps node located at index1 with node at index2

//boolean isEmpty();				//Returns true if this list contains no elements.

//void mapAll(fn);				//Calls the specified function on each element of the linkedlist in ascending index order.

//void remove(index);			//Removes the element at the specified index from this list.

//void set(index, value);		//Replaces the element at the specified index in this list with a new value.

//int size();					//Returns the number of elements in this list.

//LinkedList subList(start, length);	//Returns a new list containing elements from a sub-range of this list.

//void toString();				//Converts the list to a printable string representation.
