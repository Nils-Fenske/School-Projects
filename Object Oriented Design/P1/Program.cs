// Nils Fenske
// P1
// 1/10/2016
//

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P1 {

    class Program {

        public static Random randNum = new Random();

        static void Main(string[] args)
        {
            const int numStudents = 5;
            debtStats[] debtArray = new debtStats[numStudents];

            initialize(debtArray);

            GoToSchool(debtArray);

            printStudentInfo(debtArray);
        }

        public static void initialize(debtStats[] x)
        {
            for (int i = 0; i < x.Length; i++)
            {
                x[i] = newStudent();
            }
        } 

        public static debtStats newStudent() {

            int id = randNum.Next(100000, 1000000);
            int startDate = randNum.Next(1900, 2001);
            int graduation = randNum.Next(startDate + 1, 2002);
            return new debtStats(id, startDate, graduation);
        }

        public static void GoToSchool(debtStats[] m) {

            for(int s = 0; s < m.Length; s++ )
            {
                int loan;
                int l = randNum.Next(1, 10);
                for (int i = 0; i <= l; i++)
                {
                    loan = randNum.Next(1000, 100001);
                    m[s].addLoan(loan);
                }

                int grant;
                int g = randNum.Next(1, 10);
                for (int i = 0; i <= g; i++)
                {
                    grant = randNum.Next(1000, 100001);
                    m[s].addGrant(grant);

                }
                
                int e = randNum.Next(1, 3);
                bool extend = false;
                if (e > 1) { extend = true; }
                if (extend)
                {
                    e = randNum.Next(1, 5);
                    m[s].extendGraduation(e);
                }
            }
        } 

        public static bool simulatePayment(debtStats student)
        {
            int pay = randNum.Next(0, 2);
            if (pay == 1)
            {
                int payment = randNum.Next(500, 5001);
                student.makePayment(payment);
            }
            return student.loanDecrease;
        }

        public static bool testThreshold(debtStats student, int threshold)
        {
            return (student.testThreshold(threshold));
        }

        public static int calcAmortization(debtStats student, int years)
        {
            int amortization = student.loanTotal() / years;
            return amortization;
        }

        public static void printStudentInfo(debtStats[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                Console.WriteLine();
                Console.WriteLine("Loan Amount Has Increased: " + arr[i].loanIncrease);
                Console.WriteLine("Loan Amount Has Decreased (Student Has Made Payment): " + simulatePayment(arr[i]));
                Console.WriteLine("Loan Threshold Met: " + testThreshold(arr[i], randNum.Next(5000, 1000001)));
                Console.WriteLine("Amount Amortized by year: " + calcAmortization(arr[i], randNum.Next(1, 31)));
                Console.WriteLine();
            }
        }
    }
}
