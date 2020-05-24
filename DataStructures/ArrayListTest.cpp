#include "ArrayList.h"
#include <iostream>
#include <array>

using namespace std;

int main()
{
	
	std::array<int, 4> A = { 10,20,30,40 };
	std::array<int, 4> B = A; //copy array A into array B

	cout << B[1];

	return 0;
}
