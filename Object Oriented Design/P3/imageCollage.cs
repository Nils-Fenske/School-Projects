/* Nils Fenske
    2/1/2016
    Programming Assignment 3
    ImageCollage class v1

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

using System;

namespace P3
{
    class imageCollage
    {
        protected bool active;
        protected int size;
        protected int _count;
        public int count
        {
            get
            {
                return _count;
            }
        }
        protected int displays;
        protected int _subscriptions;
        public int subscriptions
        {
            get
            {
                return _subscriptions;
            }
        }
        protected int replacements;

        protected int[] imageArray;

        // Preconditions: User is responsible for passing in size and subscriptions. 
        // Postconditions: Object set in initial innactive state.
        public imageCollage(int s, int c)
        {
            size = s;
            imageArray = new int[size];
            _count = 0;
            displays = 0;
            _subscriptions = c;
            replacements = 0;
        }

        // Preconditions: User passes in id of image. Cannot add more than size set by user.
        // Postconditions: Once object is full, object is set in active state and no more can be added.
        public void addImage(int id)
        {
            if (_count < size)
            {
                imageArray[count] = id;
                _count++;
            }

            if (_count == size) { active = true; }
        }

        // Preconditions: object must be active. Prints out the sequnce of images as well as number of subscriptions. 
        // Postconditions: Possibly deactivated if number of subscriptions reached. 
        public virtual void display()
        {
            if (active)
            {
                Console.Write("Image Sequence: (");
                for (int i = 0; i < size - 2; i++)
                {
                    Console.Write(imageArray[i] + ", ");
                }
                Console.WriteLine(imageArray[size - 1] + ")");
                Console.WriteLine("Subscriptions: " + _subscriptions);
                displays++;
                if (displays == _subscriptions) { active = false; }
            }
        }

        // Preconditions: Object must be active. User is respnsible for knowing index of image they wish to replace. Must pass in new image. 
        // Postconditions: Object still full and active with different sequence. 
        public virtual void replace(int index, int replacement)
        {
            if (active)
            {
                int old = imageArray[index];
                int marker = 0;
                int temp = imageArray[marker];
                while (temp != old)
                {
                    marker++;
                    temp = imageArray[marker];
                }
                if (temp == old)
                {
                    imageArray[marker] = replacement;
                    replacements++;
                }
            }
        }
    }
}