#include "stdafx.h"
#include "Dictionary.h"

Dictionary::Dictionary() {

}

Dictionary::Dictionary(std::string word)
{
	root = new BalElem(word);
}

Dictionary::Dictionary(const Dictionary &other)
{
	root = copy(other.root);
}


Dictionary::Dictionary(Dictionary && trash)
{
	root = trash.root;
	trash.root = nullptr;
}

Dictionary::~Dictionary()
{
	clear();
}

Dictionary & Dictionary::operator=(const Dictionary &other)
{
	if (this == &other) {
		return *this;
	}
	clear();
	root = copy(other.root);
	return *this;
}

Dictionary & Dictionary::operator=(Dictionary &&trash)
{
	if (this == &trash) {
		return *this;
	}
	root = trash.root;
	trash.root = nullptr;
	return *this;
}

int Dictionary::find(std::string word)
{
	BalElem* elem = findElem(root, word);
	if (elem) {
		return elem->entryCount;
	}
	else {
		return 0;
	}
}

void Dictionary::add(std::string word)
{
	addElem(root, word);
}

void Dictionary::remove(std::string word)
{
	delElem(root, word);
}

void Dictionary::clear()
{
	clear(root);
}

int Dictionary::getCount()
{
	return size(root);
}

Dictionary::BalElem* Dictionary::findElem(BalElem* root, std::string word)
{
	if (!root) { return nullptr; }
	if (word == root->word) { return root; }
	BalElem* res = findElem(root->left, word);
	if (!res) { return res; }
	return findElem(root->right, word);
}

void Dictionary::lexicographicalPrintWithEntry(BalElem *root, std::ostream &os)
{
	if (!root) {
		return;
	}
	lexicographicalPrintWithEntry(root->left, os);
	os << root->word << " " << root->entryCount << "\n";
	lexicographicalPrintWithEntry(root->right, os);
}

int Dictionary::size(BalElem *root)
{
	if (!root) {
		return 0;
	}
	return root->entryCount + size(root->left) + size(root->right);
}

std::ostream & operator<<(std::ostream &os, Dictionary &dict)
{
	dict.lexicographicalPrintWithEntry(dict.root, os);
	return os;
}

Dictionary::BalElem* Dictionary::copy(BalElem* root) {
	if (!root) {
		return nullptr;
	}
	return new BalElem(root->word, copy(root->left), copy(root->right), root->entryCount);
}

void Dictionary::clear(BalElem *&node)
{
	if (node == nullptr) {
		return;
	}
	clear(node->left);
	clear(node->right);
	delete node;
	node = nullptr;
}

void Dictionary::RRotation(BalElem *&pA, BalElem *&pB)
{
	pA->bal = 0;
	pB->bal = 0;
	pA->left = pB->right;
	pB->right = pA;
	pA = pB;
}

void Dictionary::LRRotation(BalElem *&pA, BalElem *&pB)
{
	BalElem *pC = pB->right;
	if (pC->bal > 0) {
		pA->bal = pC->bal = 0;
		pB->bal = -1;
	}
	else {
		pB->bal = pC->bal = 0;
		pA->bal = 1;
	}
	pA->left = pC->right;
	pB->right = pC->left;
	pC->left = pB;
	pC->right = pA;
	pA = pC;
}

void Dictionary::LRotation(BalElem *&pA, BalElem *&pB)
{
	pA->bal = 0;
	pB->bal = 0;
	pA->right = pB->left;
	pB->left = pA;
	pA = pB;
}

void Dictionary::RLRotation(BalElem *&pA, BalElem *&pB)
{
	BalElem *pC = pB->left;
	if (pC->bal > 0) {
		pB->bal = pC->bal = 0;
		pA->bal = -1;
	}
	else {
		pA->bal = pC->bal = 0;
		pB->bal = 1;
	}
	pA->right = pC->left;
	pB->left = pC->right;
	pC->left = pA;
	pC->right = pB;
	pA = pC;
}

bool Dictionary::balanceAddLeft(BalElem *&pA)
{
	switch (pA->bal) {
	case 1:
		pA->bal = 0;
		return false;
	case 0:
		pA->bal = -1;
		return true;
	case -1: {
		BalElem* pB = pA->left;
		if (pB->bal < 0) {
			RRotation(pA, pB);
			return false;
		}
		else {
			LRRotation(pA, pB);
			return false;
		}
	}
	}
}

bool Dictionary::balanceAddRight(BalElem *&pA)
{
	switch (pA->bal) {
	case -1:
		pA->bal = 0;
		return false;
	case 0:
		pA->bal = 1;
		return true;
	case 1: {
		BalElem* pB = pA->right;
		if (pB->bal > 0) {
			LRotation(pA, pB);
			return false;
		}
		else {
			RLRotation(pA, pB);
			return false;
		}
	}
	}
}

bool Dictionary::balanceDelLeft(BalElem *&pA)
{
	switch (pA->bal) {
	case -1:
		pA->bal = 0;
		return false;
	case 0:
		pA->bal = 1;
		return true;
	case 1: {
		BalElem* pB = pA->right;
		if (pB->bal < 0) {
			RLRotation(pA, pB);
			return false;
		}
		else {
			LRotation(pA, pB);
			return false;
		}
	}
	}
}

bool Dictionary::balanceDelRight(BalElem *&pA)
{
	switch (pA->bal) {
	case 1:
		pA->bal = 0;
		return false;
	case 0:
		pA->bal = -1;
		return true;
	case -1: {
		BalElem* pB = pA->left;
		if (pB->bal > 0) {
			LRRotation(pA, pB);
			return false;
		}
		else {
			RRotation(pA, pB);
			return false;
		}
	}
	}
}

bool Dictionary::addElem(BalElem *& root, std::string x)
{
	if (!root) {
		root = new BalElem(x);
		return true;
	}
	if (x.compare(root->word) < 0) {
		if (addElem(root->left, x)) {
			return balanceAddLeft(root);
		}
		return false;
	}
	if (x.compare(root->word) > 0) {
		if (addElem(root->right, x)) {
			return balanceAddRight(root);
		}
		return false;
	}
	if (x.compare(root->word) == 0) {
		root->entryCount++;
		return false;
	}
	return false;
}

bool Dictionary::del2(BalElem *& rootLeft, BalElem *& toDel)
{
	if (rootLeft->right) {
		if (del2(rootLeft->right, toDel)) {
			return balanceDelRight(rootLeft);
		}
		return false;
	}
	toDel->word = rootLeft->word;
	toDel = rootLeft;
	rootLeft = rootLeft->left;
	return true;
}

bool Dictionary::delElem(BalElem *&root, std::string x)
{
	if (!root) { return false; }
	if (x.compare(root->word) < 0) {
		if (delElem(root->left, x)) {
			return balanceDelLeft(root);
		}
		return false;
	}
	if (x.compare(root->word) > 0) {
		if (delElem(root->right, x)) {
			return balanceDelRight(root);
		}
		return false;
	}
	if (root->entryCount > 1) {
		root->entryCount--;
	}
	else {
		BalElem *pDel = root;
		if (!root->right) {
			root = root->left;
			delete pDel;
			return true;
		}
		if (!root->left) {
			root = root->right;
			delete pDel;
			return true;
		}
		if (del2(root->left, pDel)) {
			return balanceDelLeft(root);
		}
		return false;
	}
	
}
