/* Nils Fenske
    2/1/2016
    Programming Assignment 3
    BitCollage class v1

Class Invariants

This class is an imageCollage descendant with the trait of omitting a 1, 2, or 3
(randomly) number of images each display as well as only being able to replace 
even or odd image id's (set by user).
================================================================================

Interface Invariants

The user creates a collage by passing in the size and number of subscriptions paid for as
well as wether even or odd images are replaceable. The user has the ability to read 
the number of items in the sequence as well as the number of subscriptions or display's 
available to them. The user also can add images by passing in an image id. The user 
can display images as well as replace images by knowing the index of the image they 
want to replace and passing in the new one. A user passes in a "true" boolean to the cunstructor
to allow even numbers to be replaced and vice versa for odd. 

================================================================================

Implementation Invariants

Data members are protected to be used by subclasses. Image id's are stored in an 
array. The object is constructed in initial state with values at 0 and status at 
innactive until sequence is full. Displaying the images is kept track of in order to deactivate
after a certain number of uses (subscriptions). The user is responsible for knowing the
index of the image they wish to replace as well as passing in the new image. Number of images 
cannot be reduced. Random number generator is used to omit 1, 2, or 3 images. Private exists function is 
used to check if a number exists in an array. This is used when deciding which numbers to omit. 
In a more realistic design the user would be aware of the ids of images in the sequence and would be able 
to pass in which ones they wanted omitted. Becuase images are generated randomly here, I had to do this
within the class. 

*/

using System;

namespace P3
{
    class bitCollage : imageCollage
    {
        private bool EvenOrOdd;

        private Random rand = new Random();

        // Preconditions: Array being passed in must be initialized 
        // Postconditions: Returns and bool. 
        private bool exists(int x, int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] == x) { return true; }
            }
            return false;
        }

        // Preconditions: User is responsible for passing in size and subscriptions and true for even / false for odd, replacement.
        // Postconditions: Object set in initial innactive state.
        public bitCollage(int s, int c, bool replaceable):base(s, c)
        {
            size = s;
            imageArray = new int[size];
            _count = 0;
            displays = 0;
            _subscriptions = c;
            replacements = 0;
            EvenOrOdd = replaceable;
            active = false;
        }

        // Preconditions: Object must be active.
        // Postconditions: Image information is possibly replaced and/or ommitted before each display preceeding the inital display.
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

                int numOmit = rand.Next(1, 4);
                int[] omit = new int[numOmit];
                bool selected = false;

                for (int s = 0; s < numOmit; s++)
                {
                    while (!selected)
                    {
                        int index = rand.Next(0, size);
                        if (!exists(index, omit)) { omit[s] = index; selected = true; }
                    }
                    selected = false;
                }

                Console.WriteLine("Omitting: ");
                for (int i = 0; i < numOmit; i++)
                {
                    Console.Write(imageArray[omit[i]] + " ");
                }
                Console.WriteLine();
                bool omitted;

                Console.Write("Bitwise Image Sequence: (");

                for (int i = 0; i < size - 2; i++)
                {
                    omitted = false;

                    for (int m = 0; m < numOmit - 1; m++)
                    {
                        if (imageArray[i] == imageArray[omit[m]]) { omitted = true; }
                    }
                    if (!omitted) { Console.Write(" " + imageArray[i] + ","); }

                }

                omitted = false;
                for (int m = 0; m < omit.Length - 1; m++)
                {
                    if (imageArray[size - 1] == imageArray[omit[m]]) { omitted = true; }
                }
                if (!omitted)
                {
                    Console.Write(imageArray[size - 1] + ")");
                }
                else
                {
                    Console.Write(")");
                }

                displays++;
                if (displays == _subscriptions) { active = false; }
            }
            Console.WriteLine();
        }

        // Preconditions: Objject must be active. User is respnsible for knowing index of image they wish to replace. Must pass in new image.
        //                Only even or odd images are replaced based on user setting when object initialized.
        // Postconditions: Object still full and active with different sequence.
        public override void replace(int index, int replacement)
        {
            if (active)
            {
                int old = imageArray[index];
                Console.WriteLine("Attempting to Replace " + old + " with " + replacement);
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
    }
}
