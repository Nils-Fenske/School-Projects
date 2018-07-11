/* Nils Fenske
3/2/2016
Programming Assignment 5
CyclicCollage class v3

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

cyclicCollage cyclicCollage::operator+(const cyclicCollage& rhs)
{
	int* LHStemp = this->imageArray;
	int* RHStemp = rhs.imageArray;
	int size = this->size + rhs.size;
	int subs;
	int shiftValue = ((this->shiftValue + rhs.shiftValue) / 2);
	if (this->_subscriptions > rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions == rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions < rhs._subscriptions) { subs = rhs._subscriptions; }

	cyclicCollage newCollage(size, subs, shiftValue);

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

cyclicCollage cyclicCollage::operator+(const imageCollage& rhs)
{
	int* LHStemp = this->imageArray;
	int* RHStemp = rhs.imageArray;
	int size = this->size + rhs.size;
	int subs;
	int shiftValue = this->shiftValue;
	if (this->_subscriptions > rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions == rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions < rhs._subscriptions) { subs = rhs._subscriptions; }

	cyclicCollage newCollage(size, subs, shiftValue);

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

cyclicCollage cyclicCollage::operator+=(const int& rhs)
{
	int size = this->size + 1;
	int subs = this->_subscriptions;
	int* temp = this->imageArray;
	int shiftValue = this->shiftValue;

	cyclicCollage newCollage(size, subs, shiftValue);

	for (int i = 0; i < size - 1; i++)
	{
		newCollage.addImage(temp[i]);
	}
	newCollage.addImage(rhs);

	delete temp;

	return newCollage;
}

cyclicCollage cyclicCollage::operator+=(const cyclicCollage& rhs)
{
	int* LHStemp = this->imageArray;
	int* RHStemp = rhs.imageArray;
	int size = this->size + rhs.size;
	int subs;
	int shiftValue = ((this->shiftValue + rhs.shiftValue) / 2);
	if (this->_subscriptions > rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions == rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions < rhs._subscriptions) { subs = rhs._subscriptions; }

	cyclicCollage newCollage(size, subs, shiftValue);

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

cyclicCollage cyclicCollage::operator+=(const imageCollage& rhs)
{
	int* LHStemp = this->imageArray;
	int* RHStemp = rhs.imageArray;
	int size = this->size + rhs.size;
	int subs;
	int shiftValue = this->shiftValue;
	if (this->_subscriptions > rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions == rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions < rhs._subscriptions) { subs = rhs._subscriptions; }

	cyclicCollage newCollage(size, subs, shiftValue);

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

int* cyclicCollage::getSequence()
{
	if (active)
	{
		if (displays == 0) { displays++; return imageArray; }

		if (displays < _subscriptions)
		{
			for (int i = 0; i < shiftValue; i++) { shift(); }

			displays++;
			return imageArray;
		}
		if (displays == _subscriptions) { active = false; }
		return 0;
	}
}

int cyclicCollage::whoAmI()
{
	return 2;
}
