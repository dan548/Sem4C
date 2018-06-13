#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Sem4C/BinaryTree.cpp"
#include "../Sem4C/BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool equals(std::vector<int>& vec1, std::vector<int>& vec2) {
	if (vec1.size() != vec2.size()) {
		return false;
	}
	for (int i = 0; i < vec1.size(); i++) {
		if (vec1[i] != vec2[i]) {
			return false;
		}
	}
	return true;
}

TEST_CLASS(UnitTestBinaryTree) {
	TEST_METHOD(BTAdd) {
		BinaryTree tree(1);

		Assert::ExpectException<InvalidWayInTreeException>([&]
		{
			tree.add("001010100", 9876);
		});
		Assert::ExpectException<InvalidWayInTreeException>([&]
		{
			tree.add("0110", 9876);
		});
		Assert::ExpectException<InvalidWayInTreeException>([&]
		{
			tree.add("000", 9876);
		});
	}
	TEST_METHOD(BTEven) {
		BinaryTree tree(9);
		tree.add("0", 1);
		tree.add("1", 2);
		tree.add("00", 3);
		tree.add("01", 4);
		tree.add("11", 5);
		Assert::AreEqual(tree.getQuantityOfEvenElements(), 2);
		tree.add("000", 8);
		tree.add("001", 110);
		tree.add("10", 18);
		tree.add("11", 77);
		Assert::AreEqual(tree.getQuantityOfEvenElements(), 5);

		tree.clear();
		tree.add("", 9);
		tree.add("0", 1);
		tree.add("1", 3);
		tree.add("01", 5);
		tree.add("11", 7);
		Assert::AreEqual(tree.getQuantityOfEvenElements(), 0);
	}
	TEST_METHOD(BTPositive) {
		BinaryTree tree(0);
		tree.add("0", 1);
		tree.add("1", 2);
		tree.add("00", 3);
		tree.add("01", 4);
		tree.add("11", 5);
		Assert::IsTrue(tree.areOnlyPositive());

		tree.add("0", -1);
		tree.add("00", -3);
		tree.add("01", -4);
		Assert::IsFalse(tree.areOnlyPositive());
	}
	TEST_METHOD(BTAverage) {
		BinaryTree tree(3);
		tree.add("0", 5);
		tree.add("01", 2);
		tree.add("00", 3);
		tree.add("000", 7);
		Assert::AreEqual((double)4, tree.getAverage());
		tree.clear();
		Assert::ExpectException<EmptyTreeException>([&]
		{
			tree.getAverage();
		});
	}
	TEST_METHOD(BTFind) {
		BinaryTree tree(0);
		tree.add("0", 1);
		tree.add("1", 2);
		tree.add("00", 3);
		tree.add("01", 4);
		tree.add("10", 5);
		tree.add("11", 6);
		tree.add("000", 7);
		tree.add("001", 8);
		tree.add("010", 9);
		tree.add("011", 10);
		tree.add("100", 11);
		tree.add("101", 12);
		tree.add("110", 13);
		tree.add("111", 14);

		std::vector<int> vec1;
		vec1.push_back(1);
		vec1.push_back(0);
		vec1.push_back(1);
		Assert::IsTrue(equals(vec1, tree.find(12)));

		std::vector<int> vec2;
		vec2.push_back(0);
		vec2.push_back(1);
		Assert::IsTrue(equals(vec2, tree.find(4)));

		std::vector<int> vec3;
		Assert::IsTrue(equals(vec3, tree.find(0)));

		Assert::ExpectException<ValueNotFoundException>([&]
		{
			tree.find(144);
		});
	}
	TEST_METHOD(BTBinarySearch) {
		BinaryTree tree(50);
		tree.add("0", 30);
		tree.add("00", 10);
		tree.add("01", 40);
		tree.add("010", 35);
		tree.add("011", 45);
		tree.add("1", 70);
		tree.add("10", 60);
		tree.add("11", 90);
		Assert::IsTrue(tree.isBinarySearchTree());

		tree.clear();
		tree.add("", 50);
		tree.add("0", 30);
		tree.add("00", 10);
		tree.add("01", 40);
		tree.add("010", 35);
		tree.add("011", 45);
		tree.add("1", 70);
		tree.add("10", 144);
		tree.add("11", 90);
		Assert::IsFalse(tree.isBinarySearchTree());

		tree.clear();
		tree.add("", 10);
		tree.add("0", 7);
		tree.add("00", 6);
		tree.add("01", 9);
		tree.add("000", 3);
		tree.add("0001", 4);
		tree.add("1", 12);
		tree.add("10", 11);
		tree.add("11", 14);
		Assert::IsTrue(tree.isBinarySearchTree());

		tree.clear();
		tree.add("", 50);
		tree.add("0", 10);
		tree.add("1", 90);
		Assert::IsTrue(tree.isBinarySearchTree());

		tree.clear();
		tree.add("", 10);
		tree.add("0", 7);
		tree.add("1", 6);
		Assert::IsFalse(tree.isBinarySearchTree());

		tree.clear();
		tree.add("", 6);
		tree.add("0", 3);
		tree.add("1", 10);
		tree.add("10", 4);
		tree.add("11", 14);
		Assert::IsFalse(tree.isBinarySearchTree());

		tree.clear();
		tree.add("", 6);
		tree.add("0", 3);
		tree.add("1", 10);
		tree.add("10", 14);
		tree.add("11", 4);
		Assert::IsFalse(tree.isBinarySearchTree());

		tree.clear();
		tree.add("", 0);
		tree.add("0", 3);
		tree.add("1", 10);
		tree.add("10", 14);
		tree.add("11", 4);
		Assert::IsFalse(tree.isBinarySearchTree());

		tree.clear();
		tree.add("", 8);
		Assert::IsTrue(tree.isBinarySearchTree());

		tree.clear();
		tree.add("", 10);
		tree.add("0", 8);
		tree.add("00", 6);
		tree.add("01", 12);
		tree.add("011", 9);
		tree.add("1", 11);
		tree.add("10", 7);
		tree.add("11", 13);
		Assert::IsFalse(tree.isBinarySearchTree());
	}
};