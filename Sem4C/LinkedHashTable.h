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
	public:
		LinkedHashEntry(Node* elem) {
			beginEntry = elem;
		}
		void addEntry(Node* elem) {
			Node<K, V>* tmp = beginEntry;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = elem;
		}
		Node<K, V>* beginEntry;
	};
	int hashCode(const K& elem) {
		return func(elem) % SIZE;
	}
	LinkedHashEntry* *table;
	size_t length;
	Node<K,V>* begin;
	int(*func) (const K&);
public:
	LinkedHashTable(int(*f) (const K&)) {
		table = new LinkedHashEntry*[SIZE];
		current = nullptr;
		length = 0;
		func = f;
	}
	void add(const K& key, const V& value) {
		length++;
		Node<K,V>* tmp = new Node(key, value);
		end->nextGlobal = tmp;
		end = tmp;
		int hash = hashCode(key);
		if (table[hash] == nullptr) {
			table[hash] = new LinkedHashEntry(tmp);
		}
		else {
			table[hash]->addEntry(tmp);
		}
	}
	void remove(const K& elem) {
		int hash = hashCode(elem);
		if (table[hash] != nullptr) {
			Node<K, V>* tmp = table[hash]->beginEntry;
		}
	}
	V get(const K& elem) {

	}
	void makeEmpty() {

	}
	bool isEmpty() {

	}
};
