#ifndef SEM4_1_DYNAMICARRAY_H
#define SEM4_1_DYNAMICARRAY_H

#include "stdafx.h"

class DynamicArray {
public:
    DynamicArray(int size = 10, int n = 0, int reserve = 10); //tested
	int& operator[](int); //tested
    DynamicArray(DynamicArray&&); //tested
    DynamicArray(const DynamicArray&); //tested
    ~DynamicArray();
    int getLength()const; //tested
	void reserve(int); //tested   
    DynamicArray&operator=(const DynamicArray&); //tested
    DynamicArray&operator=(DynamicArray&&); //tested
    void resize(int); //tested
	int capacity(); //tested
    friend const bool operator == (const DynamicArray &, const DynamicArray &); //tested
    friend const bool operator != (const DynamicArray &, const DynamicArray &); //tested
    friend const bool operator < (const DynamicArray &, const DynamicArray &); //tested
    friend const bool operator <= (const DynamicArray &, const DynamicArray &); //tested
    friend const bool operator > (const DynamicArray &, const DynamicArray &); //tested
    friend const bool operator >= (const DynamicArray &, const DynamicArray &); //tested
    friend DynamicArray& operator+ (const DynamicArray&, const DynamicArray&); //tested
    friend std::ostream& operator<<(std::ostream&, const DynamicArray&); //tested
    friend std::istream& operator>>(std::istream&, const DynamicArray&); //tested
	void pushBack(int); //tested
	int popBack(); //tested
private:
    int* array;
    int length;
    int realLength;
};


#endif //SEM4_1_DYNAMICARRAY_H
