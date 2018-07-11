/* Nils Fenske
   2/1/2016
   Programming Assignment 3
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P3
{
    class Program
    {
        public static Random rand = new Random();

        static void Main(string[] args)
        {
            const int size = 3;

            imageCollage[] hetero = heteroCollage(size);

            process(hetero);
        }

        // This method initializes 1 imageCollage, 1 cyclicCollage, and 1 bitCollage and fills them with random sequnce sizes, subscriptions lengths and image ids.
        // As well as random parameters specific to the object type. 
        public static imageCollage[] heteroCollage(int size)
        {
            imageCollage[] H = new imageCollage[size];

            int iQuantity = rand.Next(4, 11);
            H[0] = new imageCollage(iQuantity, rand.Next(5, 11));
            for (int n = 0; n < iQuantity; n++)
            {
                H[0].addImage(rand.Next(1000, 10000));
            }

            int cQuantity = rand.Next(4, 11);
            H[1] = new cyclicCollage(cQuantity, rand.Next(5, 11), 3);
            for (int n = 0; n < cQuantity; n++)
            {
                H[1].addImage(rand.Next(1000, 10000));
            }

            bool replaceable = false;
            int x = rand.Next(0, 1);
            if (x == 1) { replaceable = true; }
            int bQuantity = rand.Next(4, 11);
            H[2] = new bitCollage(bQuantity, rand.Next(5, 11), replaceable);
            for (int n = 0; n < bQuantity; n++)
            {
                H[2].addImage(rand.Next(1000, 10000));
            }
            return H;
        }

        // This method calls the display functions for the objects. The imageCollage is only displayed once. The other two are displayed to their full potential. 
        // Replacement is demonstrated on the bitCollage. 
        public static void process(imageCollage[] list)
        {
            list[0].display();

            for (int d = 0; d < list[1].subscriptions; d++)
            {
                list[1].display();
            }

            for (int d = 0; d < list[2].subscriptions; d++)
            {
                list[2].display();
                int index = rand.Next(0, list[2].count);
                list[2].replace(index, rand.Next(1000, 10000));
            }
        }
    }
}
