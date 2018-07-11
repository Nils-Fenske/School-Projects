/* Nils Fenske
    2/1/2016
    Programming Assignment 3
    CyclicCollage class v1

Class Invariants

This class is an imageCollage descendant with the trait of shifting images by 3 on each 
display after the first. 

================================================================================

Interface Invariants

Same visibility as imageCollage of size count and subscriptions. Obects are initialised 
the same as imageCollage objects with the addition of the user passing in a shift value.
User also displays images the same way as an imageCollage object. 

================================================================================

Implementation Invariants

This class uses the same protecteded data members as the imageCollage with the addition of a 
shift value. The constructor is overridden with the addition of the shift value parameter beeing
passed in. There is a private shift function that is used during the display function.  
*/

using System;

namespace P3
{
    class cyclicCollage : imageCollage
    {
        private int shiftValue;

        // Preconditions: Full array of images. 
        // Postconditions: Object holds same images shifted to the right by value of shiftValue.
        private void shift()
        {
            int[] temp = new int[size];
            for (int i = 0; i < size; i++)
            {
                temp[i] = imageArray[i];
            }

            for (int k = 0; k < size; k++)
            {
                if (k + shiftValue < size)
                {
                    imageArray[k + shiftValue] = temp[k];
                }
                else
                {
                    imageArray[(k + shiftValue) % size] = temp[k];
                }
            }
        }

        // Preconditions: User is responsible for passing in size and subscriptions and shift value.
        // Postconditions: Object set in initial innactive state.
        public cyclicCollage(int s, int c, int shift):base(s, c)
        {
            size = s;
            imageArray = new int[size];
            _count = 0;
            displays = 0;
            _subscriptions = c;
            shiftValue = shift;
            replacements = 0;
            active = false;
        }

        // Preconditions: Object must be active. 
        // Postconditions: Image information is shifted and displayed by the shift value before each display preceeding the inital display.
        //                 Object is possibly deactivated if number of display subscriptions has been reached.  
        public override void display()
        {
            if (active)
            {
                if (displays == 0)
                {
                    Console.WriteLine();
                    Console.Write("Original Sequence: (");
                    for (int i = 0; i < size - 2; i++)
                    {
                        Console.Write(imageArray[i] + ", ");
                    }
                    Console.WriteLine(imageArray[size - 1] + ")");
                    Console.WriteLine("Subscriptions: " + _subscriptions);
                }

                Console.Write("Cyclic Image Sequence (" + (displays + 1) + "): (");

                if (displays > 0) { shift(); }

                for (int i = 0; i < size - 2; i++)
                {
                    Console.Write(imageArray[i] + ", ");
                }
                Console.Write(imageArray[size - 1] + ")");
                displays++;
                if (displays == _subscriptions) { active = false; }
                Console.WriteLine();
            }
        }
    }
}
