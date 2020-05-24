#include "ArrayList.h"
#include <iostream>
#include <array>

using namespace std;

int main()
{
	
	ArrayList list;
	for (int i = 0; i < 50; i++) {
		list.add(i*i);
		cout << list.get(i) << "\n";
	}

	cout << "List size: " << list.size() << "\n";
	cout << "List capacity: " << list.capacity() << "\n";

	return 0;
}
