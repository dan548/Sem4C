#pragma once
#include "stdafx.h"

struct NoValueFoundException {
	std::string message;
	NoValueFoundException() {
		message = "Value not found.";
	}

	NoValueFoundException(const char* cMessage) {
		message = cMessage;
	}
};

struct EmptyHashTableException {
	std::string message;
	EmptyHashTableException(const char* cMessage) {
		message = cMessage;
	}
};

const int SIZE = 1 << 4;
template <typename K, typename V>
class LinkedHashTable {
public:
	struct Node {
		K key;
		V value;
		Node* next;
		Node* nextGlobal;
		Node* prevGlobal;
		Node(K k, V val) : key(k), value(val), next(nullptr),
			nextGlobal(nullptr), prevGlobal(nullptr) {}
	};
private:
	class LinkedHashEntry {
	public:
		LinkedHashEntry(Node* elem) {
			beginEntry = elem;
		}
		void addEntry(Node* elem) {
			if (beginEntry == nullptr) beginEntry = elem;
			Node* tmp = beginEntry;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			if (tmp->key == elem->key) {
				tmp->value = elem->value;				
			}
			else {
				tmp->next = elem;
			}			
		}
		Node* beginEntry = nullptr;
	};
	LinkedHashEntry* *table;
	size_t length;
	Node* begin;
	Node* end;
	int(*func) (const K&);
	int size;
	int hashCode(const K& elem) {
		return func(elem) % size;
	}
public:
	LinkedHashTable(int(*f) (const K&), int size = SIZE):
	size(size), begin(nullptr), end(nullptr), length(0), func(f){
		table = new LinkedHashEntry*[size];
		for (int i = 0; i < size; i++) {
			table[i] = nullptr;
		}
	}
	void push(const K& key, const V& value) {
		length++;
		bool repeat = false;
		Node* tmp = new Node(key, value);
		int hash = hashCode(key);
		if (table[hash] == nullptr) {
			table[hash] = new LinkedHashEntry(tmp);
		}
		else {
			Node* tmp2 = table[hash]->beginEntry;
			if (tmp2 != nullptr) {
				if (tmp2->key == key) {
					length--;
					repeat = true;
				}
				else {
					while (tmp2->next != nullptr) {
						if (tmp2->next->key != key) {
							tmp2 = tmp2->next;
							continue;
						}
						else {
							length--;
							repeat = true;
							break;
						}
					}
				}
			}
			table[hash]->addEntry(tmp);
		}
		if (!repeat) {
			if (begin == nullptr) {
				begin = tmp;
			}
			else {
				if (end == nullptr) {
					tmp->prevGlobal = begin;
					end = tmp;
					begin->nextGlobal = end;
				}
				else {
					tmp->prevGlobal = end;
					end->nextGlobal = tmp;
					end = tmp;
				}
			}
		}
	}
	V pop(const K& elem) {
		if (isEmpty()) throw EmptyHashTableException("The table is empty!");
		int hash = hashCode(elem);
		if (table[hash] != nullptr) {
			Node* tmp = table[hash]->beginEntry;
			Node* tmp2 = tmp;
			if (tmp->key == elem) {
				table[hash]->beginEntry = tmp->next;
			}
			else {
				while (tmp2->next != nullptr) {
					if (tmp2->next->key != elem) {
						tmp2 = tmp2->next;
						continue;
					}
					else {
						tmp = tmp2->next;
						tmp2->next = tmp->next;
					}
				}
				throw NoValueFoundException();
			}
			if (tmp->prevGlobal == nullptr) {
				begin = begin->nextGlobal;
				begin->prevGlobal = nullptr;
			}
			else {
				if (tmp == end) {
					end = tmp->prevGlobal;
				}
				tmp->prevGlobal->nextGlobal = tmp->nextGlobal;
			}
			V valuePop = tmp->value;
			delete tmp;
			length--;
			return valuePop;
		}
		else {
			throw NoValueFoundException();
		}
	}
	V get(const K& elem) {
		if (isEmpty()) throw EmptyHashTableException("The table is empty!");
		int hash = hashCode(elem);
		if (table[hash] != nullptr) {
			Node* tmp = table[hash]->beginEntry;
			Node* tmp2 = tmp;
			if (tmp->key == elem) {
				V value = tmp->value;
				return value;
			}
			else {
				while (tmp2->next != nullptr) {
					if (tmp2->next->key != elem) {
						tmp2 = tmp2->next;
						continue;
					}
					else {
						V value = tmp->value;
						return value;
					}
				}
				throw NoValueFoundException();
			}
		}
		else {
			throw NoValueFoundException();
		}
	}
	void makeEmpty() {
		Node* tmp = end;
		while (!isEmpty()) {
			if (tmp->prevGlobal != nullptr) {
				tmp = tmp->prevGlobal;
				end = tmp;
				delete tmp->nextGlobal;
			}
			else {
				delete tmp;
			}
			length--;	
		}
		begin = nullptr;
		end = nullptr;
		for (int i = 0; i < size; i++) {
			table[i] = nullptr;
		}
	}
	bool isEmpty() {
		return length == 0;
	}
};
