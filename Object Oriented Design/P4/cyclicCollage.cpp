/* Nils Fenske
2/22/2016
Programming Assignment 4
CyclicCollage class v2

Implementation Invariants

This class uses the same protecteded data members as the imageCollage with the addition of a
shift value.The constructor is overridden with the addition of the shift value parameter beeing
passed in.There is a private shift function that is used during the display function.

*/

#include "cyclicCollage.h"

void cyclicCollage::shift()
{
	int temp = imageArray[size - 1];
	for (int i = size - 1; i > 0; i--) 
	{
		imageArray[i] = imageArray[i - 1];
	}
	imageArray[0] = temp;
}

cyclicCollage::cyclicCollage() {};

cyclicCollage::cyclicCollage(int quantity, int subs, int shift): imageCollage(quantity, subs)
{
	shiftValue = shift;
}

cyclicCollage::~cyclicCollage()
{
	imageCollage::~imageCollage();
}

cyclicCollage::cyclicCollage(const cyclicCollage& x)
{
	if (x.active)
	{
		shiftValue = x.shiftValue;
		imageCollage(x);
	}
}

void cyclicCollage::operator=(const cyclicCollage& rhs) 
{
	if (rhs.active && this != &rhs)
	{
		imageCollage::operator=(rhs);
		shiftValue = rhs.shiftValue;
	}
}

void cyclicCollage::display()
{
	if (active)
	{
		if (displays == 0)
		{
			cout << endl;
			cout << "Original Sequence: (";
			for (int i = 0; i <= size - 2; i++)
			{
				cout << imageArray[i] << ", ";
			}
			cout << imageArray[size - 1] << ")" << endl;
			cout << "Subscriptions: " << _subscriptions << endl;
		}

		cout << "Cyclic Image Sequence (" << (displays + 1) << "): (";

		for (int i = 0; i < shiftValue; i++) { shift(); }

		for (int i = 0; i <= size - 2; i++)
		{
			cout << imageArray[i] << ", ";
		}
		cout << imageArray[size - 1] << ")";
		displays++;
		if (displays == _subscriptions) { active = false; }
		cout << endl;
	}
}
