/* Nils Fenske
2/22/2016
Programming Assignment 4
Review Class v1

Implementation Invariants

The object is initialized by a true or false, true if the rating was free or flase if it was not.It is
also initialized by a date written as mddyyyy or mmddyyyy with no dashes and cannot start with 0.

*/

#include "review.h"

review(bool freeOrNot, int mmddyyyy)
{
	free = freeOrNot;
	date = mmddyyyy;
	rating = 0;
	experience = 0;
}

void setRating(int _rating)
{
	rating = _rating;
}

int getRating()
{
	return rating;
}

void setExperience(int _experience)
{
	experience = _experience;
}

int getExperience() 
{
	return experience;
}

int weighted()
{
	return (rating * experience);
}
