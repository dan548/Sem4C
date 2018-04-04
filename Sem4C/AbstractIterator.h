#pragma once
#include "AbstractList.h"
template <typename T>
class AbstractIterator
{
public:
	virtual void start() = 0;
	virtual T get() = 0;
	virtual void next() = 0;
	virtual bool isFinish() = 0;
protected:
	AbstractList* list;
};