#pragma once

using namespace std;


class ArrayList
{
private:
	int INITCAP = 2;
	int length_of_storage;
	int num_of_elements;
	int* storage;

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
	int add(int value);
	int add(int index, int value);
	int remove(int index);








};