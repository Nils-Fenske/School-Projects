// Nils Fenske
// 11/11/15
// bizarreQ class

#include "bizarreQ.h"

void bizarreQ::swap(int value1, int value2, int index1, int index2) {			// takes two values at two index's and swaps the values.
	A[index1] = value2;
	A[index2] = value1;
}

void bizarreQ::heapifyDown(int startingIndex) {									// compares a value to its children and moves it down the tree as required in order to maintain heap tree structure
	
	int index = startingIndex;
	bool done = false;

	while (2 * index <= numItems && !done) {									// checks that it has children beneath it
		int lrg = index;
		if (A[2 * index] > A[index]) {											// compares to left child
			lrg = 2 * index;
		}
		if (2 * index + 1 <= numItems && A[2 * index + 1] > A[lrg]) {			// compares to right child
			lrg = 2 * index + 1;
		}
		if (lrg != index) {										
			swap(A[index], A[lrg], index, lrg);
			index = lrg;
		}
		else done = true;
	}
}

void bizarreQ::resize() {														// if the capacity of the array is met, double the capacity
	int* temp = A;
	capacity = capacity * 2;
	A = new int[capacity];														// creates a new array with double capacity
	for (int i = 1; i < capacity / 2; i++) {									// copies the values to the new array
		A[i] = temp[i];
	}
}

void bizarreQ::dump(int output) {												// when top value is removed, record value in file
	
	ofstream myfile;
	myfile.open("P4Output.txt", ios::app);
	myfile << output << " ";
	myfile.close();
}

bizarreQ::bizarreQ(const bizarreQ& x){											// copy constructor; coppying allowed
	
	capacity = x.capacity;
	A = new int[capacity];
	numItems = 0;
	for (int i = 0; i < capacity; i++) {
		A[i] = x.A[i];
		numItems++;
	}
}

void bizarreQ::operator=(const bizarreQ& rhs){									// overloaded assignment operator
	
	if (this != &rhs) {
		delete[] A;
		capacity = rhs.capacity;
		numItems = rhs.numItems;
		A = new int[capacity];
		for (int i = 0; i < capacity; i++) {
			A[i] = rhs.A[i];
			numItems++;
		}
	}
	return;
}

void bizarreQ::insert(int value) {
	
	if (numItems == capacity - 1) { resize(); }									// since we dont incude 0, if numitems = capcity minus 1, double the capcity of the array

	numItems++;
	A[numItems] = value;
	int index = numItems;
	while (index > 1 && A[index] > A[index / 2]) {								// heapify up
		swap(A[index], A[index / 2], index, index / 2);
		index = index / 2;
	}
}

bool bizarreQ::isEmpty() {														// checks to see if the array is empty
	return !(numItems > 0);
}

int bizarreQ::removeTop() {														// removes the top value 
	
	int top = A[1];

	A[1] = A[numItems];															// moves top item to last place 
	for (int i = 1; i <= numItems; i++) {
		heapifyDown(i);															// sorts the list
	}
	numItems--;																	// "removes" the max item from the list
	dump(top);																	// prints to file	
	return top;
}

void bizarreQ::clear() {														// wipes the array clean of any values
	numItems = 0;
}

void bizarreQ::flush(){															// removes the list of any odd 
		
	int* temp = A;
	A = new int[capacity];
	numItems = 0;
	for (int i = 1; i < capacity; i++) {
		if ((temp[i] % 2) == 0) {
			numItems++;
			A[numItems] = temp[i];
		}
	}
	for (int i = 1; i <= numItems / 2; i++) {
		heapifyDown(i);
		i++;
	}
}
