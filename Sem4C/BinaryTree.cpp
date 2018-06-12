#include "stdafx.h"
#include "BinaryTree.h"


BinaryTree::BinaryTree(int rootInfo)
{
	root = new TreeElem(rootInfo);
	levels = 1;
}

BinaryTree::BinaryTree(const BinaryTree &other)
{
	root = copyNode(other.root);
	levels = other.levels;
}


BinaryTree::BinaryTree(BinaryTree&& trash)
{
	root = trash.root;
	levels = trash.levels;
	trash.root = nullptr;
	trash.levels = 0;
}

BinaryTree::~BinaryTree()
{
	clear();
}

void BinaryTree::add(const char *way, int x)
{
	if (strlen(way) > levels) {
		throw InvalidWayInTreeException();
	}
	add2(root, way, x, 0);
	if (strlen(way) == levels) {
		levels++;
	}
}

BinaryTree & BinaryTree::operator=(const BinaryTree &other)
{
	if (this == &other) {
		return;
	}
	clear();
	root = copyNode(other.root);
	return *this;
}

BinaryTree & BinaryTree::operator=(BinaryTree && trash)
{
	if (this == &trash) {
		return *this;
	}
	root = trash.root;
	levels = trash.levels;
	trash.root = nullptr;
	trash.levels = 0;
}

void BinaryTree::printTree()
{
	printTree(root);
}

void BinaryTree::clear()
{
	clear(root);
	levels = 0;
}

bool BinaryTree::isBinarySearchTree()
{
	return isBinarySearchTree(root->left, 0, root->info, root->info, 0) &&
		isBinarySearchTree(root->right, 1, root->info, root->info, 0);
}

int BinaryTree::getQuantityOfEvenElements()
{
	return getQuantityOfEvenElements(root);
}

bool BinaryTree::areOnlyPositive()
{
	return areOnlyPositive(root);
}

void BinaryTree::cutLeaves()
{
	cutLeaves(root);
}

double BinaryTree::getAverage()
{
	if (levels == 0) {
		throw EmptyTreeException();
	}
	int count = 0;
	return getAverage(root, count) / count;
}

std::vector<int> BinaryTree::find(int x)
{
	std::vector<int> way;
	find(root, x, way);
	return way;
}

bool BinaryTree::add2(TreeElem *& node, const char *way, int position, int x)
{
	if (position == strlen(way)) {
		if (root == nullptr) {
			root = new TreeElem(x);
		}
		else {
			root->info = x;
		}
		return true;
	}
	if (root == nullptr) {
		throw InvalidWayInTreeException();
	}
	if (way[position] == '0') {
		if (add2(root->left, way, x, ++position)) {
			return true;
		}
	}
	if (way[position] == '1') {
		if (add2(root->right, way, x, ++position)) {
			return true;
		}
	}
	return false;
}

void BinaryTree::printTree(const TreeElem *root, int tabs = 0)
{
	if (!root) { return; }
	for (int i = 0; i < tabs; i++) {
		std::cout << "\t";
	}
	std::cout << root->info << std::endl;
	printTree(root->left, ++tabs);
	printTree(root->right, ++tabs);
}

void BinaryTree::clear(TreeElem *& node)
{
	if (node == nullptr) {
		return;
	}
	clear(node->left);
	clear(node->right);
	delete node;
	node = nullptr;
}

BinaryTree::TreeElem* BinaryTree::copyNode(TreeElem* node)
{
	if (!node) {
		return nullptr;
	}
	return new TreeElem(node->info, copyNode(node->left), copyNode(node->right));
}

void BinaryTree::printEl(TreeElem *node, std::ostream &os)
{
	if (!node) {
		return;
	}
	printEl(node->left, os);
	os << node->info << " ";
	printEl(node->right, os);
}

bool BinaryTree::isBinarySearchTree(TreeElem *node, bool side, int less, int more, bool goneOneDirection)
{
	if (!node) return true;
	if (goneOneDirection) {
		if (side) {
			if (node->info >= less) {
				return isBinarySearchTree(node->left, 0, less, node->info, 0) &&
					isBinarySearchTree(node->right, 1, more, more, 1);
			}
		}
		else {
			if (node->info < more) {
				return isBinarySearchTree(node->left, 0, less, node->info, 1) &&
					isBinarySearchTree(node->right, 1, more, more, 0);
			}
		}
	}
	else {
		if (side) {
			if (node->info >= less && node->info < more) {
				return isBinarySearchTree(node->left, 0, less, node->info, 0) &&
					isBinarySearchTree(node->right, 1, node->info, more, 0);
			}
		}
		else {
			if (node->info < more && node->info > less) {
				return isBinarySearchTree(node->left, 0, node->info, more, 0) &&
					isBinarySearchTree(node->right, 1, less, node->info, 0);
			}
		}
	}
	return false;
}

int BinaryTree::getQuantityOfEvenElements(TreeElem *root)
{
	if (!root) {
		return 0;
	}
	if (root->info % 2 == 0) {
		return 1 + getQuantityOfEvenElements(root->left) + getQuantityOfEvenElements(root->right);
	}
	else {
		return getQuantityOfEvenElements(root->left) + getQuantityOfEvenElements(root->right);
	}
}

bool BinaryTree::areOnlyPositive(TreeElem *root)
{
	if (!root) {
		return true;
	}
	if (root->info >= 0) {
		return true && areOnlyPositive(root->left) && areOnlyPositive(root->right);
	}
	else {
		return false;
	}
}

bool BinaryTree::cutLeaves(TreeElem *&root)
{
	if (!root) { return false; }
	if (!root->left && !root->right) {
		delete root;
		root = nullptr;
		return true;
	}
	if (cutLeaves(root->left)) {
		root->left = nullptr;
	}
	if (cutLeaves(root->right)) {
		root->right = nullptr;
	}
	return false;
}

double BinaryTree::getAverage(TreeElem *root, int &count)
{
	if (!root) {
		return 0;
	}
	count++;
	return root->info + getAverage(root->left, count) + getAverage(root->right, count);
}

bool BinaryTree::find(TreeElem *root, int x, std::vector<int> &way)
{
	if (!root) {
		way.pop_back();
		return false;
	}
	if (root->info == x) {
		return true;
	}
	way.push_back(0);
	if (root->info == x || find(root->left, x, way)) {
		return true;
	}
	way.push_back(1);
	if (!find(root->right, x, way)) {
		if (way.size() == 0) {
			throw ValueNotFoundException();
		}
		way.pop_back();
		return false;
	}
}

std::ostream & operator<<(std::ostream &os, BinaryTree &tree)
{
	tree.printEl(tree.root, os);
	return os;
}
