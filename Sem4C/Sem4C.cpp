#include "stdafx.h"
#include "DynamicArray.h"
#include "RingBuffer.h"
#include "List.h"
#include "AbstractIterator.h"
using namespace std;

int main()
{
	List<int> list1;
	list1.add(1);
	list1.add(2);
	list1.add(3);
	list1.add(4);
	list1.add(5);
	list1.add(6);

	list1 = move(list1);
	system("pause");
}

