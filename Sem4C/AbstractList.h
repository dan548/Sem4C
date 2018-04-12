#pragma once
#include "AbstractIterator.h"
template <typename T>
class AbstractList
{
public:
	virtual ~AbstractList() = default;
	virtual void add(T) = 0;
	virtual T remove() = 0;
	virtual void makeEmpty() = 0;
	virtual int getLength() = 0;
	virtual AbstractIterator<T>* iterator() = 0;
	virtual bool isEmpty() = 0;
	virtual AbstractIterator<T>* findFirst(T) = 0;
};

