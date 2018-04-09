#pragma once
#include "AbstractList.h"
#include "AbstractIterator.h"
template <typename T>
class List : public AbstractList
{
	struct Node {
		T value;
		Node* next;
		Node* prev;
	};
public:
	class ListIterator : public AbstractIterator {
		ListIterator(List &inputList) :list(&inputList) {}
		void start() {
			
		}
		T get() {

		}
		void next() {

		}
		void previous() {

		}
		bool isFinished() {

		}
	};

	List() {
		length = 0;
		buffer = nullptr;
		Node* tmp = new Node;
	}

	~List() {

	}

	void add(T elem) {

	}

	T remove() {

	}

	void makeEmpty() {

	}

	int length() {

	}

	AbstractIterator* findFirst(T elem) {

	}

	AbstractIterator* iterator() {

	}

	bool isEmpty() {

	}
private:
	Node* buffer;
	Node* current;
	int length;
};