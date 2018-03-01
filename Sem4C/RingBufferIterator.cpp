#include "stdafx.h"
#include "RingBufferIterator.h"


RingBufferIterator::RingBufferIterator(RingBuffer* ringBuffer):
	queue(ringBuffer)
{
	current = -1;
}


RingBufferIterator::~RingBufferIterator()
{
}

void RingBufferIterator::start()
{
	if (current == -1) {
		current = 0;
	}
}

void RingBufferIterator::next()
{
	if (current >= 0 || current < queue->getSize()) current++;
}

bool RingBufferIterator::finish()
{
	return current == queue->getSize();
}

int RingBufferIterator::getValue()
{
	int res = queue->poll();
	queue->add(res);
	return res;
}
