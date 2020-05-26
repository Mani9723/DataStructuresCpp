#pragma once
// Defines a Node

template<class T>
class Node
{

private: 
	T data;
	Node<T>* next;
	Node<T>* prev;

public:
	Node(T data);
	T getValue();
	void setValue(T value);
	Node<T>* getNext();
	Node<T>* getPrev();
	void setNext(Node<T>* next);
	void setPrev(Node<T>*prev);
};

template<class T>
inline Node<T>::Node(T data)
{
	this->data = data;
}

template<class T>
inline T Node<T>::getValue()
{
	return this->data;
}

template<class T>
inline void Node<T>::setValue(T value)
{
	this->data = value;
}

template<class T>
inline Node<T>* Node<T>::getNext()
{
	return this->next;
}

template<class T>
inline Node<T>* Node<T>::getPrev()
{
	return this->prev;
}

template<class T>
inline void Node<T>::setNext(Node<T>* next)
{
	this->next = next;
}

template<class T>
inline void Node<T>::setPrev(Node<T>* prev)
{
	this->prev = prev;
}
