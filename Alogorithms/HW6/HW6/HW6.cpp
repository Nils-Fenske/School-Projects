// Nils Fenske
// CS 4100
// HW5 v2.0

// I have not received unauthorized aid on this assignment. 
// I understand the answers that I have submitted. 
// The answers submitted have not been directly copied from another source, but instead are written in my own words.

// This program takes a string from user input. 
// It then stores a copy of that string in reverse. 
// Next, a longest common subsequence is looked for between the two strings.
// The LCS found is the longest palindrome of characters in the original string. 


//#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <chrono>

using namespace std;

void LCS_length(string X, string Y, int**& c) {
	int m = X.length();
	int n = Y.length();

	c = new int* [m + 1];

	for (int i = 0; i <= m; i++) {
		c[i] = new int[n + 1];
	}

	for (int i = 1; i <= m; i++) {
		c[i][0] = 0;
	}
	for (int j = 0; j <= n; j++) {
		c[0][j] = 0;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[i - 1] == Y[j - 1]) {
				c[i][j] = (c[i - 1][j - 1]) + 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
			}
			else {
				c[i][j] = c[i][j - 1];
			}
		}
	}
}

void LCS_traceback(int** c, string X, int i, int j) {

   if (i == 0 || j == 0) return;
   if (c[i][j] == c[i - 1][j]) { 
     LCS_traceback(c, X, i - 1, j);
   }
   else if (c[i][j] == c[i][j - 1]) {
	 LCS_traceback(c, X, i, j - 1);
   }
   else if (c[i][j] == (c[i - 1][j - 1]) + 1) {
	 LCS_traceback(c, X, i - 1, j - 1);
   	 cout << X[i - 1];
   }
}

template <typename T>
void destroy(T**& A, int rows) {
	for (int i = rows - 1; i >= 0; i--) {
		delete[] A[i];
	}
	delete[] A;
}

void palindrome(string X, string Y) {

	int** c;

	LCS_length(X, Y, c);

	cout << "The palindrome within the string is: ";
	LCS_traceback(c, X, X.length(), Y.length());
	cout << "\n";

	destroy(c, X.length() + 1);
}

string reverse(string A) {
	string B;
	for (int i = A.length() - 1; i >= 0; i--) {
		B.push_back(A[i]);
	}
	return B;
}

int main()
{
  auto starts = chrono::steady_clock::now();

  string S_forwards;
  cout << "Please enter a string: \n";
  cin >> S_forwards;

  string S_backwards = reverse(S_forwards);

  cout << S_backwards << "\n";

  palindrome(S_forwards, S_backwards);

  auto ends = chrono::steady_clock::now();

  chrono::steady_clock::  duration d = ends - starts;

  cout << "Runtime: " << chrono::duration_cast<chrono::milliseconds>(d).count() << " ms\n";

  return 0;
}

