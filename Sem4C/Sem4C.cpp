#include "stdafx.h"
#include "DynamicArray.h"
#include "RingBuffer.h"
#include "List.h"
#include "AbstractIterator.h"
#include "LinkedHashTable.h"
#include "Dictionary.h"
#include "BinaryTree.h"
using namespace std;

int f(const int& key) {
	return key + 145;
}

int main()
{
	/*LinkedHashTable<int, double> table(f, 8);
	table.push(-1, 0.13);
	table.push(-3, 0.39);
	table.push(5, 1.48);
	table.push(14, 2.45);
	double kek = table.get(5);
	table.push(18, 6.45);
	table.makeEmpty();
	table.push(-1, 0.13);
	table.push(1, 2.32);
	table.push(9, 3.45);
	table.push(2, 6.78);
	double sas = table.pop(1);
	table.push(4, 1.14);
	double a = table.pop(4);
	table.push(17, 11.13);
	table.push(-1, 481516);
	table.push(9, 13);
	cout << table.pop(-1) << endl;*/	
	BinaryTree tree(5);
	tree.add("0", 3);
	tree.add("1", 7);
	cout << tree.isBinarySearchTree() << endl;
	/*Dictionary dict;
	dict.add("alpha");
	dict.add("bravo");
	dict.add("human");
	dict.add("surrender");
	dict.add("despair");
	dict.add("foolish");
	dict.add("human");//2
	dict.add("sony");
	dict.add("laptop");
	dict.add("despair");//2
	dict.add("rococo");
	dict.add("bloom");
	dict.add("despair");//3
	dict.add("star");
	dict.add("wind");
	dict.add("always");	
	dict.remove("despair");
	dict.remove("rococo");
	cout << dict;*/
	system("pause");
}

