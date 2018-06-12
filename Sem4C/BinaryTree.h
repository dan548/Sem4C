#pragma once
#include <vector>

struct InvalidWayInTreeException {
	std::string message;
	InvalidWayInTreeException() {
		message = "The way is invalid";
	}

	InvalidWayInTreeException(const char* cMessage) {
		message = cMessage;
	}
};

struct ValueNotFoundException {
	std::string message;
	ValueNotFoundException() {
		message = "Value not found";
	}

	ValueNotFoundException(const char* cMessage) {
		message = cMessage;
	}
};

struct EmptyTreeException {
	std::string message;
	EmptyTreeException() {
		message = "The tree is empty.";
	}

	EmptyTreeException(const char* cMessage) {
		message = cMessage;
	}
};

class BinaryTree
{
	struct TreeElem {
		int info;
		TreeElem *left, *right;
		TreeElem(int x, TreeElem *pLeft = 0, TreeElem *pRight = 0) :
			info(x), left(pLeft), right(pRight) {}
	};
public:
	BinaryTree(int);
	BinaryTree(const BinaryTree&);
	BinaryTree(BinaryTree&&);
	~BinaryTree();
	void add(const char*, int);
	BinaryTree& operator= (const BinaryTree&);
	BinaryTree& operator= (BinaryTree&&);
	friend std::ostream& operator <<(std::ostream&, BinaryTree&);
	void printTree();
	void clear();
	bool isBinarySearchTree();
	int getQuantityOfEvenElements();
	bool areOnlyPositive();
	void cutLeaves();
	double getAverage();
	std::vector<int> find(int);
private:
	TreeElem* root;
	bool add2(TreeElem*&, const char*, int, int);
	void printTree(const TreeElem*, int);
	void clear(TreeElem*&);
	TreeElem* copyNode(TreeElem*);
	void printEl(TreeElem*, std::ostream &);
	bool isBinarySearchTree(TreeElem*, bool, int, int, bool);
	int getQuantityOfEvenElements(TreeElem*);
	bool areOnlyPositive(TreeElem*);
	bool cutLeaves(TreeElem*&);
	double getAverage(TreeElem*, int&);
	bool find(TreeElem*, int, std::vector<int>&);
	int levels;
};

