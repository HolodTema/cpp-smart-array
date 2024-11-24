
#ifndef SMART_ARRAY_EXCEPTIONS_H
#define SMART_ARRAY_EXCEPTIONS_H

#include <stdexcept>

class NoMemoryToAllocateException: public std::exception {
	const char * what() const noexcept {
		return "Error: no memory to allocate smart array\n";
	}
};

class ArrayIndexOutOfRangeException: public std::exception {
	const char * what() const noexcept {
		return "Error: array index is out of range\n";
	}
};

#endif

