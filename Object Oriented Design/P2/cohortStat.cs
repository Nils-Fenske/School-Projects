/*  Nils Fenske
    1/20/2016
    Programming Assignment 2
    cohortStat class v1.0

Class Invariants
                                                                
The cohortStat object encapsulates studentStat objects as well as debtStat 
objects. A cohortStat object has-a studentStat object. There must be one student
enrolled.

================================================================================

Interface Invariants

The client must pass in a valid initial student to initiate a cohortStat object. 
The client then has ability to add studentStat type students. The client has 
ability to call the methods; currentMatriculation(), currentlargest(), 
currentSmallest(), and currentPaidOff() (number deactivated). 

================================================================================

Implementation Invariants

The studentStat objects are in a private list to prevent the client from accessing
them. I used mehtods instead of variable mutators to return statistical information
so they can generate the most current data upon being called. 

*/

using System;
using System.Collections.Generic;

namespace P2
{
    public class cohortStat
    {
        private List<studentStat> students;

        // Preconditions: The client must pass a valid studentStat object to construct a cohortStat.
        // Postconditions: CohortStat object in valid initial state. List contains 1 student.
        public cohortStat(studentStat initialStudent)
        {
            students = new List<studentStat>();
            students.Add(initialStudent);
        }

        // Precondition: The client is responsible for apssing ina valid studentStat object.
        // Postcondition List will have more than one studentStat object.
        public void addStudent(studentStat student)
        {
            students.Add(student);
        } 

        // Precondition: Constructed cohortStat with at least one studentStat
        // Postcondition: If list contains no students with active debt then will return 0.
        public int currentMatriculation()
        {
            int total = 0; ;
            for (int i = 0; i < students.Count; i++)
            {
                for (int d = 0; d < students[i].numDegrees; d++)
                {
                    total += students[i].degreeDebt(d);
                }
            }
            return total;
        }

        // Precondition: Constructed cohortStat with at least one studentStat
        // Postcondition: If list contains no students with active debt then will return 0.
        public int currentLargest()
        {
            int largest = 0; ;
            for (int i = 0; i < students.Count; i++)
            {
                for (int d = 0; d < students[i].numDegrees; d++)
                {
                    int temp = students[i].degreeDebt(d);
                    if (temp > largest) { largest = temp; }
                }
            }
            return largest;
        }

        // Precondition: Constructed cohortStat with at least one studentStat
        // Postcondition: If list contains no students with active debt then will return 0.
        public int currentSmallest()
        {
            int smallest = currentLargest(); ;
            for (int i = 0; i < students.Count; i++)
            {
                for (int d = 0; d < students[i].numDegrees; d++)
                {
                    int temp = students[i].degreeDebt(d);
                    if (temp != 0 && temp < smallest ) { smallest = temp; }
                }
            }
            return smallest;
        }

        // Precondition: Constructed cohortStat with at least one studentStat
        // Postcondition: N/A
        public int currentPaidOff()
        {
            int total = 0; ;
            for (int i = 0; i < students.Count; i++)
            {
                for (int d = 0; d < students[i].numDegrees; d++)
                {
                    total += students[i].numDeactivated;
                }
            }
            return total;
        }
    }
}