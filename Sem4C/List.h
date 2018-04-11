#pragma once
#include "AbstractList.h"
#include "AbstractIterator.h"

template <typename T>
struct Node {
	T value;
	Node* next;
	Node* prev;
};

template <typename T>
class List : public AbstractList
{
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
		Node<T> *tmp = new Node<T>;
		tmp->value = 0;
		tmp->next = nullptr;
		tmp->prev = nullptr;
		buffer = tmp;
		current = buffer;
	}

	~List() {
		
	}

	void add(T elem) {
		Node<T> *tmp = new Node<T>;
		tmp->prev = current;
		tmp->value = elem;
		if (isEmpty()) {
			tmp->next = buffer;
			buffer->next = tmp;
			buffer->prev = tmp;
		}
		else {
			if (current->next != buffer) {
				tmp->next = current->next;
			}
			else {
				tmp->next = current->next->next;
			}
			tmp->next->prev = tmp;
			current->next = tmp;
		}
		current = tmp;
		length++;
	}

	T remove() {
		Node<T> *tmp = current;
		current = tmp->prev;
		tmp->next->prev = current;
		T res = tmp->value;
		delete tmp;
		length--;
		return res;
	}

	void makeEmpty() {
		Node<T> *first = buffer->next;
		while (!isEmpty()) {
			Node<T> *tmp = first->next;
			delete first;
			first = tmp;
			length--;
		}
	}

	int length() {
		return length;
	}

	AbstractIterator* findFirst(T elem) {

	}

	AbstractIterator* iterator() {

	}

	bool isEmpty() {
		return length == 0;
	}
private:
	Node* buffer;
	Node* current;
	int length;
};