/* Nils Fenske
2/22/2016
Programming Assignment 4
ImageCollage class v2

Implementation Invariants

Data members are protected to be used by subclasses.Image id's are stored in an
array.The object is constructed in initial state with values at 0 and status at
innactive until sequence is full.Displaying the images is kept track of in order to deactivate
after a certain number of uses(subscriptions).The user is responsible for knowing the
index of the image they wish to replace as well as passing in the new image.Number of images
cannot be reduced.

*/

#include "imageCollage.h"

int imageCollage::getCount()
{
	return _count;
}

int imageCollage::getSubscriptions()
{
	return _subscriptions;
}

imageCollage::imageCollage() {};

imageCollage::imageCollage(int quantity, int subs)
{
	size = quantity;
	imageArray = new int[size];
	_count = 0;
	displays = 0;
	_subscriptions = subs;
	replacements = 0;
	active = false;
}

imageCollage::~imageCollage()
{
	delete[] imageArray;
}

imageCollage::imageCollage(const imageCollage& x)
{
	if (x.active) 
	{
		active = x.active;
		size = x.size;
		imageArray = new int[size];
		_count = x._count;
		displays = x.displays;
		_subscriptions = x._subscriptions;
		replacements = x.replacements;

		for (int i = 0; i < size; i++) {
			imageArray[i] = x.imageArray[i];
		}
	}
}

void imageCollage::operator=(const imageCollage& rhs) 
{
	if (rhs.active && this != &rhs)
	{
		delete[] imageArray;
		active = rhs.active;
		size = rhs.size;
		imageArray = new int[size];
		_count = rhs._count;
		displays = rhs.displays;
		_subscriptions = rhs._subscriptions;
		replacements = rhs.replacements;

		for (int i = 0; i < size; i++) {
			imageArray[i] = rhs.imageArray[i];
		}
	}
	return;
}

void imageCollage::addImage(int id)
{
	if (_count < size)
	{
		imageArray[_count] = id;
		_count++;
	}

	if (_count == size) { active = true; }
}

void imageCollage::display()
{
	if (active)
	{
		cout << endl;
		cout << "Image Sequence: (";
		for (int i = 0; i <= size - 2; i++)
		{
			cout << imageArray[i] << ", ";
		}
		cout << imageArray[size - 1] << ")" << endl;
		cout << "Subscriptions: " << _subscriptions << endl;
		displays++;
		if (displays == _subscriptions) { active = false; }
	}
}

void imageCollage::replace(int index, int replacement)
{
	if (active)
	{
		imageArray[index] = replacement;
		replacements++;
	}
}

int* imageCollage::getSequence()
{
	if (active) { return imageArray; }
}
