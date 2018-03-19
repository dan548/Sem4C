/*#include "stdafx.h"
#include "RingBuffer.h"

template <typename T>
RingBuffer<T>::RingBuffer(int buf):
	buffer(nullptr),
	bufSize(buf)
{
	buffer = new int[bufSize];
	size = 0;
	start = 0;
}

template <typename T>
RingBuffer<T>::~RingBuffer()
{
	delete[] buffer;
}

template <typename T>
void RingBuffer<T>::add(T x)
{
	if (size < bufSize) {
		buffer[(start + size) % bufSize] = x;
		size++;
	} else {
		throw std::length_error("The buffer is full!");
	}
}

template <typename T>
T RingBuffer<T>::poll()
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

template <typename T>
inline T RingBuffer<T>::peek()
{
	if (!isEmpty()) {
		return buffer[start];
	}
	else {
		throw std::length_error("The buffer is empty!");
	}
}

template <typename T>
int RingBuffer<T>::getSize()
{
	return size;
}

template <typename T>
void RingBuffer<T>::makeEmpty()
{
	size = 0;
	start = 0;
}

template <typename T>
inline bool RingBuffer<T>::isEmpty()
{
	return size == 0;
}
*/