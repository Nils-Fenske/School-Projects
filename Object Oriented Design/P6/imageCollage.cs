/* Nils Fenske
    3/9/2016
    Programming Assignment 6
    ImageCollage class v4

Class Invariants

This class of object holds a sequence of image id's

================================================================================

Interface Invariants

The user creates a collage by passing in the size and number of subscriptions paid for. 
The user has the ability to read the number of items in the sequence as well as the
number of subscriptions or display's available to them. The user also can add images 
by passing in an image id. The user can display images as well as replace images by 
knowing the index of the image they want to replace and passing in the new one. 

================================================================================

Implementation Invariants

Data members are protected to be used by subclasses. Image id's are stored in an 
array. The object is constructed in initial state with values at 0 and status at 
innactive until sequence is full. Displaying the images is kept track of in order to deactivate
after a certain number of uses (subscriptions). The user is responsible for knowing the
index of the image they wish to replace as well as passing in the new image. Number of images 
cannot be reduced. 

*/

namespace P6
{
    class imageCollage : Collage
    {
        protected bool active;
        protected int size;
        protected int count;
        protected int displays;
        protected int subscriptions;
        protected int replacements;

        protected int[] imageArray;

        // Preconditions: User is responsible for passing in size and subscriptions. 
        // Postconditions: Object set in initial innactive state.
        public imageCollage(int s, int c)
        {
            size = s;
            imageArray = new int[size];
            count = 0;
            displays = 0;
            subscriptions = c;
            replacements = 0;
        }

        // Preconditions: User passes in id of image. Cannot add more than size set by user.
        // Postconditions: Once object is full, object is set in active state and no more can be added.
        public virtual void addImage(int id)
        {
            if (count < size)
            {
                imageArray[count] = id;
                count++;
            }

            if (count == size) { active = true; }
        }

        // Preconditions: object must be active. Prints out the sequnce of images as well as number of subscriptions. 
        // Postconditions: Possibly deactivated if number of subscriptions reached. 
        public virtual int[] getSequence()
        {
            if (active)
            {
                if (displays < subscriptions)
                {
                    displays++;
                    return imageArray;
                }
            }
            if (displays == subscriptions) { active = false; }
            return null;
        }

        // Preconditions: Object must be active. User is respnsible for knowing index of image they wish to replace. Must pass in new image. 
        // Postconditions: Object still full and active with different sequence. 
        public virtual void replace(int index, int replacement)
        {
            if (active)
            {
                imageArray[index] = replacement;
                replacements++;
            }
        }

        public virtual string whoAmI()
        {
            return "imageCollage";
        }

        public int getSubs()
        {
            return subscriptions;
        }

        public int getCount()
        {
            return count;
        }
    }
}