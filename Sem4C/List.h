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
			if (!list->isEmpty()) list->current = list->buffer->next;
			else {
				throw EmptyListException("The list is empty.");
			}
			forward = true;
		}
		T get() {
			if (!list->isEmpty()) {
				if (list->current == list->buffer) {
					if (forward) {
						list->current = list->buffer->next;
					}
					else {
						list->current = list->buffer->prev;
					}
				}
				return list->current->value;
			}
			else {
				throw EmptyListException("The list is empty.");
			}
		}
		void next() {
			list->current = list->current->next;
			if (list->current == list->buffer && !forward) forward = true;
		}
		void previous() {
			list->current = list->current->prev;
			if (list->current == buffer) forward = false;
		}
		bool isFinished() {
			return list->current == list->buffer;
		}
		void operator++(int) {
			next();
		}
	private:
		List* list;
		bool forward;
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

	List(const List& list)
		:buffer(nullptr),
		current(nullptr),
		length(0)
	{
		Node<T> *tmp = new Node<T>;
		tmp->value = 0;
		tmp->next = nullptr;
		tmp->prev = nullptr;
		buffer = tmp;
		current = buffer;
		tmp = list.buffer->next;
		while (tmp != list.buffer) {
			add(tmp->value);
			tmp = tmp->next;
		}
	}

	List(List&& list)
		:buffer(list.buffer),
		current(list.current),
		length(list.length)
	{
		list.buffer = nullptr;
		list.current = nullptr;
		list.length = 0;
	}

	~List() {
		makeEmpty();
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
			tmp->next = current->next;
			current->next = tmp;
			tmp->next->prev = tmp;
		}
		length++;
		current = tmp;
	}

	T remove() {
		if (!isEmpty()) {
			Node<T> *tmp = current;
			current = tmp->prev;
			current->next = tmp->next;
			current->next->prev = current;
			delete tmp;
			length--;
		}
		else {
			throw EmptyListException("The list is empty.");
		}
	}

	void makeEmpty() {
		current = buffer->prev;
		while (!isEmpty()) {
			remove();
		}
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