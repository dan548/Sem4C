#include "stdafx.h"
#include "RingBufferIterator.h"

template <typename T>
RingBufferIterator<T>::RingBufferIterator(RingBuffer* ringBuffer):
	queue(ringBuffer)
{
	current = -1;
}

template <typename T>
RingBufferIterator<T>::~RingBufferIterator()
{
}

template <typename T>
void RingBufferIterator<T>::start()
{
	if (current == -1) {
		current = 0;
	}
}

template <typename T>
void RingBufferIterator<T>::next()
{
	if (current >= 0 || current < queue->getSize()) current++;
}

template <typename T>
bool RingBufferIterator<T>::finish()
{
	return current == queue->getSize();
}

template <typename T>
T RingBufferIterator<T>::getValue()
{
	int res = queue->poll();
	queue->add(res);
	return res;
}
