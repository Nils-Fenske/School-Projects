/* Nils Fenske
2/22/2016
Programming Assignment 4
CollageReview Class v1

Implementation Invariants

When the user passes in parameters to construct the imageCollage type collageReview of their choice, 
the corresponding bool is set to true which directs function calls of the correct class for the whole object. 

*/

#include "collageReview.h"

void collageReview::operator=(const collageReview &){}

collageReview::collageReview() {};

collageReview::collageReview(int quantity, int subs, bool freeOrNot, int mmddyyyy): imageCollage(quantity, subs), review(freeOrNot, mmddyyyy)
{
	iCollage = true;
	bCollage = false;
	cCollage = false;
}

collageReview::collageReview(int quantity, int subs, bool replaceable, bool freeOrNot, int mmddyyyy) : bitCollage(quantity, subs, replaceable), review(freeOrNot, mmddyyyy)
{
	iCollage = false;
	bCollage = true;
	cCollage = false;
}

collageReview::collageReview(int quantity, int subs, int shift, bool freeOrNot, int mmddyyyy) : cyclicCollage(quantity, subs, shift), review(freeOrNot, mmddyyyy)
{
	iCollage = false;
	bCollage = false;
	cCollage = true;
}

collageReview::~collageReview()
{
	if (iCollage) { imageCollage::~imageCollage(); }
	if (bCollage) { bitCollage::~bitCollage(); }
	if (cCollage) { cyclicCollage::~cyclicCollage();; }
	review::~review();
}

string collageReview::whoAmI()
{
	if (iCollage) { return "imageCollage"; }
	if (bCollage) { return "bitCollage"; }
	if (cCollage) { return "cyclicCollage"; }
	return "NO ONE";
}

void collageReview::addImage(int id)
{
	if (iCollage) { imageCollage::addImage(id); }
	if (bCollage) { bitCollage::addImage(id); }
	if (cCollage) { cyclicCollage::addImage(id); }
}

void collageReview::display()
{
	if (iCollage) 
	{ 
		cout << (date / 1000000) << "/" << (date / 10000) % 100 << "/" << (date % 10000) << endl;
		imageCollage::display(); 
	}
	
	if (bCollage) 
	{ 
		cout << (date / 1000000) << "/" << (date / 10000) % 100 << "/" << (date % 10000) << endl;
		bitCollage::display(); 
	}
	
	if (cCollage) 
	{ 
		cout << (date / 1000000) << "/" << (date / 10000) % 100 << "/" << (date % 10000) << endl;
		cyclicCollage::display(); 
	}
}

void collageReview::replace(int index, int replacement)
{
	if (iCollage) { imageCollage::replace(index, replacement); }
	if (bCollage) { bitCollage::replace(index, replacement); }
	if (cCollage) { cyclicCollage::replace(index, replacement); }
}

int* collageReview::getSequence() 
{
	return imageCollage::getSequence();
}