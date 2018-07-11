/* Nils Fenske
    3/9/2016
    Programming Assignment 6
    Review Class v2

Class Invariants

The review class contains a date, if the rating was free, a rating, an experience, 
and a weighted score. The review object is either attached or unattached.

================================================================================

Interface Invariants

The user must pass in if it was free or not and the date of the rating. The user can set 
the rating and experience. The user can then query the rating and experience as well as
the weighted score. The client has no control over the state of being attached or not.
================================================================================

Implementation Invariants

Rating and Experience are initially set to 0 and attached is set to false. The only way a 
review object can be atached is if it is inherited by another class that uses a review.
That class can set attachment to true. The algorithm to get a weighted score is made up
and in this instance does not reflect any real life info or requirments.
*/

namespace P6
{
    public class review
    {
        private bool free;
        private int date;
        private int rating;
        private int experience;

        protected bool attached;

        public review(bool freeOrNot, int mmddyyyy)
        {
            free = freeOrNot;
            date = mmddyyyy;
            rating = 0;
            experience = 0;
            attached = false;
        }

        public void setRating(int userRating)
        {
            rating = userRating;
        }

        public int getRating()
        {
            return rating;
        }

        public void setExperience(int userExperience)
        {
            experience = userExperience;
        }

        public int getExperience()
        {
            return experience;
        }

        public int weighted()
        {
            return (rating * experience);
        }

        public bool attachment()
        {
            return attached;
        }
    }
}