
#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H

#include <iostream>
#include <stdexcept>
#include "smartArrayExceptions.h"

template <typename T>
class SmartArray final {
private:
	static constexpr unsigned int START_CAPACITY_ = 20;

	T* data_;
	unsigned int capacity_;
	unsigned int size_;

	void extendCapacity() {
		T *dataExtended;
		try {
			dataExtended = new T[capacity_*2];
		}
		catch (std::bad_alloc &e) {
			throw NoMemoryToAllocateException();
		}
		SmartArray arrayCopy = SmartArray(size_, capacity_*2, dataExtended);
		for (int i = 0; i<size_; ++i) {
			arrayCopy[i] = *this[i];
		}
		swap(arrayCopy);
		delete[] arrayCopy.data_;
	}
	
	//to use copy-and-swap idiom
	void swap(SmartArray &array) noexcept {
		std::swap(capacity_, array.capacity_);
		std::swap(size_, array.size_);
		std::swap(data_, array.data_);
	}
	
	//private constructor to extend capacity
	SmartArray(const unsigned int size, const unsigned int capacity, T *data) {
		size_ = size;
		capacity_ = capacity;
		data_ = data;
	}

public:
	SmartArray(const unsigned int size) {
		if (size > START_CAPACITY_) {
			unsigned int newCapacity = 
				size + (START_CAPACITY_ - size % START_CAPACITY_);
			
			try {
				data_ = new T[newCapacity];
			}
			catch (std::bad_alloc &e) {
				throw NoMemoryToAllocateException();
			}

			capacity_ = newCapacity;
			size_ = size;
		}
		else {
			try {
				data_ = new T[START_CAPACITY_];
			}
			catch (std::bad_alloc &e) {
				throw NoMemoryToAllocateException();
			}
			
			capacity_ = START_CAPACITY_;
			size_ = size;
		}
	}

	SmartArray(unsigned int size, T* data) {
		data_ = data;
		size_ = size;
		capacity_ = size;
	}

	SmartArray(SmartArray &array) {
		size_ = array.size_;
		capacity_ = array.capacity_;
		try {
			data_ = new int[capacity_];
		}
		catch(std::bad_alloc &e) {
			throw NoMemoryToAllocateException();
		}
	}

	~SmartArray() {
		if (data_ != nullptr && data_ != 0) {
			delete[] data_;
		}
	}

	unsigned int getSize() const noexcept {
		return size_;
	}
	
	void add(T newElement);

	T& operator [] (unsigned int index) const;
};
	

			

#endif
