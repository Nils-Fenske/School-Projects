// Nils Fenske
// 10/21/2015
// Programming Assignment 2

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Node {
	int data;
	Node* link;
};

Node* scan(Node* head, int value);
void insert(Node* &head, int value);
int filter(int value);
bool isPrime(int value);
void printOut(Node* head);
void remove(Node* &head, int valueToDelete);

int main() {
	srand(time(NULL));
	Node* head = new Node;
	head = 0;

	const int size = 100;

	for (int i = 0; i < size; i++) {
		int x = rand() % 100;
		insert(head, x);
	}

	for (int i = 0; i < size/2; i++) {
		int x = rand() % 100;
		remove(head, x);
	}

	printOut(head);

	return 0;
}

void printOut(Node* head) {
	Node* travel = head;
	while (travel) {
		cout << travel->data << " ";
		travel = travel->link;
	}
}

Node* scan(Node* head, int value) {
	Node* scanP = head;
	Node* prevP = 0;
	while (scanP && scanP->data < value) {
		prevP = scanP;
		scanP = scanP->link;
	}
	return prevP;
}

void insert(Node* &head, int value) {
	
	if (filter(value)) {

		Node* insertP = new Node;
		insertP->data = filter(value);
		Node* prevP = scan(head, insertP->data);

		if (!prevP) {
			insertP->link = head;
			head = insertP;
		}
		else {
			insertP->link = prevP->link;
			prevP->link = insertP;
		}
	}
}

void remove(Node* &head, int valueToDelete) {
	Node* prevP = scan(head, valueToDelete);
	if (prevP) {
		Node* scanP = prevP->link;
		if (scanP && scanP->data == valueToDelete) {
			prevP->link = scanP->link;
			delete scanP;
		}
		else {
			if (head && head->data == valueToDelete) {
				prevP = head;
				head = head->link;
				delete prevP;
			}
		}
	}
}

int filter(int value) {
	if (isPrime(value)) {
		for (int i = value - 1; i > 2; i--) {
			if (isPrime(i)) {
				return i - 1;
			}
		}
	}
	return 0;
}

bool isPrime(int value){

	if (value > 2) {

		for (int i = 2; i < value; i++) {
			if (value % i == 0) {
				return false;
			}
		}
		return true;
	}
	return false;
}

