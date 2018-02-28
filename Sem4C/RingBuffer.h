#pragma once
class RingBuffer
{
public:
	RingBuffer(int);
	~RingBuffer();
	void add(int);
	int poll();
	inline int peek();
	inline int getSize();
	void makeEmpty();
	inline bool isEmpty();
private:
	int size;
	int bufSize;
	int start;
	int* buffer;
};

