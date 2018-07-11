/* Nils Fenske
   1/20/2016
   Programming Assignment 2
   Driver Test Code v1.0
*/

using System;

namespace P2
{
    class P2
    {
        public static Random randNum = new Random();

        static void Main(string[] args)
        {
            const int numStudents = 5;
            studentStat[] studentArray = new studentStat[numStudents];

            generateStudents(studentArray);

            printStudentInfo(studentArray);

            studentStat initialStudent = studentArray[0];
            cohortStat group = new cohortStat(initialStudent);

            generateCohort(studentArray, group);

            printCohort(group);
        }

        public static void generateStudents(studentStat[] studentArray)
        {
            for (int i = 0; i < studentArray.Length; i++)
            {
                studentArray[i] = (newStudent());
            }
        }

        public static studentStat newStudent()
        {
            int id = randNum.Next(100000, 1000000);
           
            return new studentStat(id);
        }

        public static void makePayments(studentStat student)
        {
            for(int i = 0; i < (randNum.Next(0, (student.numDegrees + 1))); i++)
            {
                int amount = randNum.Next(1000, 100001);
                student.makePayment(i, amount) ;
            }
        }

        public static void printStudentInfo(studentStat[] studentArray)
        {
            for (int i = 0; i < studentArray.Length; i++)
            {
                Console.WriteLine();
                Console.WriteLine("Debt Amounts");
                for (int d = 0; d < studentArray[i].numDegrees; d++)
                {
                    Console.WriteLine((d + 1) + ". " + studentArray[i].degreeDebt(d));
                }
                Console.WriteLine("Most Burdensome: " + studentArray[i].viewMostBurdensome());

                makePayments(studentArray[i]);

                Console.WriteLine("Number of Degrees Paid Off: " + studentArray[i].numDeactivated);
                Console.WriteLine();
            }
        }

        public static void generateCohort(studentStat[] studentArray, cohortStat group)
        {
            for (int i = 1; i < studentArray.Length; i++)
            {
                group.addStudent(studentArray[i]);
            }
        }

        private static void printCohort(cohortStat group)
        {
            Console.WriteLine("Total Current Student Loans Matriculating: " + group.currentMatriculation());
            Console.WriteLine("Current Largest Loan: " + group.currentLargest());
            Console.WriteLine("Current Smallest Loan: " + group.currentSmallest());
            Console.WriteLine("Current Number of Loans Paid Off: " + group.currentPaidOff());
        }
    }
}
