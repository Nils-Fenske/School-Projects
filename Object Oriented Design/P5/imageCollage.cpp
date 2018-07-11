/* Nils Fenske
3/2/2016
Programming Assignment 5
ImageCollage class v3

Implementation Invariants

Data members are protected to be used by subclasses.Image id's are stored in an
array.The object is constructed in initial state with values at 0 and status at
innactive until sequence is full. Displaying the images is kept track of in order to deactivate
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
}

ostream& operator<<(ostream& stream, imageCollage& rhs) 
{
	if (rhs._count != rhs._subscriptions)
	{
		int* local = rhs.getSequence();

		stream << "[ ";

		for (int i = 0; i < rhs.size; i++)
		{
			if (local[i] > 0) { stream << local[i] << " "; }
		}

		stream << "]" << endl;

		return stream;
	}
	return stream;
}

void operator+(const int& id, imageCollage& rhs)
{
	int* temp = rhs.imageArray;

	rhs.imageArray = new int[rhs.size + 1];

	rhs.imageArray[0] = id;

	for (int i = 1; i < rhs.size + 1; i++)
	{
		rhs.imageArray[i] = temp[i + 1];
	}
	rhs.active = true;
}

void imageCollage::operator+(const int& rhs)
{
	this->addImage(rhs);
}

imageCollage imageCollage::operator+(const imageCollage& rhs)
{

	int* LHStemp = this->imageArray;
	int* RHStemp = rhs.imageArray;
	int size = this->size + rhs.size;
	int subs;
	if (this->_subscriptions > rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions == rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions < rhs._subscriptions) { subs = rhs._subscriptions; }
	
	imageCollage newCollage(size, subs);

	for (int i = 0; i < this->size; i++)
	{
		newCollage.addImage(LHStemp[i]);
	}
	for (int j = this->size; j < rhs.size; j++)
	{
		newCollage.addImage(RHStemp[j]);
	}

	return newCollage;
}

imageCollage imageCollage::operator+=(const int& rhs)
{
	int size = this->size + 1;
	int subs = this->_subscriptions;
	int* temp = this->imageArray;

	imageCollage newCollage(size, subs);
	
	for (int i = 0; i < size - 1; i++)
	{
		newCollage.addImage(temp[i]);
	}
	newCollage.addImage(rhs);

	delete temp;
	
	return newCollage;
}

imageCollage imageCollage::operator+=(const imageCollage& rhs)
{
	int* LHStemp = this->imageArray;
	int* RHStemp = rhs.imageArray;
	int size = this->size + rhs.size;
	int subs;
	if (this->_subscriptions > rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions == rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions < rhs._subscriptions) { subs = rhs._subscriptions; }

	imageCollage newCollage(size, subs);

	for (int i = 0; i < this->size; i++)
	{
		newCollage.addImage(LHStemp[i]);
	}
	for (int j = this->size; j < rhs.size; j++)
	{
		newCollage.addImage(RHStemp[j]);
	}

	return newCollage;
}

bool imageCollage::operator==(const imageCollage& rhs)
{
	return (this->size == rhs.size);
}

bool imageCollage::operator!=(const imageCollage& rhs)
{
	return (this->size != rhs.size);
}

bool imageCollage::operator<(const imageCollage& rhs)
{
	return (this->size < rhs.size);
}

bool imageCollage::operator<=(const imageCollage& rhs)
{
	return (this->size <= rhs.size);
}

bool imageCollage::operator>(const imageCollage& rhs)
{
	return (this->size > rhs.size);
}

bool imageCollage::operator>=(const imageCollage& rhs)
{
	return (this->size >= rhs.size);
}

int imageCollage::operator[](int input)
{
	int* temp = this->getSequence();

	if (input > 0 && input < this->size) { return temp[input]; }
	
	return 0;
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

int* imageCollage::getSequence()
{
	if (active)
	{
		if (displays < _subscriptions)
		{
			return imageArray;
			displays++;
		}
	}
	if (displays == _subscriptions) { active = false; }
	return 0;
}

void imageCollage::replace(int index, int replacement)
{
	if (active)
	{
		imageArray[index] = replacement;
		replacements++;
	}
}

int imageCollage::whoAmI()
{
	return 0;
}

