select * from Students;

select * from Courses;

select * from Registration;

#3 (1 point) List the names (first name, last name) of all the students. Sort first by last name and
#then by first name alphabetically.

SELECT firstName, lastName 
FROM Students 
ORDER BY firstName;

SELECT firstName, lastName 
FROM Students 
ORDER BY lastName;

#4 (1 point) What are the student ID and the names of the female students who were born after
#1993?

SELECT studentID, firstName, lastName
FROM Students
WHERE (dateofBirth < '1993-12-31') AND (gender = 'F');

#5. (1 point) How many students are registered in the course “CS056”?

SELECT COUNT(*)
FROM Registration
WHERE courseCode = 'CS056';

#6. (1 point) What courses (courseCode and courseName) are offered by the department of
#Computer Science (i.e. course codes CS***)?

SELECT courseCode, courseName
FROM Courses
WHERE courseCode LIKE 'CS%';

#7. (1 point) Which course(s) (couseCode and courseName) give less than 5 credits?

SELECT courseCode, courseName
FROM Courses
WHERE (credits < 5);

#8. (1 point) How many courses are there on each level?

SELECT courseLevel, COUNT(courseCode)
FROM Courses 
GROUP BY courseLevel;

#9. (1 point) Which courses (course codes only) have been taken by the student with student ID
#861103-2438?

SELECT courseCode
From Registration
WHERE studentID = '861103-2438';

#10. (1 point) Which students (studentID only) have the highest grade for the course ‘CS052’?

SELECT studentID, grade 
FROM Registration
WHERE courseCode = 'CS052' AND grade = (SELECT MAX(grade) FROM Registration WHERE courseCode = 'CS052');

#11. (1 point) Find the courses (course codes only) that have been taken by both the student
#861103-2438 and the student 123456-0980.

SELECT courseCode
FROM Registration
WHERE studentID = '861103-2438' OR studentID = '123456-0980';

#12. (1 point) Find the students who have not registered any course yet.

SELECT studentID 
FROM Students
WHERE studentID NOT IN (SELECT studentID FROM Registration);

#13. (1 point) Find the student (studentID only), the sum of grade, and the average of grade, for
#each student who has registered courses and the average of grade is above 3.

SELECT studentID, SUM(grade), AVG(grade)
FROM Registration
GROUP BY studentID
HAVING AVG(grade) > 3;

#14. (1 point) Find the student who has registered the most number of courses. If there are
#multiple students who has registered the most number of courses, just take one student (To
#take only one record - the 1st record in the returned result, use ‘limit 1’ at the end of your
#SQL code).

SELECT studentID, COUNT(courseCode) AS Count 
FROM Registration 
GROUP BY studentID
ORDER BY Count DESC
LIMIT 1;

#15. (1 point) Find the students (studentID only) who have taken either “PHY210” or “BIO001”.

SELECT studentID
FROM Registration
WHERE courseCode = 'PHY210' OR courseCode = 'BIO001';

#16. (1 point) Find the youngest student’s name.

SELECT firstName, lastName, MAX(dateofBirth)
FROM Students;

#17. (1 point) Change the credit for all Computer Science courses (i.e. course codes CS***) with
#five credits from 5 to 6.

UPDATE Courses SET credits = 6 WHERE courseCode LIKE 'CS%' AND credits = 5;

#18. (1 point) Delete the registration record for the student 908409-0010.

DELETE FROM Registration WHERE studentID = '908409-0010';

#19. (1 point) Change the grade of “PHY210” for student 861103-2438 from 3.5 to 3.8.

UPDATE Registration
SET grade = 3.8
WHERE studentID = '861103-2438' AND courseCode = 'PHY210'; 
 
