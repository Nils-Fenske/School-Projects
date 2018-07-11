// Nils Fenske
// 11/11/15
// P4 header

#ifndef BIZARREQ
#define BIZARREQ

#include <iostream>
#include <fstream>

using namespace std;

class bizarreQ {

private:

	int capacity;
	int numItems;
	int* A;

	void swap(int value1, int value2, int index1, int index2);
	void heapifyDown(int startingIndex);
	void resize();
	void dump(int output);
	


public:

	bizarreQ(unsigned c = 50) {
		capacity = c;
		A = new int[capacity];
		numItems = 0;
	}

	bizarreQ(const bizarreQ&);			// deep copying supported

	void operator=(const bizarreQ&);    // overloaded assignment operator

	~bizarreQ() { delete[] A; };

	void insert(int value);

	int removeTop();

	bool isEmpty();

	void clear();

	void flush();

};

#endif BIZARREQ