#include "stdafx.h"
#include "DynamicArray.h"


int main()
{
	DynamicArray array1(7);
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
	std::cout << b;
	system("pause");
}

