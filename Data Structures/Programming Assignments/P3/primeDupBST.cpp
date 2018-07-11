// Nils Fenske
// 11-1-15
// Programming Assignment 3

#include "primeDupBST.h"
#include <stack>

void primeDupBST::operator=(const primeDupBST &) {}

bool primeDupBST::isPrime(int number) {

	for (int i = 2; i < number; i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

void primeDupBST::destroy(TNode* &root) {

	if (!root) return;
	destroy(root->left);
	destroy(root->right);
	delete root;
}

primeDupBST::primeDupBST() { root = nullptr; }

primeDupBST::~primeDupBST() { destroy(root); }

bool primeDupBST::search(int number, TNode* &start) {

	TNode* locator = start;
	while (locator) {
		if (number == locator->data) {
			return true;
		}
		if (number < locator->data) {
			locator = locator->left;
		}
		if (number > locator->data) {
			locator = locator->right;
		}
	}
	return false;
}

void primeDupBST::clear() {

	destroy(root);
	root = nullptr;
}

void primeDupBST::insert(int value) {

	TNode* prev = NULL;
	TNode* auxilary = root;
	bool exists = search(value, auxilary);
	bool prime = isPrime(value);

	if (exists && prime) {
		auxilary->dupCount++;
		return;
	}
	if (exists && !prime) {
		return;
	}

	TNode* insert = new TNode;
	insert->data = value;
	insert->dupCount = 0;
	insert->left = NULL;
	insert->right = NULL;

	while (auxilary) {
		prev = auxilary;
		if (value < auxilary->data) {
			auxilary = auxilary->left;
		}
		if (value > auxilary->data) {
			auxilary = auxilary->right;
		}
	}

	if (!prev) {
		root = insert;
	}
	if (value < prev->data) {
		prev->left = insert;
	}
	if (value > prev->data) {
		prev->right = insert;
	}
	return;
}

void primeDupBST::inorder() {
	inorder(root);
}

void primeDupBST::inorder(TNode* trav) {

	if (!trav) return;
	inorder(trav->left);
	process(trav);
	inorder(trav->right);
	return;
}

void primeDupBST::preorder() {
	preorder(root);
}

void primeDupBST::preorder(TNode* trav) {

	TNode* top;
	stack <TNode*> s;

	if (!trav) return;
	s.push(trav);

	while (!s.empty()) {
		top = s.top();
		s.pop();
		process(top);
		if (top->right) s.push(top->right);
		if (top->left) s.push(top->left);
	}
}

void primeDupBST::process(TNode* output) {

	
	ofstream orderPrint;
	orderPrint.open("P3out.txt");

	orderPrint << output->data;
	cout << output->data;
	if (output->dupCount > 0) {
		orderPrint << " Duplicates: " << output->dupCount << endl;
		cout << " Duplicates: " << output->dupCount << endl;
	}
	orderPrint << endl;
	cout << endl;

	orderPrint.close();
}

void primeDupBST::remove(int value) {

	TNode* removalPTR = nullptr;
	search(value, removalPTR);
	TNode* trav = removalPTR;

	if (removalPTR->data == value) {
		if (removalPTR->dupCount > 0) {
			removalPTR->dupCount--;
		}
		else if (trav->left) {
			trav = trav->left;
			while (trav->right) {
				trav = trav->right;
			}
			removalPTR->data = trav->data;
			removalPTR->dupCount = trav->dupCount;
			delete trav;
		}
		else if (trav->right) {
			trav = trav->right;
			while (trav->left) {
				trav = trav->left;
			}
			removalPTR->data = trav->data;
			removalPTR->dupCount = trav->dupCount;
		}
		else {
			delete removalPTR;
		}
	}
}

bool primeDupBST:: isEmpty(){

	return !root;
}