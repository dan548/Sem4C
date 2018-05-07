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
		Node<T>* current;
	public:
		LinkedHashEntry() {
			table = new LinkedHashEntry*[SIZE];
		}
	};
	LinkedHashEntry* *table;
public:
	LinkedHashTable() {

	}
};
