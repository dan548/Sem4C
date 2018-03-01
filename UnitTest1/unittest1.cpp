#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Sem4C/RingBuffer.h"
#include "../Sem4C/RingBufferIterator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			int res = 0;
			RingBuffer queue(7);
			for (int i = 0; i < 7; i++) {
				queue.add(8 * i % 3);
			}
			/*RingBufferIterator iter(&queue);
			iter.start();
			while (!iter.finish()) {
				res += iter.getValue();
			}*/
			//Assert::IsTrue(queue.peek() == 6);
		}

	};
}