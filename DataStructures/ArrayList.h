#pragma once
#include <string>

using namespace std;

/**
	Basic C++ implementation of Arraylist
*/

template<class T>
class ArrayList
{
private:
	/**
		* Default capacity of the array if no other value is provided.
	*/
	int INITCAP = 2;
	/**
	 * The overall size of the array.
	 */
	int length_of_storage;
	/**
	 * The number of elements actually in the array.
	 */
	int num_of_elements;
	/**
	 * The generic array.
	 */
	T* storage;

	// Reallocates the array
	int* grow_array(bool halve);
	//Validates the range of given index
	void validate_range(int index);


public:
	/*Default constructor*/
	ArrayList();
	/* User defined constructor*/
	ArrayList(int init_capacity);
	/*User defined constructor*/
	ArrayList(ArrayList<T>& list);
	/* Destructor*/
	~ArrayList();
	/*Returns the actual of the list*/
	int size();
	/*Returns the total capacity of the list*/
	int capacity();
	/*Returns the index of an element*/
	int index_of(T value);
	/*Returns the last known index of an element*/
	int last_index_of(T value);
	/*Returns if the list is empty*/
	bool isEmpty();
	/*Searches the list*/
	bool contains(T value);
	/*Sets value at a particular index*/
	int set(int index, int value);
	/*Returns a value from an index*/
	int get(int index);
	/*Appends a value*/
	bool add(int value);
	/*Inserts a value at an index*/
	void add(int index, int value);
	/*Appends another list*/
	void addAll(ArrayList<T> &list);
	/*Removes a value at an index*/
	int remove(int index);
	/*Creates a sublist within the given inclusive bounds*/
	ArrayList<T> sublist(int src, int dest);
	/*Returns an array representation*/
	T* toArray();
	/*Clears the list*/
	void clear();
	/*ToString representation*/
	string toString();
};

/**
	 * This default constructor sets the capacity of the dynamic {@literal array -> 2}.
	 * Currently an empty array.
	 */
template<class T>
ArrayList<T>::ArrayList()
{
	storage = new int[INITCAP];
	num_of_elements = 0;
	length_of_storage = INITCAP;
}

/**
 * User defined constructor that sets the input value as the capacity of the array.
 * Throws an IllegalArgumentException if the input is less than 1.
 *
 * @param init_capacity capacity of the array
 */
template<class T>
ArrayList<T>::ArrayList(int init_capacity)
{
	storage = new int[init_capacity];
	num_of_elements = 0;
	length_of_storage = init_capacity;
}

/*
Constructor that initializes to provided list
*/
template<class T>
ArrayList<T>::ArrayList(ArrayList<T>& list)
{
	num_of_elements = list.size();
	length_of_storage = list.capacity() << 1;
	storage = new T[length_of_storage];
	for (int i = 0; i < num_of_elements; i++) {
		storage[i] = list.get(i);
	}
}

/*
Destructor
*/
template<class T>
ArrayList<T>::~ArrayList()
{
	delete[] storage;
}

/**
 * Checks if the given range is positve numbers and that.
 * it falls below the maximum length of the current array boundaries.
 *
 * @param index - requested index
 */
template<class T>
void ArrayList<T>::validate_range(int index)
{
	if (index < 0 || index > this->length_of_storage) {
		throw "Invalid Index";
	}
}

/**
 * Adjusts the capacity of the array.
 * The parameter determines if the capacity
 * needs to be increased or decreased.
 *
 * @param halve  true if size/2; false if size*2
 * @return new array pointer
 */
template<class T>
int* ArrayList<T>::grow_array(bool halve)
{
	if (halve) {
		this->length_of_storage = this->length_of_storage >> 1;
	}
	else {
		this->length_of_storage = this->length_of_storage << 1;
	}
	int* temp = new int[this->length_of_storage];

	for (int i = 0; i < this->length_of_storage; i++) {
		temp[i] = this->storage[i];
	}

	delete[] this->storage;

	return temp;
}

/**
 * Access the total number of elements in the array.
 * @return number of elements
 */
template<class T>
int ArrayList<T>::size()
{
	return this->num_of_elements;
}

/**
 * Access the overall size of the array.
 * @return capacity
 */
template<class T>
int ArrayList<T>::capacity()
{
	return this->length_of_storage;
}

/*
This function returns the first known index of an element
*/
template<class T>
int ArrayList<T>::index_of(T value)
{
	if (value == NULL) {
		for (int i = 0; i < this->num_of_elements; i++) {
			if (this->storage[i] == NULL) {
				return i;
			}
		}
	}
	for (int i = 0; i < this->num_of_elements; i++) {
		if (this->storage[i] == value) {
			return i;
		}
	}
	return -1;
}

/*
Finds the last known index of an element
*/
template<class T>
int ArrayList<T>::last_index_of(T value)
{
	if (value == NULL) {
		for (int i = num_of_elements; i >= 0; i--) {
			if (this->storage[i] == NULL) {
				return i;
			}
		}
	}
	for (int i = num_of_elements; i >= 0; i--) {
		if (this->storage[i] == value) {
			return i;
		}
	}
	return -1;
}

/*
Returns true if the list is empty
*/
template<class T>
bool ArrayList<T>::isEmpty()
{
	return this->size == 0;
}

/*
Checks the list if it contains a specific value
*/
template<class T>
bool ArrayList<T>::contains(T value)
{
	return index_of(value) != -1;
}

/**
 * Overwrites the value at the provided index with a new value.
 *
 * @param index  index to be modified
 * @param value  value to be inserted
 * @return original value at the index
 */
template<class T>
int ArrayList<T>::set(int index, int value)
{
	validate_range(index);
	int oldItem = storage[index];
	storage[index] = value;
	return oldItem;
}

/**
 * Returns the value at the index.
 * @param index location
 * @return array[index]
 */
template<class T>
int ArrayList<T>::get(int index)
{
	validate_range(index);
	return storage[index];
}

/**
 * Appends a value at the end of the array.
 * Automatically increases the capacity if necessary.
 *
 * @param value insertion value
 * @return true if successful
 */
template<class T>
bool ArrayList<T>::add(int value)
{
	if (this->num_of_elements == this->length_of_storage)
	{
		this->storage = grow_array(false);
	}
	this->storage[this->num_of_elements] = value;
	this->num_of_elements++;

	return true;
}

/**
 * Inserts the value at an index and shifts the values to right if not appending.
 * Increases the capacity of the array if the need arises.
 * @param index insertion point
 * @param value value to be inserted
 */
template<class T>
void ArrayList<T>::add(int index, int value)
{
	validate_range(index);

	if (this->num_of_elements == this->length_of_storage) {
		this->storage = grow_array(false);
	}
	if (index == this->num_of_elements) {
		add(value);
	}
	else {
		int end = this->num_of_elements - 1;
		for (int i = end; i >= index; i--) {
			this->storage[i + 1] = this->storage[i];
		}
		this->storage[index] = value;
		++this->num_of_elements;
	}
}
/*
Appends a whole list
*/
template<class T>
void ArrayList<T>::addAll(ArrayList<T> &list)
{
	this->num_of_elements += list.size();
	this->length_of_storage += list.capacity();
	for (int i = 0; i < list.size(); i++) {
		this->add(list.get(i));
	}
}

/**
 * Removes the value at the requested index.
 * The gap is filled in with the remaining values.
 * @param index position of the value
 * @return old value.
 */
template<class T>
int ArrayList<T>::remove(int index)
{
	validate_range(index);
	int oldItem = this->storage[index];

	if (this->num_of_elements < ((1 / 3) * this->length_of_storage)) {
		this->storage = grow_array(true);
	}
	if (index == this->num_of_elements - 1) {
		this->storage[index] = NULL;
	}
	else {
		int end = this->num_of_elements - 1;
		int currIndex = index + 1;
		for (int i = currIndex; i < index; i++) {
			this->storage[i - 1] = this->storage[i];
		}
		this->storage[end] = NULL;
		--this->num_of_elements;
	}
	return oldItem;
}

/*
Creates a child list from the parent list within the given 
inclusive bounds
*/
template<class T>
ArrayList<T> ArrayList<T>::sublist(int src, int dest)
{
	validate_range(src);
	validate_range(dest);

	if (src == dest)
		return NULL;

	ArrayList<T> new_list((dest - src) << 1);

	for (int i = src; i <= dest; i++) {
		new_list.add(this->storage[i]);
	}
	return new_list;
}

/*
Converts the ArrayList to an array
*/
template<class T>
T* ArrayList<T>::toArray()
{
	T* array_copy = new T[num_of_elements];
	for (int i = 0; i < this->num_of_elements; i++) {
		array_copy[i] = this->storage[i];
	}
	return array_copy;
}

template<class T>
inline void ArrayList<T>::clear()
{
	this->~ArrayList;
}

/**
	return string representation of DynamicArray
	*/
template<class T>
string ArrayList<T>::toString()
{
	return "Arraylist with  size" + this->num_of_elements;
}