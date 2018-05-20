#pragma once
const int SIZE = 16;
template <typename T>
class LinkedHashTable {
private:
	template <typename T>
	struct Node {
		T value;
		Node* next;
		Node(T val) : value(val), next(nullptr) {}
	};
	template <typename T>
	class LinkedHashEntry {
	private:
		size_t length;
		Node<T>* start;
	public:
		LinkedHashEntry(T value) {
			length = 1;
			Node<T> *tmp = new Node<T>(value);
			start = tmp;
		}
	};
	LinkedHashEntry** table;

public:
	LinkedHashTable() {
		table = new LinkedHashEntry*[SIZE];
	}
};
