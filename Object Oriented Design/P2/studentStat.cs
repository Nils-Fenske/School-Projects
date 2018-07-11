/*  Nils Fenske
    1/20/2016
    Programming Assignment 2
    studentStat class v1.0

Class Invariants
                                                                
The studentStat class encapsulates debtStat objects. A studentStat object has-a 
debtStat object. A student must have a valid id.

================================================================================

Interface Invariants

The client may query the number of degrees and the number of degrees 
that have been fully paid for (deactivated). Degree's paid fully paid for are 
visible as a total of 0. The client has access to the viewMostBurdnesome() function 
as well. The client may view the debt burden of a degree by passing in a valid degree 
index. The index must be between 1 and the number of degrees. The client may also 
make a payment, partial or in full for a degree by passing in a valid index as well 
as a payment amount.

================================================================================

Implementation Invariants

In a more serious application the students info such as degree start dates, 
graduation dates, number of degrees, and loan information would be loaded from a 
third party i.e. college financial services. I used a random number generator to 
simulate information that was needed by debtStats but did not want the client to be 
responsible for entering. There is much more to the debtstat class that is not used 
here but could be utilized by a client other than a student. I used a List to 
organize debtStat objects because of ease with adding. A student in reality may add 
or drop degrees at any time in which case this would be useful.                                                                        

*/
using System;
using System.Collections.Generic;

namespace P2
{
    public class studentStat
    {
        private static Random randNum = new Random();

        private int _numDegrees;
        public int numDegrees
        {
            get
            {
                return _numDegrees;
            }
        }

        private int _numDeactivated;
        public int numDeactivated
        {
            get
            {
                return _numDeactivated;
            }
        }

        private List<debtStat> degreeList;

        // Preconditions: Client must pass in a valid id of 6 digits
        // Postconditions: studentStat object in valid initial state. Array of debtStat objects in valid initial state
        public studentStat(int id)
        {
            int startDate = randNum.Next(1900, 2001);
            int graduation = randNum.Next(startDate + 1, 2002);
            _numDegrees = randNum.Next(0, 5);

            _numDeactivated = 0;
            degreeList = new List<debtStat>();
            for (int i = 0; i < _numDegrees; i++)
            {
                degreeList.Add(new debtStat(id, startDate, graduation));
                degreeList[i].addLoan(randNum.Next(1000, 100001));
            }

        }

        // Preconditions: Will run with no active debt. Will return 0.
        // Postconditions: N/A
        public int viewMostBurdensome()
        {
            int max = 0;
            for (int i = 0; i < _numDegrees; i++)
            {
                int temp = degreeList[i].debtTotal();
                if (temp > max) { max = temp; }
            }
            return max;
        }

        // Preconditions: Client must pass a valid index of degree within range of 1 to numDegrees. Client must pass non negative payment amount.
        //                Payment amount may be more than debt amount. 
        // Postconditions: Degree may be fully paid for. Degree will be "deactivated". 
        public void makePayment(int degree, int amount)
        {
            int temp = degreeList[degree].debtTotal();
            if (amount < temp) { degreeList[degree].makePayment(amount); }
            else { degreeList[degree].makePayment(temp); }
            if (degreeList[degree].debtTotal() == 0) { degreeList[degree].deactivate(); _numDeactivated++; }
        }

        // Preconditions: Client must pass a valid index of degree within range of 1 to numDegrees. 
        // Postconditions: N/A
        public int degreeDebt(int degree)
        {
            return degreeList[degree].debtTotal();
        }
    }
}
