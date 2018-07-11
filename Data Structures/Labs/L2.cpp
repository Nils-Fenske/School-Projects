// Nils Fenske

// 10/2/2015

// 2430 Section 2

// Lab 2


#include <iostream>

using namespace std;


int passByValue(int x, int y);

int passByRef(int& x, int& y);


int main () {

  cout << "Welcome message" << endl;


  passByValue(100, 200);

  passByValue(50, 150);

  passByValue(10, 100);


  int x = 100;

  int y = 200;

  passByRef(x, y);


  x = 50;

  y = 150;

  passByRef(x, y);


  x = 10;

  y = 100;

  passByRef(x, y);


  cout << "End of Lab 2 Program" << endl;


}



int passByValue( int x, int y  ) {


  int* iPtr;
  iPtr = &x;
          

  cout << x << " @ "  << &x << endl;

  cout << *iPtr << " @ " << iPtr << endl;


  cout << ++x << endl;

  cout << x++ << endl;

  cout << x++ << endl;

  cout << ++x << endl;

  *iPtr = y;
  cout << x << endl;

  cout << ++(*iPtr) << endl;
  cout << (*iPtr)++ << endl;
  cout << (*iPtr)++ << endl;
  cout << ++(*iPtr) << endl;

  cout << x << endl;  

  cout << *iPtr << endl;

  return 0;
}

int passByRef( int& x, int& y  ) {

  int* iPtr;          
  iPtr = &x;          

  cout << x << " @ " << &x << endl;
  cout << *iPtr << " @ " << iPtr << endl;

  cout << ++x << endl;
  cout << x++ << endl;
  cout << x++ << endl;
  cout << ++x << endl;

  *iPtr = y;
  cout << x << endl;

  cout << ++(*iPtr) << endl;
  cout << (*iPtr)++ << endl;
  cout << (*iPtr)++ << endl;
  cout << ++(*iPtr) << endl;

  cout << x << endl;

  cout << *iPtr << endl;

  return 0;
}

			 
	
