// Nils Fenske
// 10/9/2015
// Lab 3

#include <iostream>
using namespace std

;struct Node {
  int  data;
  Node* link;
};

int main() {

    // build list
	Node*   head = new Node;

	head->data = 5;

	head->link = NULL;  

	// add values
	Node*   auxPtr = head;

	int nodeCounter = 0;
	int currentValue = 5;
	int newValue;

	while ( (nodeCounter < 10) ) {
		auxPtr->link = new Node;
	    auxPtr = auxPtr->link;
		newValue = (currentValue * 2);
		auxPtr->data = (newValue);
		currentValue = newValue;
		nodeCounter++;
		}
	auxPtr->link = NULL;
	
	// find and delete
	Node* finder = head;
	Node* prevNode;
	int desiredVal = 40;

	if ( head->data == desiredVal ) {
	  head = head->link;
	} else {
	  while ( finder != NULL ){	
		if ( !(finder->data == desiredVal) ) {
		 prevNode = finder;
		 finder = finder->link;
		} else {
		  prevNode->link = finder->link;
		  delete finder;
		}
	  }
	}

	//insert
	Node* slotFinder = head;
	Node* insertion;
	int insertVal = 7;

	while (slotFinder) { 
	  if (slotFinder->data > insertVal) {
		insertion = slotFinder->link;
		insertion->data = insertVal;
	  }else {
		slotFinder = slotFinder->link;
	  }
	}
	  

	// travers and print
	Node* travPtr = head;

    while (travPtr) {
	  cout << travPtr->data << endl;
	  travPtr = travPtr->link;
	}
	delete travPtr;
	
}
