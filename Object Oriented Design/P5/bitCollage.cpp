/* Nils Fenske
3/2/2016
Programming Assignment 5
BitCollage class v3

Implementation Invariants

Data members are protected to be used by subclasses.Image id's are stored in an
array.The object is constructed in initial state with values at 0 and status at
innactive until sequence is full.Displaying the images is kept track of in order to deactivate
after a certain number of uses(subscriptions).The user is responsible for knowing the
index of the image they wish to replace as well as passing in the new image.Number of images
cannot be reduced.Random number generator is used to omit 1, 2, or 3 images.Private exists function is
used to check if a number exists in an array.This is used when deciding which numbers to omit.
In a more realistic design the user would be aware of the ids of images in the sequence and would be able
to pass in which ones they wanted omitted.Becuase images are generated randomly here, I had to do this
within the class.

*/

#include "bitCollage.h"

bool bitCollage::randomSeed;

bool bitCollage::exists(int x, int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		if (arr[i] == x) { return true; }
	}
	return false;
}

bitCollage::bitCollage() {}

bitCollage::bitCollage(int quantity, int subs, bool replaceable): imageCollage(quantity, subs)
{
	EvenOrOdd = replaceable;
}

bitCollage::~bitCollage()
{
	imageCollage::~imageCollage();
}

bitCollage::bitCollage(const bitCollage& x)
{
	if (x.active)
	{
		EvenOrOdd = x.EvenOrOdd;
		imageCollage(x);
	}
}

void bitCollage::operator=(const bitCollage& rhs) 
{
	if (rhs.active && this != &rhs) 
	{
		imageCollage::operator=(rhs);
		EvenOrOdd = rhs.EvenOrOdd;
	}
}

bitCollage bitCollage::operator+(const bitCollage& rhs)
{
	int* LHStemp = this->imageArray;
	int* RHStemp = rhs.imageArray;
	int size = this->size + rhs.size;
	int subs;
	bool replaceable = (this->EvenOrOdd && rhs.EvenOrOdd);
	if (this->_subscriptions > rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions == rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions < rhs._subscriptions) { subs = rhs._subscriptions; }

	bitCollage newCollage(size, subs, replaceable);

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

bitCollage bitCollage::operator+(const imageCollage& rhs)
{
	int* LHStemp = this->imageArray;
	int* RHStemp = rhs.imageArray;
	int size = this->size + rhs.size;
	int subs;
	bool replaceable = (this->EvenOrOdd);
	if (this->_subscriptions > rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions == rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions < rhs._subscriptions) { subs = rhs._subscriptions; }

	bitCollage newCollage(size, subs, replaceable);

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

bitCollage bitCollage::operator+=(const int& rhs)
{
	int size = this->size + 1;
	int subs = this->_subscriptions;
	int* temp = this->imageArray;
	bool replaceable = this->EvenOrOdd;

	bitCollage newCollage(size, subs, replaceable);

	for (int i = 0; i < size - 1; i++)
	{
		newCollage.addImage(temp[i]);
	}
	newCollage.addImage(rhs);

	delete temp;

	return newCollage;
}

bitCollage bitCollage::operator+=(const bitCollage& rhs)
{
	int* LHStemp = this->imageArray;
	int* RHStemp = rhs.imageArray;
	int size = this->size + rhs.size;
	int subs;
	bool replaceable = (this->EvenOrOdd && rhs.EvenOrOdd);
	if (this->_subscriptions > rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions == rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions < rhs._subscriptions) { subs = rhs._subscriptions; }

	bitCollage newCollage(size, subs, replaceable);

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

bitCollage bitCollage::operator+=(const imageCollage& rhs)
{
	int* LHStemp = this->imageArray;
	int* RHStemp = rhs.imageArray;
	int size = this->size + rhs.size;
	int subs;
	bool replaceable = this->EvenOrOdd;
	if (this->_subscriptions > rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions == rhs._subscriptions) { subs = this->_subscriptions; }
	if (this->_subscriptions < rhs._subscriptions) { subs = rhs._subscriptions; }

	bitCollage newCollage(size, subs, replaceable);

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

int* bitCollage::getSequence()
{
	if (active)
	{
		if (displays == 0) { displays++; return imageArray; }

		if (displays < _subscriptions)
		{
			if (randomSeed != true) { srand(time(0)); randomSeed = true; }
			int numOmit = rand() % 4;
			if (numOmit == 0) { numOmit++; }
			int* omit = new int[numOmit];
			bool selected = false;

			for (int s = 0; s < numOmit; s++)
			{
				while (!selected)
				{
					int index = rand() % size;
					if (!exists(index, omit, numOmit)) { omit[s] = index; selected = true; }
				}
				selected = false;
			}
			int t = 0;
			int* local = new int[size - numOmit];

			for (int i = 0; i < size; i++)
			{
				if (!exists(i, omit, numOmit)) { local[t] = imageArray[i]; t++; }
			}
			delete[] omit;
			displays++;
			return local;
			delete[] local;
		}
		if (displays == _subscriptions) { active = false; }
		return 0;
	}
}

void bitCollage::replace(int index, int replacement)
{
	if (active)
	{
		int old = imageArray[index];
		int marker = 0;
		int x = 0;
		int y = 0;
		if (old % 2 == 0 && EvenOrOdd)
		{
			int temp = imageArray[marker];
			while (temp != old)
			{
				temp = imageArray[marker];
				x = marker;
				marker++;
			}
			if (temp == old)
			{
				imageArray[x] = replacement;
				replacements++;
			}
		}
		if (old % 2 == 1 && !EvenOrOdd)
		{
			int temp = imageArray[marker];
			while (temp != old)
			{
				temp = imageArray[marker];
				y = marker;
				marker++;
			}
			if (temp == old)
			{
				imageArray[y] = replacement;
				replacements++;
			}
		}
	}
}

int bitCollage::whoAmI()
{
	return 1;
}


