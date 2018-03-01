#include "stdafx.h"
#include "RingBuffer.h"


RingBuffer::RingBuffer(int buf):
	buffer(nullptr),
	bufSize(buf)
{
	buffer = new int[bufSize];
	size = 0;
	start = 0;
}


RingBuffer::~RingBuffer()
{
	delete[] buffer;
}

void RingBuffer::add(int x)
{
	if (size < bufSize) {
		buffer[(start + size) % bufSize] = x;
		size++;
	} else {
		throw std::length_error("The buffer is full!");
	}
}

int RingBuffer::poll()
{
	if (!isEmpty()) {
		size--;
		if (start < bufSize - 1) {
			start++;
			return buffer[start - 1];
		} else {
			start = 0;
			return buffer[bufSize - 1];
		}
	} else {
		throw std::length_error("The buffer is empty!");
	}
}

inline int RingBuffer::peek()
{
	if (!isEmpty()) {
		return buffer[start];
	}
	else {
		throw std::length_error("The buffer is empty!");
	}
}

int RingBuffer::getSize()
{
	return size;
}

void RingBuffer::makeEmpty()
{
	size = 0;
	start = 0;
}

inline bool RingBuffer::isEmpty()
{
	return size == 0;
}
