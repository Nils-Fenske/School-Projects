// Nils Fenske
// 10/30/2015
// Lab 5

#include <iostream>

using namespace std;

void insert(int number);
void heapifyDown();
void swap(int value1, int value2, int index);
void removeTop();
int capacity = 5;
int numItems = 0;  
int* A = new int[capacity + 1];

int main(){
  
  insert(30);
  insert(15);
  insert(5);
  insert(20);
  insert(10);
  insert(25);
  
  return 0;
}

void insert(int number){

  numItems++;
  A[numItems] = number;
  int index = numItems;
  while (index>1 && A[index] > A[index/2])
	{swap( A[index], A[index/2], index);
	  index = index/2;
	}
  
}

void heapifyDown(int startingIndex){

  int index = startingIndex;
  bool done = false;
  
  while (2*index <= numItems && !done){
   int lrg = index;
	 if (A[2*index] > A[index])lrg = 2*index;				//left child > parent
	 if (2*index+1<=numItems && A[2*index+1] > A[lrg])		// rtchild largest
	   lrg = 2*index + 1;
	 if (lrg != index)										// parent not largest
	   {swap( A[index], A[lrg]);
		 index = lrg;
	   }
	 else done = true;
   }
}

void swap(int value1, int value2, int index){      // for #6 this swap function 
  A[index] = value2;                               // would need to be changed to 
  A[index/2] = value1;                             // swap values at any index   
}

void removeTop(){
  A[1] = A[numItems];
  for(int i = 1; i <= numItems / 2; i++){
	heapifyDown(i);
	i++;
  }

  numItems--;
  
}
  
