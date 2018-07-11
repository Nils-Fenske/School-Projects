// Nils Fenske
// 12/2/2015
// Programming Assignment 5 

#ifndef HASHTABLE
#define HASHTABLE

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class HashTable {

	struct HNode {

		string word;
		int count;
		HNode* next;
	};

	HNode** table;								// the hash table is an array of pointers
	int numWords;
	int hash(string word);
	string filter(string word);
	HashTable(const HashTable&);				// copying supressed
	void operator=(const HashTable&);			// overloaded assignment operator

public:

	HashTable();
	~HashTable();
	void insert(string word);
	int search(string word);
	int getCount();
};

#endif HASHTABLE