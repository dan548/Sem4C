#pragma once
const int SIZE = 17;
template <typename K, typename V>
class LinkedHashTable {
private:
	template <typename K, typename V>
	struct Node {
		K key;
		V value;
		Node* next;
		Node* nextGlobal;
		Node(K k, V val) : key(k), value(val), next(nullptr), 
			nextGlobal(nullptr) {}
	};
	template <typename K, typename V>
	class LinkedHashEntry {
	private:
		Node<K,V>* beginEntry;
	public:
		LinkedHashEntry(K key, V value) {
			beginEntry = new Node(key, value);
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
	void add(K key, V value) {
		length++;
		Node<K,V>* tmp = new Node(key, value);
		end->nextGlobal = tmp;
		end = tmp;

	}
	void remove() {

	}
	V contains(K elem) {

	}
	void makeEmpty() {

	}
	bool isEmpty() {

	}
	int hashCode(int(*func) (K), K elem) {
		return func(elem);
	}
};
