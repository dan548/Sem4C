#pragma once
const int SIZE = 17;
template <typename T>
class LinkedHashTable {
private:
	template <typename T>
	struct Node {
		T value;
		Node* next;
		Node* nextGlobal;
		Node(T val) : value(val), next(nullptr), 
			nextGlobal(nullptr) {}
	};
	template <typename T>
	class LinkedHashEntry {
	private:
		Node<T>* beginEntry;
	public:
		LinkedHashEntry(T value) {
			Node<T>* tmp = new Node(value);
			beginEntry = endEntry = tmp;
		}
	};
	LinkedHashEntry* *table;
	size_t length;
	Node<T>* begin;
	Node<T>* end;

public:
	LinkedHashTable() {
		table = new LinkedHashEntry*[SIZE];
		current = nullptr;
		length = 0;
	}
	void add(T elem) {
		length++;
		Node<T>* tmp = new Node(elem);
		end->nextGlobal = tmp;
		end = tmp;

	}
	void remove() {

	}
	T find(T elem) {

	}
	void makeEmpty() {

	}
	bool isEmpty() {

	}
	int hashCode(int(*func) (T), T elem) {
		return func(elem);
	}
};
