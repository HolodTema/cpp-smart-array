#include <stdexcept>
#include "SmartArray.h"
#include "smartArrayExceptions.h"

template <typename T>
void SmartArray<T>::add(T element) {
	if (capacity_ - size_ < 1) {
		extendCapacity();
	}
	data_[size_] = element;
	++size_;
}

template <typename T>
T& SmartArray<T>::operator [] (unsigned int index) const {
	T& element = nullptr;
	try {
		element = data_[index];
	}
	catch (std::out_of_range &e) {
		throw ArrayIndexOutOfRangeException();
	}
	
	return element;
}

