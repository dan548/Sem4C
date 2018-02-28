#pragma once
class RingBufferIterator
{
public:
	RingBufferIterator();
	~RingBufferIterator();
	void start();
	void next();
	bool finish();
	int getValue();
};

