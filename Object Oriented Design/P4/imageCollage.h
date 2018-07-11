/* Nils Fenske
2/22/2016
Programming Assignment 4
ImageCollage class v2

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

	// Preconditions: Object must be active.
	// Postconditions: 
	int* getSequence();

	// Preconditions: User passes in id of image. Cannot add more than size set by user.
	// Postconditions: Once object is full, object is set in active state and no more can be added.
	virtual void addImage(int id);

	// Preconditions: object must be active. Prints out the sequnce of images as well as number of subscriptions. 
	// Postconditions: Possibly deactivated if number of subscriptions reached. 
	virtual void display();

	// Preconditions: Object must be active. User is respnsible for knowing index of image they wish to replace. Must pass in new image. 
	// Postconditions: Object still full and active with different sequence. 
	virtual void replace(int index, int replacement);

};
#endif