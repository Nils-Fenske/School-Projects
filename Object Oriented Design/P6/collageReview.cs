/* Nils Fenske
    3/9/2016
    Programming Assignment 6
    CollageReview class v2

Class Invariants

This class is a collage object of type image, bit, or cyclic. It is also a review 
object. 

================================================================================

Interface Invariants

This class has the same user capabilities as the collage objects. 

================================================================================

Implementation Invariants

The object contains a collage interface delegate. There are specific constructors 
based on parameters that the user passes in for each of the collage types. 

*/

namespace P6
{
    public class collageReview : review, Collage
    {
        private bool iCollage;
        private bool bCollage;
        private bool cCollage;

        private Collage thing;

        public collageReview(int quantity, int subs, bool freeOrNot, int mmddyyyy) : base(freeOrNot, mmddyyyy)
        {
            iCollage = true;
            bCollage = false;
            cCollage = false;

            thing = new imageCollage(quantity, subs);
            attached = true;
        }

        public collageReview(int quantity, int subs, bool replaceable, bool freeOrNot, int mmddyyyy) : base(freeOrNot, mmddyyyy)
        {
            iCollage = false;
            bCollage = true;
            cCollage = false;

            thing = new bitCollage(quantity, subs, replaceable);
            attached = true;
        }

        public collageReview(int quantity, int subs, int shift, bool freeOrNot, int mmddyyyy) : base(freeOrNot, mmddyyyy)
        {
            iCollage = false;
            bCollage = false;
            cCollage = true;

            thing = new cyclicCollage(quantity, subs, shift);
            attached = true;
        }

        public string whoAmI()
        {
            if (iCollage) { return "ImageCollage Review"; }
            if (bCollage) { return "BitCollage Review"; }
            if (cCollage) { return "CyclicCollage Review"; }
            return "NO ONE";
        }

        public void addImage(int id)
        {
            thing.addImage(id);
        }

        public int[] getSequence()
        {
            return thing.getSequence();
        }

        public void replace(int index, int replacement)
        {
            thing.replace(index, replacement);
        }

        public int getSubs()
        {
            return thing.getSubs();
        }

        public int getCount()
        {
            return thing.getCount();
        }
    }
}
