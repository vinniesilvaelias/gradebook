#include"gradebook.h"
int main(){
   int gradeArray[ Gradebook::students ][ Gradebook::tests ];
   for ( int student = 0; student < Gradebook::students; student++  )
   {
       cout << "Student " << student + 1 << "\n\n";
       for ( int test = 0; test < Gradebook::tests; test++ )
       {
           cout << "Test " << test + 1 << " : ";
           cin >> gradeArray[ student ][ test ];
       }
       cout << endl;
   }
   Gradebook myGradeBook(
               "CS101 Introduction to C++ Programming", gradeArray );
   myGradeBook.displayMessage();
   myGradeBook.processGrades();
   return 0;
}
