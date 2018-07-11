// Nils Fenske
// 9/24/2015
// CPSC 2430 2
// Lab 1

#include <iostream>

using namespace std;

 

int main() 													// This is incredibly unfinished and I am still getting the hang of C++

    cout << "Welcome message" << endl;
	sortList();
	

    cout << endl << "End of Lab1 Pgm" << endl;

 

    return 0;
}

//get list of numbers
int getList() {
	int listSize;
	cout << "Please enter a desired list size: ";
	cin >> listSize;
	char list [listSize];
	int x;
	int y = 0;
	while ( list[listSize - 1] != null ){
	cout << "Please enter a number between 11 and 99: ";
	cin >> x;
	cout << endl;
		if ( x%2 != 1 ){
		list [y] = x;
		y++;
		}
	}
	return list;
}

//measure and find the maximum number in a list
int sortList() {
	getList();
	int count = 0;
	while ( count != listSize ) {
		cout << list[count] << ", ";
		count++;
	}
		
}