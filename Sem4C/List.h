#pragma once
#include "AbstractList.h"
#include "AbstractIterator.h"
template <typename T>
class List : public AbstractList
{
public:
	class ListIterator : public AbstractIterator {
		ListIterator(List &inputList) :list(&inputList) {}
	};

	void add(int);
};