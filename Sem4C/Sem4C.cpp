#include "stdafx.h"
#include "DynamicArray.h"
#include "RingBuffer.h"
using namespace std;

int main()
{
	/*DynamicArray array1(7);
	std::cin >> array1;
	int a = array1[4];
	array1[4] = 7;
	std::cout << a << std::endl;
	std::cout << array1 << std::endl;
	array1.pushBack(10);
	array1.pushBack(11);
	array1.pushBack(12);
	array1.pushBack(13);
	std::cout << array1.popBack() << std::endl << array1 << std::endl;
	std::cout << array1.getLength() << std::endl;
	DynamicArray array2(0);
	int b = array2[0];
	std::cout << b << std::endl;
	DynamicArray array3(4, 10);
	array2 = array1;
	array2 = std::move(array1);
	std::cout << array2 << std::endl;
	std::cout << (array1 < array2) << std::endl;
	std::cout << (array1 == array2) << std::endl;
	std::cout << (array1 >= array3) << std::endl;
	array1.resize(12);
	std::cout << array1 << std::endl;
	array1.resize(3);
	std::cout << array1 << std::endl;
	std::cout << array1.capacity() << std::endl;
	array1.reserve(10);
	std::cout << array1.capacity() << std::endl;
	std::cout << array2.getLength() << std::endl;
	DynamicArray array5(array3);
	DynamicArray array6(std::move(array3));
	std::cout << array5 << std::endl << array6 << std::endl;
	array3 = array1 + array5;
	std::cout << array3 << std::endl;

	int res = 0;
	RingBuffer<int> queue(5);
	for (int i = 0; i < 5; i++) {
		queue.add(res++);
	}
	queue.poll();
	queue.poll();
	queue.add(2018);
	RingBuffer<int>::Iterator it(queue);
	it.start();
	while (!it.finish())
	{
		cout << it.getValue() << " ";
		it.next();
	}
	*/
	system("pause");
}

