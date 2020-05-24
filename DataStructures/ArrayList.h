#pragma once
#include <string>

using namespace std;

/**
	Basic C++ implementation of Arraylist
	Its and integer arraylist.
*/

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
	int* storage;

	// Reallocates the array
	int* grow_array(bool halve);
	//Validates the range of given index
	void validate_range(int index);


public:
	/**
	 * This default constructor sets the capacity of the dynamic {@literal array -> 2}.
	 * Currently an empty array.
	 */
	ArrayList() {
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
	ArrayList(int init_capacity) {
		if (init_capacity < 1) {
			throw "Initial Capacity cannot be less than 1";
		}
		storage = new int[init_capacity];
		num_of_elements = 0;
		length_of_storage = init_capacity;
	}

	int size();
	int capacity();
	int set(int index, int value);
	int get(int index);
	bool add(int value);
	void add(int index, int value);
	int remove(int index);
	string toString();
};


/**
 * Checks if the given range is positve numbers and that.
 * it falls below the maximum length of the current array boundaries.
 *
 * @param index - requested index
 */
void ArrayList::validate_range(int index)
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
int* ArrayList::grow_array(bool halve)
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
int ArrayList::size()
{
	return this->num_of_elements;
}

/**
	 * Access the overall size of the array.
	 * @return capacity
	 */
int ArrayList::capacity()
{
	return this->length_of_storage;
}

/**
	 * Overwrites the value at the provided index with a new value.
	 *
	 * @param index  index to be modified
	 * @param value  value to be inserted
	 * @return original value at the index
	 */
int ArrayList::set(int index, int value)
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
int ArrayList::get(int index)
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
bool ArrayList::add(int value)
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
void ArrayList::add(int index, int value)
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

/**
 * Removes the value at the requested index.
 * The gap is filled in with the remaining values.
 * @param index position of the value
 * @return old value.
 */
int ArrayList::remove(int index)
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

/**
	return string representation of DynamicArray
	*/
string ArrayList::toString()
{
	return "Arraylist with  size" + this->num_of_elements;
}


