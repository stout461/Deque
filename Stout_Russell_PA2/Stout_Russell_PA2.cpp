// Stout_Russell_PA2.cpp : This file contains the main' function. Program execution begins and ends there.
//

#include"pch.h"
//#include "Deque.h" 
#include <iostream>
#include <exception>

using namespace std;

// This is my node struct
template<class Type> 
struct node {
	node<Type> *next;
	node<Type> *prev;
	Type data;
};


template<class Type>
class Deque
{
private:// all the feilds i need to access the first and last elements
	node<Type> *head = new node<Type>();
	node<Type> *tail = new node<Type>();
	int siz;

public:
	Deque();
	~Deque();
	bool isEmpty();
	int size();
	Type first();
	Type last();
	void insertFirst(Type o);
	void insertLast(Type o);
	Type removeFirst();
	Type removeLast();
};



template<class Type>
Deque<Type>::Deque() { // default constructor for deque
	siz = 0;
};

template<class Type>
Deque<Type>::~Deque() { // destructor deletes all the values in the list and clears up values 
	node<Type> *walker = head; 
	while (walker != NULL)
	{
		node<Type> *delptr = walker;
		walker = walker->next;
		delptr->next = NULL;
		delete delptr;
		head = walker;
	}
	walker = NULL;
	delete head;
	delete tail;
};

template<class Type>
bool Deque<Type>:: isEmpty() { // returns if the list is empty or not 
	if (siz == 0) {
		return true;
	}
	return false;
};

template <class Type>
int Deque<Type>::size() { // returns the size of the list
	return siz;
};

template<class Type>
Type Deque<Type>::first() { // returns the first value in the list without changing it
	if (siz == 0) {
		cout << "there is no items in the list\n";
		return NULL;
	}
	return head->data;
};

template<class Type> 
Type Deque<Type>:: last(){	 // returns the last value in the list without changing it 
	if (siz == 0) {
		return NULL;
	}
	return tail->data;
};

template<class Type>
void Deque<Type>::insertFirst(Type o) { // inserts an element in the first spot on the list 
	if (size() == 0) {
		head->data = o;
		tail->data = o;
		siz++;
	}
	else {
		node<Type> *temp = new node<Type>();
		temp->data = o;
		head->prev = temp;
		temp->next = head;
		head = temp;
		siz++;
	}
	cout << head->data << " first has been added to the list \n";
};

template<class Type>
void Deque<Type>::insertLast(Type o) { // inserts an element at the last spot on the list 
	if (size() == 0) {
		head->data = o;
		tail->data = o;
		siz++;
	}
	else {
		node<Type> *temp = new node<Type>();
		temp->data = o;
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		siz++;
	}
	cout << tail->data << " last has been added to the list\n";
};

template<class Type>
Type Deque<Type>::removeFirst() { // removes an element from the head of the list 
	if (siz == 0) {
		cout << "there are no elements to return \n";
		return NULL;
	}
	else if (siz == 1) {
		Type temp = head->data;
		siz--;
		return temp;
	}
	else {
		Type temp = head->data;
		head = head->next;
		siz--;
		return temp;
	}
};

template<class Type>
Type Deque<Type>::removeLast() { // removes an element from the tail of the list 
	if (siz == 0) {
		cout << "there are no elements to return \n";
		return NULL;
	} 
	else if(siz == 1) {
		Type temp = tail->data;
		siz--;
		return temp;
	}
	else {
		Type temp = tail->data; 
		tail = tail->prev;
		siz--;
		return temp;
	}
};


int main()
{

	Deque<int> intQ;

	printf("isEmpty(1): %d\n", intQ.isEmpty() ? 1 : 0);
	intQ.insertFirst(4);
	printf("removeLast(4): %d\n", intQ.removeLast());
	intQ.insertFirst(5);
	intQ.insertFirst(12);
	intQ.insertLast(7);
	intQ.insertLast(13);
	printf("first(12): %d\n", intQ.first());
	printf("last(13): %d\n", intQ.last());
	printf("size(4): %d\n", intQ.size());
	printf("isEmpty(0): %d\n", intQ.isEmpty() ? 1 : 0);
	printf("removeLast(13) :%d\n", intQ.removeLast());
	printf("removeLast(7) :%d\n", intQ.removeLast());
	printf("removeLast(5) :%d\n", intQ.removeLast());
	printf("removeFirst(12) :%d\n", intQ.removeFirst());
	printf("size(0): %d\n", intQ.size());
	printf("isEmpty(1): %d\n", intQ.isEmpty() ? 1 : 0);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
