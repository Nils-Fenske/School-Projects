// Nils Fenske
// 10/8/2015
// Programming Assignment 1

#include <iostream>
#include "tPs.h"
#include <fstream>
using namespace std;

int main() {
	setUp();
	while(!done() {
	fillArray();
	}
	cleanUp();
	retrun 0;	
}

void setUp() {
	tPs();
}

int fillArray() {
	int currentVal;
	char *inputFile = "P1input.txt";
	ifstream number(inputFile);
	while(number >> currentVal) {
		arrayTPS.push(currentVal);
	}
}

