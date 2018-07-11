/* Nils Fenske
2/22/2016
Programming Assignment 4
Review Class v1

Class Invariants

This class conains data on an object being reviewed. The user can set a rating and an
experience which can be combined into a weighted score.

================================================================================

Interface Invariants

The user has the ability to set a rating (1 - 5) or experience (1 - 100) as well as call for a rating or
experience.They can also ask for the weighted score.

*/

#ifndef REVIEW
#define REVIEW

#include <fstream>
#include <iostream>

using namespace std;

class review 
{
protected:
	bool free;
	int date;
	int rating;
	int experience;

public:
	review();

	// Preconditions:  
	// Postconditions: Object constructed with default values including info passed in by user.
	review(bool freeOrNot, int mmddyyyy);

	~review();

	// Preconditions:  
	// Postconditions: 
	void setRating(int _rating);

	// Preconditions:  
	// Postconditions: 
	int getRating();

	// Preconditions:  
	// Postconditions: 
	void setExperience(int _experience);

	// Preconditions:  
	// Postconditions: 
	int getExperience();

	// Preconditions:  
	// Postconditions: 
	int weighted();
};
#endif
