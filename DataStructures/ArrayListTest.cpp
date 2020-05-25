#include "ArrayList.h"
#include <iostream>
#include <array>

using namespace std;

int main()
{
	
	ArrayList ida;
	/*for (int i = 0; i < 50; i++) {
		list.add(i*i);
		cout << list.get(i) << "\n";
	}

	cout << "List size: " << list.size() << "\n";
	cout << "List capacity: " << list.capacity() << "\n";*/

	if ((ida.size() == 0) && (ida.capacity() == 2)) {
		//System.out.println("Yay 1");
		cout << "Yay 1\n";
	}

	// adding to the list?
	bool ok = true;
	for (int i = 0; i < 3; i++)
		ok = ok && ida.add(i * 5);

	if (ok && ida.size() == 3 && ida.get(2) == 10 && ida.capacity() == 4) {
		cout << "Yay 2\n";
		//System.out.println("Yay 2");
	}

	ida.add(1, -10);
	ida.add(4, 100);
	if (ida.set(1, -20) == -10 && ida.get(2) == 5 && ida.size() == 5
		&& ida.capacity() == 8) {
		cout << "Yay 3\n";
		//System.out.println("Yay 3");
	}

	// removing from the list?
	if (ida.remove(0) == 0 && ida.remove(0) == -20 && ida.remove(2) == 100
		&& ida.size() == 2 && ida.capacity() == 4) {
	//	System.out.println("Yay 4");
		cout << "Yay 4\n";
	}

	return 0;
}
