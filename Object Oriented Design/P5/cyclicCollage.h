/* Nils Fenske
3/2/2016
Programming Assignment 5
CyclicCollage class v3

Class Invariants

This class is an imageCollage descendant with the trait of shifting images by 3 on each
display after the first.

================================================================================

Interface Invariants

Same visibility as imageCollage of size count and subscriptions. Obects are initialised
the same as imageCollage objects with the addition of the user passing in a shift value.
User also displays images the same way as an imageCollage object.

*/

#ifndef CYCLICCOLLAGE
#define CYCLICCOLLAGE

#include "imageCollage.h"

using namespace std;

class cyclicCollage: public imageCollage
{
private:
	int shiftValue;

	// Preconditions: Full array of images. 
	// Postconditions: Object holds same images shifted to the right by value of shiftValue.
	void shift();

public:
	cyclicCollage();

	// Preconditions: User is responsible for passing in size and subscriptions and shift value.
	// Postconditions: Object set in initial innactive state.
	cyclicCollage(int quantity, int subs, int shift);

	~cyclicCollage();

	cyclicCollage(const cyclicCollage&);

	void operator=(const cyclicCollage&);

	cyclicCollage operator+(const cyclicCollage&);							// cyclicCollage = cC1 + cC2

	cyclicCollage operator+(const imageCollage&);							// cyclicCollage = cC1 + iC1

	cyclicCollage operator+=(const int&);									// cC1 += 5555

	cyclicCollage operator+=(const cyclicCollage&);							// cC1 += cC2

	cyclicCollage operator+=(const imageCollage&);							// cC1 += iC1

	// Preconditions: Object must be active. 
	// Postconditions: Image information is shifted and displayed by the shift value before each display preceeding the inital display.
	//                 Object is possibly deactivated if number of display subscriptions has been reached.  
	int* getSequence();

	int whoAmI();
};
#endif