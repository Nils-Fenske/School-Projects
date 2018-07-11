/* Nils Fenske
3/2/2016
Programming Assignment 5
ImageCollage class v3

Class Invariants

This class of object holds a sequence of image id's

================================================================================

Interface Invariants

The user creates a collage by passing in the size and number of subscriptions paid for.
The user has the ability to read the number of items in the sequence as well as the
number of subscriptions or display's available to them. The user also can add images
by passing in an image id. The user can display images as well as replace images by
knowing the index of the image they want to replace and passing in the new one.

*/

#ifndef IMAGECOLLAGE
#define IMAGECOLLAGE

#include <fstream>
#include <iostream>

using namespace std;

class imageCollage {

	friend class bitCollage;
	friend class cyclicCollage;

protected:

	bool active;
	int size;
	int _count;
	int displays;
	int _subscriptions;
	int replacements;
	int* imageArray;

public:

	// Preconditions:  
	// Postconditions: 
	int getCount();

	// Preconditions:  
	// Postconditions: 
	int getSubscriptions();

	imageCollage();

	// Preconditions: User is responsible for passing in size and subscriptions. 
	// Postconditions: Object set in initial innactive state.
	imageCollage(int quantity, int subs);

	~imageCollage();

	imageCollage(const imageCollage&);

	void operator=(const imageCollage&);

	friend ostream& operator<<(ostream&, imageCollage&);						// cout << iC1 

	friend void operator+(const int&, imageCollage&);							// 5555 + iC1

	void operator+(const int&);													// iC1 + 5555;

	imageCollage operator+(const imageCollage&);								// imageCollage = iC1 + iC2

	imageCollage operator+=(const int&);										// iC1 += 5555

	imageCollage operator+=(const imageCollage&);								// iC1 += iC2

	bool operator==(const imageCollage&);										// iC1 == iC2

	bool operator!=(const imageCollage&);										// iC1 != iC2

	bool operator<(const imageCollage&);										// iC1 < iC2

	bool operator<=(const imageCollage&);										// iC1 <= iC2

	bool operator>(const imageCollage&);										// iC1 > iC2

	bool operator>=(const imageCollage&);										// iC1 >= iC2
				
	int operator[](int);														// iC[i]

	// Preconditions: User passes in id of image. Cannot add more than size set by user.
	// Postconditions: Once object is full, object is set in active state and no more can be added.
	virtual void addImage(int id);

	// Preconditions: object must be active. Returns the sequnce of images. 
	// Postconditions: Possibly deactivated if number of subscriptions reached. 
	virtual int* getSequence();

	// Preconditions: Object must be active. User is respnsible for knowing index of image they wish to replace. Must pass in new image. 
	// Postconditions: Object still full and active with different sequence. 
	virtual void replace(int index, int replacement);

	virtual int whoAmI();
};
#endif