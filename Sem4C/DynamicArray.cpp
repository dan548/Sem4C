#include "stdafx.h"
#include "DynamicArray.h"


DynamicArray::DynamicArray(int size, int n, int reserveSize)
        :length(size)
        ,realLength(size + reserveSize)
        ,array(nullptr)
{
    array = new int[realLength];
    for (int i = 0; i < length; i++){
        array[i] = n;
    }
}

void DynamicArray::resize(int newSize) {
	if (newSize > realLength) {
		reserve(newSize - realLength);
	}
	if (newSize < length) {
		length = newSize;
	}
	for (int i = length; i < newSize; i++) {
		array[i] = 0;
	}
	length = newSize;
}

int& DynamicArray::operator [](int n) {
	int* error = new int;
	error[0] = -1;
	try {
		if (n < 0 || n >= length) {
			throw("Wrong index!");
		}
		return array[n];
	}
	catch (char* err) {
		std::cerr << err << std::endl;
	}
	return *error;
}

int DynamicArray::capacity()
{
	return realLength - length;
}

DynamicArray::DynamicArray(DynamicArray&& dA)
        :length(dA.length)
        ,realLength(dA.realLength)
        ,array(dA.array)
{
    dA.array = nullptr;
	dA.length = 0;
	dA.realLength = 0;
}

DynamicArray::DynamicArray(const DynamicArray& dA)
        :length(dA.length)
        ,realLength(dA.realLength)
        ,array(nullptr)
{
    array = new int[realLength];
	for (int i = 0; i < length; i++) {
		array[i] = dA.array[i];
	}
}

DynamicArray::~DynamicArray() {
	delete[] array;
}

int DynamicArray::getLength()const {
    return length;
}

void DynamicArray::reserve(int n)
{
	realLength += n;
	int* newArray = new int[realLength];
	for (int i = 0; i < realLength - n; i++) {
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& dA) {
    length = dA.length;
    realLength = dA.realLength;
    array = new int[realLength];
	for (int i = 0; i < length; i++) {
		array[i] = dA.array[i];
	}
    return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& dA) {
	if (this != &dA) {
		length = dA.length;
		realLength = dA.realLength;
		array = dA.array;
		dA.array = nullptr;
		dA.length = 0;
		dA.realLength = 0;
	}
    return *this;
}

void DynamicArray::pushBack(int x)
{
	if (capacity() == 0) {
		reserve(5);
	}
	array[length] = x;
	length++;
}

int DynamicArray::popBack()
{
	length--;
	return array[length];
}

const bool operator==(const DynamicArray &dA1, const DynamicArray &dA2)
{
	if (dA1.length != dA2.length) {
		throw std::invalid_argument("Array lengths do not match!");
	}
	for (int i = 0; i < dA1.length; i++) {
		if (dA1.array[i] != dA2.array[i]) return false;
	}
	return true;
}

const bool operator!=(const DynamicArray &dA1, const DynamicArray &dA2)
{
	return !(dA1 == dA2);
}

const bool operator<(const DynamicArray &dA1, const DynamicArray &dA2) {
	if (&dA1 == &dA2) return false;
	int size = std::fmin(dA1.length, dA2.length);
    for (int i = 0; i < size; i++) {
        if(dA1.array[i] < dA2.array[i]) return true;
        if(dA1.array[i] > dA2.array[i]) return false;
    }
	return dA1.length < dA2.length;
}

const bool operator>(const DynamicArray &dA1, const DynamicArray &dA2) {
    return dA2 < dA1;
}

const bool operator<=(const DynamicArray &dA1, const DynamicArray &dA2) {
    return !(dA2 < dA1);
}

const bool operator>=(const DynamicArray &dA1, const DynamicArray &dA2) {
    return !(dA1 < dA2);
}

DynamicArray &operator+(const DynamicArray &dA1, const DynamicArray &dA2) {
    DynamicArray* resArray = new DynamicArray(0, 0, dA1.getLength() + dA2.getLength());
    for (int i = 0; i < dA1.getLength(); i++) {
        resArray->pushBack(dA1.array[i]);
    }
    for (int i = 0; i < dA2.getLength(); i++) {
		resArray->pushBack(dA2.array[i]);
    }
    return *resArray;
}

std::ostream &operator<<(std::ostream &os, const DynamicArray &dA) {
    for (int i = 0; i < dA.getLength(); i++) {
        os << dA.array[i] << " ";
    }
    os << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, const DynamicArray &dA) {
    for (int i = 0; i < dA.getLength(); i++) {
        is >> dA.array[i];
    }
    return is;
}