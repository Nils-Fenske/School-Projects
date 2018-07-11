/* Nils Fenske
   2/1/2016
   Programming Assignment 3
*/

using System;

namespace P6
{
    class Program
    {
        public static Random rand = new Random();

        public const int DATE = 3092016;

        static void Main(string[] args)
        {
            const int collageSize = 6;

            const int reviewSize = 4;

            Collage[] collageHetero = buildCollage(collageSize);

            review[] reviewHetero = buildReview(reviewSize);

            score(reviewHetero, reviewSize);

            collagePrint(collageHetero, collageSize);

            reviewPrint(reviewHetero, reviewSize);
        }

        // This method builds a collection of imageCollage, bit collage, cyclicCollage, and collageReview objects. 
        public static Collage[] buildCollage(int size)
        {
            Collage[] H = new Collage[size];

            for (int i = 0; i < size; i++)
            {
                int quantity;
                int subs;
                bool free;
                int mmddyyyy;
                bool EvenOrOdd;
                int shiftValue;
                int id;

                if (i % size == 0)
                {
                    quantity = rand.Next(4, 11);
                    subs = rand.Next(5, 11);
                    H[i] = new imageCollage(quantity, subs);

                    for (int a = 0; a < quantity; a++)
                    {
                        id = rand.Next(1000, 10000);
                        H[i].addImage(id);
                    }
                }
                else if (i % size == 1)
                {
                    quantity = rand.Next(4, 11);
                    subs = rand.Next(5, 11);
                    EvenOrOdd = false;
                    int y = rand.Next(0, 2);
                    if (y == 1) { EvenOrOdd = true; }
                    H[i] = new bitCollage(quantity, subs, EvenOrOdd);

                    for (int a = 0; a < quantity; a++)
                    {
                        id = rand.Next(1000, 10000);
                        H[i].addImage(id);
                    }
                }
                else if (i % size == 2)
                {
                    quantity = rand.Next(4, 11);
                    subs = rand.Next(5, 11);
                    shiftValue = rand.Next(1, 4);
                    H[i] = new cyclicCollage(quantity, subs, shiftValue);

                    for (int a = 0; a < quantity; a++)
                    {
                        id = rand.Next(1000, 10000);
                        H[i].addImage(id);
                    }
                }
                else if (i % size == 3)
                {
                    quantity = rand.Next(4, 11);
                    subs = rand.Next(5, 11);
                    free = false;
                    int x = rand.Next(0, 2);
                    if (x == 1) { free = true; }
                    mmddyyyy = DATE;
                    H[i] = new collageReview(quantity, subs, free, mmddyyyy);

                    for (int a = 0; a < quantity; a++)
                    {
                        id = rand.Next(1000, 10000);
                        H[i].addImage(id);
                    }
                }
                else if (i % size == 4)
                {
                    quantity = rand.Next(4, 11);
                    subs = rand.Next(5, 11);
                    free = false;
                    int x = rand.Next(0, 2);
                    if (x == 1) { free = true; }
                    mmddyyyy = DATE;
                    EvenOrOdd = false;
                    int y = rand.Next(0, 2);
                    if (y == 1) { EvenOrOdd = true; }
                    H[i] = new collageReview(quantity, subs, EvenOrOdd, free, mmddyyyy);

                    for (int a = 0; a < quantity; a++)
                    {
                        id = rand.Next(1000, 10000);
                        H[i].addImage(id);
                    }
                }
                else if (i % size == 5)
                {
                    quantity = rand.Next(4, 11);
                    subs = rand.Next(5, 11);
                    shiftValue = rand.Next(1, 4);
                    free = false;
                    int x = rand.Next(0, 2);
                    if (x == 1) { free = true; }
                    mmddyyyy = DATE;
                    H[i] = new collageReview(quantity, subs, shiftValue, free, mmddyyyy);

                    for (int a = 0; a < quantity; a++)
                    {
                        id = rand.Next(1000, 10000);
                        H[i].addImage(id);
                    }
                }

            }
            return H;
        }

        // This method builds a collection of review and collageReview objects.
        public static review[] buildReview(int size)
        {
            review[] H = new review[size];

            for (int i = 0; i < size; i++)
            {
                int quantity;
                int subs;
                bool free;
                int mmddyyyy;
                bool EvenOrOdd;
                int shiftValue;

                if (i % size == 0)
                {
                    free = false;
                    int x = rand.Next(0, 2);
                    if (x == 1) { free = true; }
                    mmddyyyy = DATE;
                    H[i] = new review(free, mmddyyyy);
                }
                else if (i % size == 1)
                {
                    quantity = rand.Next(4, 11);
                    subs = rand.Next(5, 11);
                    free = false;
                    int x = rand.Next(0, 2);
                    if (x == 1) { free = true; }
                    mmddyyyy = DATE;
                    H[i] = new collageReview(quantity, subs, free, mmddyyyy);
                }
                else if (i % size == 2)
                {
                    quantity = rand.Next(4, 11);
                    subs = rand.Next(5, 11);
                    free = false;
                    int x = rand.Next(0, 2);
                    if (x == 1) { free = true; }
                    mmddyyyy = DATE;
                    EvenOrOdd = false;
                    int y = rand.Next(0, 2);
                    if (y == 1) { EvenOrOdd = true; }
                    H[i] = new collageReview(quantity, subs, EvenOrOdd, free, mmddyyyy);
                }
                else if (i % size == 3)
                {
                    quantity = rand.Next(4, 11);
                    subs = rand.Next(5, 11);
                    shiftValue = rand.Next(1, 4);
                    free = false;
                    int x = rand.Next(0, 2);
                    if (x == 1) { free = true; }
                    mmddyyyy = DATE;
                    H[i] = new collageReview(quantity, subs, shiftValue, free, mmddyyyy);
                }
            }
            return H;
        }

        // This function rates the review objects in a collection. 
        public static void score(review[] ReviewHetero, int size)
        {
            int r;
            int e;

            for (int i = 0; i < size; i++)
            {
                r = rand.Next(1, 6);
                ReviewHetero[i].setRating(r);

                e = rand.Next(1, 101);
                ReviewHetero[i].setExperience(e);
            }
        }
        
        // This function prints out the image arrays (their max number of times).
        public static void collagePrint(Collage[] collageHetero, int size)
        {
            for (int i = 0; i < size; i++)
            {
                Console.WriteLine(collageHetero[i].whoAmI());

                for (int k = 0; k < collageHetero[i].getSubs(); k++)
                {
                    int[] arr = collageHetero[i].getSequence();
                    Console.Write("[ ");
                    for (int m = 0; m < arr.Length; m++)
                    {
                        Console.Write(arr[m] + " ");
                    }
                    Console.WriteLine("]");
                }
                Console.WriteLine();
            }
        }

        // This function prints out the information of each review object.
        public static void reviewPrint(review[] reviewHetero, int size)
        {
            for (int i = 0; i < size; i++)
            {
                if (reviewHetero[i].attachment()) { Console.WriteLine("Attached Review"); }
                else { Console.WriteLine("Unattached Review"); }
                Console.WriteLine("Rating: " + reviewHetero[i].getRating());
                Console.WriteLine("Experience: " + reviewHetero[i].getExperience());
                Console.WriteLine("Weighted: " + reviewHetero[i].weighted());
                Console.WriteLine();
            }
        }
    }
}
