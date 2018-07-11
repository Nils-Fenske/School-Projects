/* Nils Fenske
    3/9/2016
    Programming Assignment 6
    Collage Interface v1

Interface Invariants

This interface is teh outline for collage type objects such as ImageCollage,
BitCollage, CyclicCollage, and CollageReview objects. 

*/

namespace P6
{
    public interface Collage
    {
        int getSubs();
        int getCount();
        void addImage(int id);
        int[] getSequence();
        void replace(int index, int replacement);
        string whoAmI();
    }
}