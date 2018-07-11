// Nils Fenske
// 11/11/2015
// P4 driver

#include <iostream>
#include <time.h>
#include "bizarreQ.cpp"

int main() {
	srand(time(NULL));

	bizarreQ poop;
	
	ofstream myfile;
	myfile.open("P4Output.txt");
	myfile.close();

	for (int i = 0; i < 100; i++) {
		int x = rand() % 100;
		poop.insert(x);
	}

	poop.flush();

	while (!poop.isEmpty()) {
		int x = poop.removeTop();
		cout << x << " ";
	}

	return 0;
}
