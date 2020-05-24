#pragma once
#include <string>

using namespace std;


class ArrayList
{
private:
	int INITCAP = 2;
	int length_of_storage;
	int num_of_elements;
	int* storage;


	int* grow_array(bool halve);
	void validate_range(int index);


public:
	ArrayList() {
		storage = new int[INITCAP];
		num_of_elements = 0;
		length_of_storage = INITCAP;
	}

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

void ArrayList::validate_range(int index)
{
	if (index < 0 || index > this->length_of_storage) {
		throw "Invalid Index";
	}
}

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

int ArrayList::size()
{
	return this->num_of_elements;
}

int ArrayList::capacity()
{
	return this->length_of_storage;
}

int ArrayList::set(int index, int value)
{
	validate_range(index);
	int oldItem = storage[index];
	storage[index] = value;
	return oldItem;
}

int ArrayList::get(int index)
{
	validate_range(index);
	return storage[index];
}

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




