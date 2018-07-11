// Nils Fenske
// 12/2/2015
// Programming Assignment 5 

#include "HashTable.h"

const int tableSize = 20000;

int HashTable::hash(string word) {							// hash the word to a unique value 

	int count = 0;

	for (int unsigned i = 0; i < word.length(); i++) {
		count += word[i];
	}

	return count % tableSize;
}

string HashTable::filter(string word) {

	string temp = "";

	for (int unsigned i = 0; i < word.length(); i++) {		// set all the characters to lowercase letters
		if (word[i] > 64 && word[i] < 91) {
			word[i] = word[i] + 32;
		}
		if (word[i] > 96 && word[i] < 123) {				// add only letters to the finished string. No punctuation.
			temp += word[i];
		}
	}
	return temp;
}

void HashTable::operator=(const HashTable&) {};				// overloaded assignment operator

HashTable::HashTable() {									// constructor sets all indexes of table to NULL
	table = new HNode*[tableSize];
	for (int i = 0; i < tableSize; i++) {
		table[i] = NULL;
	}
	numWords = 0;											// initial number of unique words in table set to 0
}

HashTable::~HashTable() {									// destructor walks through each link list and then deletes table
	HNode* temp;
	
	for (int i = 0; i < tableSize; i++) {
		while (table[i]) {
			temp = table[i]->next;
			delete table[i];
			table[i] = temp;
		}
	}
}

void HashTable::insert(string word) {						// inserts a word into the table

	word = filter(word);									// returns a string of lowercase letters

	if (word.length() > 4) {								// will not allow a string shorter than 5 to be entered

		int key = hash(word);							
		HNode* temp = table[key];							// hashed word becomes index for table

		while (temp) {

			if (temp->word == word) {						// if the wrod already exists, increase count and return
				temp->count++;
				return;
			}
			temp = temp->next;								// walks through array
		}
		HNode* node = new HNode();							// if never found, enter a new node
		node->word = word;
		node->count = 1;
		node->next = table[key];
		table[key] = node;
		numWords++;											// since not a duplicate, number of words increases

	}
}

int HashTable::search(string word) {						// locates a word and returns its count of occurences

	int found = 0;
	HNode* walker;
	word = filter(word);
	int key = hash(word);

	if (!table[key]) {
		return found;										// will return 0 (false)
	}
	else {
		walker = table[key];
		while (found == 0 && walker) {
			if (walker->word == word) {
				found = walker->count;
			}
			else {
				walker = walker->next;
			}
		}
		return found;										// will return a number greater than 0 (true)
	}
	return 0;
}

int HashTable::getCount() {									// returns the number of unique words in the table
	return numWords;
}