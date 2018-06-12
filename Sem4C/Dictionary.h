#pragma once
#include<string>
class Dictionary {
public:
	Dictionary();
	Dictionary(std::string);
	Dictionary(const Dictionary&);
	Dictionary(Dictionary&&);
	~Dictionary();
	Dictionary& operator=(const Dictionary&);
	Dictionary& operator=(Dictionary&&);
	int find(std::string);
	void add(std::string);
	void remove(std::string);
	void clear();
	int getCount();
	friend std::ostream& operator<<(std::ostream &, Dictionary&);
private:
	struct BalElem {
		std::string word;
		BalElem* left;
		BalElem* right;
		int entryCount;
		int bal;
		BalElem(std::string nWord, BalElem* nLeft = nullptr, BalElem* nRight = nullptr, int entries = 1, int balance = 0) : word(nWord), left(nLeft), right(nRight), entryCount(entries), bal(balance) {}
	};
	BalElem* findElem(BalElem*, std::string);
	void lexicographicalPrintWithEntry(BalElem*, std::ostream &);
	int size(BalElem*);
	BalElem* copy(BalElem*);
	void clear(BalElem*&);
	void RRotation(BalElem*&, BalElem*&);
	void LRRotation(BalElem*&, BalElem*&);
	void LRotation(BalElem*&, BalElem*&);
	void RLRotation(BalElem*&, BalElem*&);
	bool balanceAddLeft(BalElem*&);
	bool balanceAddRight(BalElem*&);
	bool balanceDelLeft(BalElem*&);
	bool balanceDelRight(BalElem*&);
	bool addElem(BalElem*&, std::string);
	bool del2(BalElem*&, BalElem*&);
	bool delElem(BalElem*&, std::string);
	BalElem* root;
};

