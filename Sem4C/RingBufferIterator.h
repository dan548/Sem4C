#pragma once
#include "RingBuffer.h"
template <typename T>
class RingBufferIterator
{
public:
	RingBufferIterator(RingBuffer*);
	~RingBufferIterator();
	void start();
	void next();
	bool finish();
	T getValue();
private:
	RingBuffer* queue;
	int current;
};

