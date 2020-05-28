#pragma once
#include "Node.h"
#include <iostream>
// Creates a linked list

template<class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;

	int size;
	T value;

public:

	LinkedList();

	bool add(T element);
	void add(T element, int index);
	void add_all(LinkedList<T>* list);
	void add_first(T element);
	void add_last(T element);
	bool set(int index, T element);
	bool remove(int index);
	Node<T>* get(int index);
	Node<T>* get_first();
	Node<T>* get_last();
	int index_of(T element);
	int last_index_of(T element);
	T* to_array();
	bool clear();
	int get_size();
};

template<class T>
inline LinkedList<T>::LinkedList()
{
	this->size = 0;
}

template<class T>
bool LinkedList<T>::add(T element)
{
	if (element == NULL) {
		return false;
	}
	else {
		Node<T> node(element);
		if (this->size == 0) {
			*head = node;
			this->size++;
			return true;
		}

	}
	return false;
}
