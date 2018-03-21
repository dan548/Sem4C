#pragma once
template <typename T>
class AbstractList
{
public:
	virtual ~AbstractList() = default;
	virtual void add(int) = 0;
	virtual T remove(int) = 0;
	virtual void makeEmpty() = 0;
	virtual int length() = 0;
};

