/*
This is an implementation of a generic stack.
Any single data type can be used to create
a stack data structure.
*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
private:
	/*
	This holds the current top position of the stack
	*/
	int top = -1;
	/*
	This refers to the overall size of the stack
	*/
	int size;
	/*
	Accounts for the number of actual data in the stack
	*/
	int numElements;
	/*
	The stack itself
	*/
	vector<T> storage;

public:
	/*
	Default constructor that initializes an empty stack*/
	Stack() {
		size = 5;
		numElements = 0;
	}
	/*
	User defined constructor that initializes the stack size
	to a given value
	*/
	Stack(int n) {
		size = n;
		numElements = 0;
		storage.reserve(size);

	}
	/*
	Destructor to clear the memory used by the vector stack
	*/
	~Stack() {
		storage.clear();
	}
	/*
	Verifies the emptiness of the stack
	*/
	bool isEmpty();
	/*
	Verifies the fullness of the stack
	*/
	bool isFull();
	/*
	Adds to the stack
	*/
	void push(T data);
	/*
	Removes the last element from the stack
	*/
	T pop();
	/*
	Displays the last element of the stack
	*/
	T peek();
	/*
	Returns the size of the stack
	*/
	int stackSize();
};

/*
Returns 0 if the stack is empty
*/
template <typename T>
bool Stack<T>::isEmpty()
{
	return storage.size() == 0;
}
/*
Returns 0 if the stack is full
*/
template <typename T>
bool Stack<T>::isFull()
{
	return size == numElements;
}
/*
Returns the last element of the stack
as well as removing that element from the stack itself
*/
template <typename T>
T Stack<T>::pop()
{
	if (!isEmpty()) {
		T val = storage.back();
		storage.pop_back();
		top--; numElements--;
		return val;
	}
	else {
		cout << "Stack Underflow\n" << endl;
		return 0;
	}
}
/*
Pushes a data to the stack as long as the stack
is not full
*/
template <typename T>
void Stack<T>::push(T data)
{
	if (!isFull()) {
		storage.push_back(data);
		numElements++; top++;
	}
	else {
		cout << "Stack is full\n";
	}
}
/*
Return the last element of the stack without removing it
from the stack.
*/
template <typename T>
T Stack<T>::peek()
{
	if (!isEmpty()) {
		return storage.back();
	}
	else {
		cout << "Stack is empty\n" << endl;
	}
}
/*
Returns the capacity of the stack
*/
template <typename T>
int Stack<T>::stackSize()
{
	return storage.size();
}