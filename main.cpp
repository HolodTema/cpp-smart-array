#include <iostream>
#include "SmartArray.h"

int main() {
	SmartArray<int> array = SmartArray<int>(10);
	array[3] = 5;
	array[5] = 8;

	array.add(48);

	for (int i = 0; i<array.getSize(); ++i) {
		std::cout << array[i] << "\t";
	}
	std::cout << "\n";
	
	return 0;
}
