// Nils Fenske
// 12/2/2015
// Programming Assignment 5

#include <string>
#include <fstream>
#include <iostream>
#include "HashTable.cpp"

using namespace std;

int main() {

	HashTable book1;
	int wCount1 = 0;

	HashTable book2;
	int wCount2 = 0;

	ifstream bFile1;
	bFile1.open("WarAndPeace.txt");

	string word1 = "";

	while (bFile1 >> word1) {

		book1.insert(word1);
	}
	
	bFile1.close();

	ifstream bFile2;
	bFile2.open("GreatExpectations.txt");

	string word2 = "";

	while (bFile2 >> word2) {

		book2.insert(word2);
	}

	bFile2.close();

	string wordArray[15];					// array to hold words			**
	int countArray[15];						// array to hold counts			**indeces correspond

	int combo = 0;
	string searchWord;

	bFile1.open("WarAndPeace.txt");			
		
	while (bFile1 >> searchWord) {																	// read each word from war and peace
		while (book2.search(searchWord) > 0) {														// this word must also occur in great expectations
			combo = (book1.search(searchWord) + book2.search(searchWord));							// combine the two counts of occurences for the word

			for (int i = 0; i < 15; i++) {		
				while (countArray[i] >= 0 && combo <= countArray[i] && wordArray[i] != searchWord) {	// if the index is valid and the combo is not greater than the value at that index and the word does not match 
					if (combo > countArray[i]) {														// if the combo is greater
						int tempC = combo;																// store the combo
						combo = countArray[i];															// store the value already there
						countArray[i] = tempC;															// index equals the combo

						string tempW = searchWord;														// same for corresponding word
						searchWord = wordArray[i];
						wordArray[i] = tempW;
					}
					i++;																				// will shuffle the values down the array and push off any that we dont care about anymore
				}
			}
		}
	}

	ofstream oFile;
	oFile.open("P5Output.txt");

	oFile << "Number of words in War and Peace: " << book1.getCount() << endl;
	oFile << "Number of words in Great Expectations: " << book2.getCount() << endl;

	oFile << "15 Most Common Words:" << endl;
	
	for (int i = 0; i < 15; i++) {
		oFile << i + 1 << ". " << wordArray[i] << " : " << countArray[i];
	}

	return 0;
}

