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
		}
		T get() {
			return list->current->value;
		}
		void next() {
			list->current = list->current->next;
		}
		void previous() {
			list->current = list->current->prev;
		}
		bool isFinished() {
			return list->current == list->buffer;
		}
	private:
		List* list;
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
		delete current;
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

	int getLength() {
		return length;
	}

	ListIterator* findFirst(T elem) {
		ListIterator* listIter = iterator();
		listIter->start();
		while (!listIter->isFinished()) {
			if (listIter->get() == elem) return listIter;
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