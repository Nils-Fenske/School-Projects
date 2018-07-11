/* Nils Fenske
   3/2/2016
   P5
*/

#include "imageCollage.cpp"
#include "bitCollage.cpp"
#include "cyclicCollage.cpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

void build(imageCollage**& collection, int size);
void print(imageCollage**& collection, int size);
void testOperators(imageCollage**& collection, int size);

int main() 
{

	srand(time(0));

	const int size = (((rand() % 4 + 2) * 3));

	imageCollage** hetero = new imageCollage*[size];

	build(hetero, size);
	print(hetero, size);
	cout << endl << endl;
	testOperators(hetero, size);

}

void build(imageCollage**& collection, int size)
{
	for (int i = 0; i < size; i++)
	{
		int quantity;
		int subs;
		bool EvenOrOdd;
		int shiftValue;
		int id;

		if (i % 3 == 0) 
		{ 
			quantity = (rand() % 10) + 3;
			subs = rand() % 6 + 5;
			collection[i] = new imageCollage(quantity, subs); 

			for (int a = 0; a < quantity; a++)
			{
				id = rand() % 9000 + 1000;
				*collection[i] + id;
			}
		}
		else if (i % 3 == 1)
		{
			quantity = (rand() % 10) + 3;
			subs = (rand() % 6) + 5;
			EvenOrOdd = rand() % 2;
			collection[i] = new bitCollage(quantity, subs, EvenOrOdd);

			for (int a = 0; a < quantity; a++)
			{
				id = rand() % 9000 + 1000;
				*collection[i] + id;
			}
		}
		else if (i % 3 == 2)
		{
			quantity = (rand() % 10) + 3;
			subs = (rand() % 6) + 5;
			shiftValue = (rand() % 3) + 1;
			collection[i] = new cyclicCollage(quantity, subs, shiftValue);

			for (int a = 0; a < quantity; a++)
			{
				id = rand() % 9000 + 1000;
				*collection[i] + id;
			}
		}
	}
}

void print(imageCollage**& collection, int size)
{
	for (int i = 0; i < size; i++)
	{
		
		if (collection[i]->whoAmI() == 0) { cout << "Image Collage (" << collection[i]->getSubscriptions() << "): " << endl; }
		if (collection[i]->whoAmI() == 1) { cout << "Bit Collage (" << collection[i]->getSubscriptions() << "): " << endl; }
		if (collection[i]->whoAmI() == 2) { cout << "Cyclic Collage (" << collection[i]->getSubscriptions() << "): " << endl; }
		cout << *collection[i] << endl;
		cout << *collection[i] << endl;
		cout << *collection[i] << endl;
		cout << endl;
	}
}

void testOperators(imageCollage**& collection, int size)
{
	for (int i = 0; i < size - 3; i++)
	{
		int x = 0;
		int type = collection[i]->whoAmI();

		if (i % 3 == 0)
		{
			cout << "Integer + Image Collage Test: " << endl;
			x = rand() % 9000 + 1000;
			x + *collection[i];
			cout << *collection[i] << endl;
			cout << endl << endl;

			cout << "Image Collage = image collage 1 + image collage 2: " << endl;
			imageCollage result1 = *collection[i] + *collection[i + 3];
			cout << result1;
			cout << endl << endl;

			cout << "Image Collage += Integer Test: " << endl;
			x = rand() % 9000 + 1000;
			*collection[i] += x;
			cout << *collection[i];
			cout << endl << endl;

			cout << "Image Collage 1 += Image Collage 2 Test: " << endl;
			*collection[i] += *collection[i + 3];
			cout << *collection[i];
			cout << endl << endl;

			cout << "Image Collage 1 == Image Collage 2 Test: " << endl;
			cout << (*collection[i] == *collection[i + 3]);
			cout << endl << endl;

			cout << "Image Collage 1 != Image Collage 2 Test: " << endl;
			cout << (*collection[i] != (*collection[i + 3]));
			cout << endl << endl;

			cout << "Image Collage 1 < Image Collage 2 Test: " << endl;
			cout << (*collection[i] < (*collection[i + 3]));
			cout << endl << endl;

			cout << "Image Collage 1 <= Image Collage 2 Test: " << endl;
			cout << (*collection[i] <= (*collection[i + 3]));
			cout << endl << endl;

			cout << "Image Collage 1 > Image Collage 2 Test: " << endl;
			cout << (*collection[i] > (*collection[i + 3]));
			cout << endl << endl;

			cout << "Image Collage 1 >= Image Collage 2 Test: " << endl;
			cout << (*collection[i] >= (*collection[i + 3]));
			cout << endl << endl;

			cout << "Image Collage [] Test: " << endl;
			int y = collection[i]->getCount();
			cout << collection[i][y];
			cout << endl << endl;
		}
		else if (i % 3 == 1)
		{
			cout << "Integer + Bit Collage Test: " << endl;
			x = rand() % 9000 + 1000;
			x + *((bitCollage*)collection[i]);
			cout << *collection[i] << endl;
			cout << endl << endl;

			cout << "Bit Collage = bit collage 1 + bit collage 2: " << endl;
			bitCollage result2 = *((bitCollage*)collection[i]) + *((bitCollage*)collection[i + 3]);
			cout << result2;
			cout << endl << endl;

			cout << "Bit Collage = bit collage 1 + image collage 1: " << endl;
			bitCollage result5 = *((bitCollage*)collection[i]) + *collection[i + 2];
			cout << result5;
			cout << endl << endl;

			cout << "Bit Collage += Integer Test: " << endl;
			x = rand() % 9000 + 1000;
			*((bitCollage*)collection[i]) += x;
			cout << *collection[i];
			cout << endl << endl;

			cout << "Bit Collage 1 += Bit Collage 2 Test: " << endl;
			*((bitCollage*)collection[i]) += *((bitCollage*)collection[i + 3]);
			cout << *((bitCollage*)collection[i]);
			cout << endl << endl;

			cout << "Bit Collage 1 += Image Collage 1 Test: " << endl;
			*((bitCollage*)collection[i]) += *collection[i + 2];
			cout << *((bitCollage*)collection[i]);
			cout << endl << endl;

			cout << "Bit Collage 1 == Bit Collage 2 Test: " << endl;
			cout << (*(bitCollage*)collection[i] == (*((bitCollage*)collection[i + 3])));
			cout << endl << endl;

			cout << "Bit Collage 1 != Bit Collage 2 Test: " << endl;
			cout << (*(bitCollage*)collection[i] != (*((bitCollage*)collection[i + 3])));
			cout << endl << endl;

			cout << "Bit Collage 1 < Bit Collage 2 Test: " << endl;
			cout << (*collection[i] < (*collection[i + 3]));
			cout << endl << endl;

			cout << "Bit Collage 1 <= Bit Collage 2 Test: " << endl;
			cout << (*collection[i] <= (*collection[i + 3]));
			cout << endl << endl;

			cout << "Bit Collage 1 > Bit Collage 2 Test: " << endl;
			cout << (*collection[i] > (*collection[i + 3]));
			cout << endl << endl;

			cout << "Bit Collage 1 >= Bit Collage 2 Test: " << endl;
			cout << (*collection[i] >= (*collection[i + 3]));
			cout << endl << endl;

			cout << "Bit Collage [] Test: " << endl;
			int y = collection[i]->getCount();
			cout << collection[i][y];
			cout << endl << endl;

		}
		else if (i % 3 == 2)
		{

			cout << "Integer + Cyclic Collage Test: " << endl;
			x = rand() % 9000 + 1000;
			x + *((cyclicCollage*)collection[i]);
			cout << *collection[i] << endl;
			cout << endl << endl;

			cout << "Cyclic Collage = cyclic collage 1 + cyclic collage 2: " << endl;
			cyclicCollage result3 = *((cyclicCollage*)collection[i]) + *((cyclicCollage*)collection[i + 3]);
			cout << result3;
			cout << endl << endl;

			cout << "Cyclic Collage = cyclic collage 1 + image collage 1: " << endl;
			cyclicCollage result5 = *((cyclicCollage*)collection[i]) + *collection[i + 2];
			cout << result5;
			cout << endl << endl;

			cout << "Cyclic Collage += Integer Test: " << endl;
			x = rand() % 9000 + 1000;
			*((cyclicCollage*)collection[i]) += x;
			cout << *collection[i];
			cout << endl << endl;

			cout << "Cyclic Collage 1 += Cyclic Collage 2 Test: " << endl;
			*((cyclicCollage*)collection[i]) += *((cyclicCollage*)collection[i + 3]);
			cout << *((cyclicCollage*)collection[i]);
			cout << endl << endl;

			cout << "Cyclic Collage 1 += Image Collage 1 Test: " << endl;
			*((cyclicCollage*)collection[i]) += *collection[i + 1];
			cout << *((cyclicCollage*)collection[i]);
			cout << endl << endl;

			cout << "Cyclic Collage 1 == Cyclic Collage 2 Test: " << endl;
			cout << (*(cyclicCollage*)collection[i] == (*((cyclicCollage*)collection[i + 3])));
			cout << endl << endl;

			cout << "Cyclic Collage 1 != Cyclic Collage 2 Test: " << endl;
			cout << (*(cyclicCollage*)collection[i] != (*((cyclicCollage*)collection[i + 3])));
			cout << endl << endl;

			cout << "Cyclic Collage 1 < Cyclic Collage 2 Test: " << endl;
			cout << (*collection[i] < (*collection[i + 3]));
			cout << endl << endl;

			cout << "Cyclic Collage 1 <= Cyclic Collage 2 Test: " << endl;
			cout << (*collection[i] <= (*collection[i + 3]));
			cout << endl << endl;

			cout << "Cyclic Collage 1 > Cyclic Collage 2 Test: " << endl;
			cout << (*collection[i] > (*collection[i + 3]));
			cout << endl << endl;

			cout << "Cyclic Collage 1 >= Cyclic Collage 2 Test: " << endl;
			cout << (*collection[i] >= (*collection[i + 3]));
			cout << endl << endl;

			cout << "Cyclic Collage [] Test: " << endl;
			int y = collection[i]->getCount();
			cout << collection[i][y];
			cout << endl << endl;
		}
	}
}

