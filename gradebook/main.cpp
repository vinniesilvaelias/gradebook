#include"gradebook.h"
int main(){
    string nameOfCourse;
   int student, test;
   cout << "Insert a course name: ";
   getline(cin,nameOfCourse);
   cout << "Insert the number of students: ";
   cin >> student;
   cout << "Insert the numer of tests: ";
   cin >> test;
   Gradebook myGradeBook(nameOfCourse, student, test);
   myGradeBook.displayMessage();
   myGradeBook.processGrades();
   return 0;
}
