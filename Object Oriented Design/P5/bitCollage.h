/* Nils Fenske
3/2/2016
Programming Assignment 5
BitCollage class v3

Class Invariants

This class is an imageCollage descendant with the trait of omitting a 1, 2, or 3
(randomly) number of images each display as well as only being able to replace
even or odd image id's (set by user).
================================================================================

Interface Invariants

The user creates a collage by passing in the size and number of subscriptions paid for as
well as wether even or odd images are replaceable. The user has the ability to read
the number of items in the sequence as well as the number of subscriptions or display's
available to them. The user also can add images by passing in an image id. The user
can display images as well as replace images by knowing the index of the image they
want to replace and passing in the new one. A user passes in a "true" boolean to the cunstructor
to allow even numbers to be replaced and vice versa for odd.

*/

#ifndef BITCOLLAGE
#define BITCOLLAGE

#include "imageCollage.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

class bitCollage: public imageCollage 
{

private:
	
	bool EvenOrOdd;
	static bool randomSeed;

	// Preconditions: Array being passed in must be initialized 
	// Postconditions: Returns and bool. 
	bool exists(int x, int* arr, int size);

public:

	bitCollage();

	// Preconditions: User is responsible for passing in size and subscriptions and true for even / false for odd, replacement.
	// Postconditions: Object set in initial innactive state.
	bitCollage(int quantity, int subs, bool replaceable);

	~bitCollage();

	bitCollage(const bitCollage&);

	void operator=(const bitCollage&); 

	bitCollage operator+(const bitCollage&);								// bitCollage = bC1 + bC2

	bitCollage operator+(const imageCollage&);								// bitCollage = bC1 + iC1      bitCOllage = iC + bC

	bitCollage operator+=(const int&);										// bC1 += 5555

	bitCollage operator+=(const bitCollage&);								// bC1 += bC2

	bitCollage operator+=(const imageCollage&);								// bC1 += iC1


	// Preconditions: Object must be active.
	// Postconditions: Image information is possibly replaced and/or ommitted before each return preceeding the inital return.
	//                 Object is possibly deactivated if number of display subscriptions has been reached.
	int* getSequence();

	// Preconditions: Object must be active. User is respnsible for knowing index of image they wish to replace. Must pass in new image.
	//                Only even or odd images are replaced based on user setting when object initialized.
	// Postconditions: Object still full and active with different sequence.
	void replace(int index, int replacement);

	int whoAmI();
};
#endif
