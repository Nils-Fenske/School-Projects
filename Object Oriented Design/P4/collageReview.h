/* Nils Fenske
2/22/2016
Programming Assignment 4
CollageReview Class v1

Class Invariants

This class object Is-a imageCollage (including decendants of imageCollage) and Is-a review object.

================================================================================

Interface Invariants

User has access to interfaces of both the imageCollage as well as the review classes. User must pass in 
specific parameters to construct a collageReview of imageCollage type along with review object parameters.


*/

#ifndef COLLAGEREVIEW
#define COLLAGEREVIEW

#include "review.h"
#include "imageCollage.h"
#include "bitCollage.h"
#include "cyclicCollage.h"
#include <string>

using namespace std;

class collageReview : public imageCollage, public bitCollage, public cyclicCollage, public review
{

private:
	bool iCollage;
	bool bCollage;
	bool cCollage;

	collageReview(const collageReview&);
	void operator=(const collageReview&);

public:
	collageReview();

	// Preconditions:  
	// Postconditions: 
	collageReview(int quantity, int subs, bool freeOrNot, int mmddyyyy);

	// Preconditions:  
	// Postconditions: 
	collageReview(int quantity, int subs, bool replaceable, bool freeOrNot, int mmddyyyy);

	// Preconditions:  
	// Postconditions: 
	collageReview(int quantity, int subs, int shift, bool freeOrNot, int mmddyyyy);

	~collageReview();

	// Preconditions:  
	// Postconditions: 
	string whoAmI();

	// Preconditions:  
	// Postconditions: 
	void addImage(int id);

	// Preconditions:  
	// Postconditions: 
	void display();

	// Preconditions:  
	// Postconditions: 
	void replace(int index, int replacement);

	// Preconditions:  
	// Postconditions: 
	int* getSequence();
};
#endif