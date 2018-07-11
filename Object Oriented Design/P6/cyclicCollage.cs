/* Nils Fenske
    3/9/2016
    Programming Assignment 6
    CyclicCollage class v4

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

namespace P6
{
    class cyclicCollage : imageCollage, Collage
    {
        private int shiftValue;

        // Preconditions: Full array of images. 
        // Postconditions: Object holds same images shifted to the right by value of shiftValue.
        private void shift()
        {
            int temp = imageArray[size - 1];
            for (int i = size - 1; i > 0; i--)
            {
                imageArray[i] = imageArray[i - 1];
            }
            imageArray[0] = temp;
        }

        // Preconditions: User is responsible for passing in size and subscriptions and shift value.
        // Postconditions: Object set in initial innactive state.
        public cyclicCollage(int s, int c, int shift) : base(s, c)
        {
            size = s;
            imageArray = new int[size];
            count = 0;
            displays = 0;
            subscriptions = c;
            shiftValue = shift;
            replacements = 0;
            active = false;
        }

        // Preconditions: Object must be active. 
        // Postconditions: Image information is shifted and displayed by the shift value before each display preceeding the inital display.
        //                 Object is possibly deactivated if number of display subscriptions has been reached.  
        public override int[] getSequence()
        {
            if (active)
            {
                if (displays == 0) { displays++; return imageArray; }

                if (displays < subscriptions)
                {
                    for (int i = 0; i < shiftValue; i++) { shift(); }

                    displays++;
                    return imageArray;
                }
                if (displays == subscriptions) { active = false; return null; }
            }
            return null;
        }

        public override string whoAmI()
        {
            return "cyclicCollage";
        }
    }
}
