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
	virtual int length() = 0;
	virtual AbstractIterator* iterator() = 0;
	virtual bool isEmpty() = 0;
	virtual AbstractIterator* findFirst(T) = 0;
};

