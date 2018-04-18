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
class List : public AbstractList<T>
{
public:
	class ListIterator : public AbstractIterator<T> {
	public:
		ListIterator(List* inputList) :list(inputList) {}
		void start() {
			list->current = list->buffer->next;
			count = 0;
		}
		T get() {
			return list->current->value;
		}
		void next() {
			list->current = list->current->next;
			if (isFinished()) count = 1;
			else count++;
		}
		void previous() {
			list->current = list->current->prev;
			if (count == 0) count = list->getLength() - 1;
			else count--;

		}
		bool isFinished() {
			return count == list->getLength();
		}
	private:
		List* list;
		int count;
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
		delete buffer;
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
		//переделать
		if (getLength() > 0) {
			Node<T> *tmp = current;
			current = tmp->prev;
			tmp->next->prev = current;
			T res = tmp->value;
			delete tmp;
			length--;
			return res;
		}
		else {
			return 0;
		}
	}

	void makeEmpty() {
		//
	}

	int getLength() {
		return length;
	}

	ListIterator* findFirst(T elem) {
		ListIterator* listIter = iterator();
		listIter->start();
		while (!listIter->isFinished()) {
			if (listIter->get() == elem) {
				return listIter;
			}
			else {
				listIter->next();
			}
		}
		return nullptr;
	}

	ListIterator* iterator() {
		ListIterator* listIter = new ListIterator(this);
		return listIter;
	}

	bool isEmpty() {
		return length == 0;
	}
private:
	Node<T>* buffer;
	Node<T>* current;
	int length;
};