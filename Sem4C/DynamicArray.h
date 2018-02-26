#ifndef SEM4_1_DYNAMICARRAY_H
#define SEM4_1_DYNAMICARRAY_H

#include "stdafx.h"

class DynamicArray {
public:
    DynamicArray(int size = 10, int n = 0, int reserve = 10);
	int& operator[](int);
    DynamicArray(DynamicArray&&);
    DynamicArray(const DynamicArray&);
    ~DynamicArray();
    int getLength()const;
	void reserve(int);    
    DynamicArray&operator=(const DynamicArray&);
    DynamicArray&operator=(DynamicArray&&);
    void resize(int);
	int capacity();
    friend const bool operator == (const DynamicArray &, const DynamicArray &);
    friend const bool operator != (const DynamicArray &, const DynamicArray &);
    friend const bool operator < (const DynamicArray &, const DynamicArray &);
    friend const bool operator <= (const DynamicArray &, const DynamicArray &);
    friend const bool operator > (const DynamicArray &, const DynamicArray &);
    friend const bool operator >= (const DynamicArray &, const DynamicArray &);
    friend DynamicArray& operator+ (const DynamicArray&, const DynamicArray&);
    friend std::ostream& operator<<(std::ostream&, const DynamicArray&);
    friend std::istream& operator>>(std::istream&, const DynamicArray&);
	void pushBack(int);
	int popBack();
private:
    int* array;
    int length;
    int realLength;
    void destroy();
};


#endif //SEM4_1_DYNAMICARRAY_H
