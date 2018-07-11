/* Nils Fenske
2/22/2016
Programming Assignment 4
*/

#include "collageReview.cpp"
#include "imageCollage.cpp"
#include "bitCollage.cpp"
#include "cyclicCollage.cpp"
#include "review.cpp"
#include <iostream>

const int DATE = 2222016; // DO NOT START WITH ZERO IF MONTH IS LESS THAN 10

void build(collageReview**& H, int size);
void score(collageReview**& H, int size);
void print(collageReview**& H, int size);

int main()
{
	srand(time(0));

	const int size = ((rand() % 10) + 1) * 2;
	
	collageReview** hetero = new collageReview*[size];

	build(hetero, size);
	score(hetero, size);
	print(hetero, size);
}

void build(collageReview**& H, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		int type = (rand() % 3) + 1;

		if (type == 1)
		{
			int quantity = rand() % 10;
			if (quantity < 2) { quantity++; }
			int subs = rand() % 10 / 2;
			if (subs == 0) { subs++; }
			bool free = rand() % 2;
			int mmddyyyy = DATE;

			H[i] = new collageReview(quantity, subs, free, mmddyyyy);

			for (int n = 0; n < quantity; n++)
			{
				int id = rand() % 10000;
				H[i]->addImage(id);
			}
		}

		if (type == 2)
		{
			int quantity = rand() % 10;
			if (quantity < 2) { quantity++; }
			int subs = rand() % 10 / 2;
			if (subs == 0) { subs++; }
			bool replaceable = rand() % 2;
			bool free = rand() % 2;
			int mmddyyyy = DATE;

			H[i] = new collageReview(quantity, subs, replaceable, free, mmddyyyy);

			for (int n = 0; n < quantity; n++)
			{
				int id = rand() % 10000;
				H[i]->addImage(id);
			}
		}

		if (type == 3)
		{
			int quantity = rand() % 10;
			if (quantity < 2) { quantity++; }
			int subs = rand() % 10 / 2;
			if (subs == 0) { subs++; }
			int shift = rand() % 3 + 1;
			bool free = rand() % 2;
			int mmddyyyy = DATE;

			H[i] = new collageReview(quantity, subs, shift, free, mmddyyyy);

			for (int n = 0; n < quantity; n++)
			{
				int id = rand() % 10000;
				H[i]->addImage(id);
			}
		}
	}
}

void score(collageReview**& H, int size) 
{
	int r;
	int e;

	for (int i = 0; i < size; i++) 
	{
		r = ((rand() % 10) / 2);
		if (r == 0) { r++; }
		H[i]->setRating(r);

		e = ((rand() % 100));
		if (e == 0) { e = 100; }
		H[i]->setExperience(e);
	}

}

void print(collageReview**&  H, int size) 
{
	for (int i = 0; i < size; i++)
	{
		H[i]->display();
		cout << "Rating: " << H[i]->getRating() << endl;
		cout << "Experience: " << H[i]->getExperience() << endl;
		cout << "Weighted Score: " << H[i]->weighted() << endl;
		cout << endl;
		cout << endl;
	}
}
