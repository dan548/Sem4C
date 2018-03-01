#pragma once
#include "RingBuffer.h"
class RingBufferIterator
{
public:
	RingBufferIterator(RingBuffer*);
	~RingBufferIterator();
	void start();
	void next();
	bool finish();
	int getValue();
private:
	RingBuffer* queue;
	int current;
};

