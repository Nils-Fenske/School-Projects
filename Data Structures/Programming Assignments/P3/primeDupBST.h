// Nils Fenske
// 11-1-15
// Programming Assignment 3 

#ifndef PRIMEDUPBST
#define PRIMEDUPBST

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct TNode {

	int data;
	int dupCount;
	TNode* left;
	TNode* right;
};

class primeDupBST {

private:

	TNode* root;

	primeDupBST(const primeDupBST&);
	void operator= (const primeDupBST&);

	bool isPrime(int number);
	void destroy(TNode* &root);
	void inorder(TNode* trav);
	void preorder(TNode* trav);
	bool isEmpty();
	void process(TNode* node);

public:

	primeDupBST();
	~primeDupBST();
	bool search(int number, TNode* &start);
	void insert(int value);
	void remove(int value);
	void inorder();
	void preorder();
	void clear();
	
};

#endif