#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
#include<iomanip>
using std::setprecision;
using std::setw;
#include"gradebook.h"
void Gradebook::setStudents( int student )
{
    students = student;
}
void Gradebook::setTests( int test )
{
    tests = test;
}
int Gradebook::getStudents()
{
    return students;
}
int Gradebook::getTests()
{
    return  tests;
}
Gradebook::Gradebook( string name, int student, int test)
{
    setStudents(student);
    setTests(test);
    setCourseName( name );
    for ( int student = 0; student < students; student++ )
    {
        cout << "Student " << student + 1 << "\n\n";
        for ( int test = 0; test < tests; test++ )
        {
            cout << "Test " << test + 1 << " : ";
            cin >> grades[ student ][ test ];
        }
    }
}
void Gradebook::setCourseName( string name )
{
   courseName = name;
}
string Gradebook::getCourseName()
{
    return courseName;
}
void Gradebook::displayMessage()
{
    cout << "Welcome to the grade book for\n"
         << getCourseName() << "!" << endl;
}
void Gradebook::processGrades()
{
    outputGrades();
    cout << "\nLowest grade in the grade book is "
         << getMaximum()
         << "\nHighest grade in the grade book is "
         << getMinimum() << endl;
    outputBarChart();
}
int Gradebook::getMinimum()
{
    int lowGrade = 100;
    for ( int student = 0; student < students; student++ )
    {
        for ( int test = 0; test < tests; test++ )
        {
            if ( grades[ student ][ test ] < lowGrade )
                lowGrade = grades[ student ][ test ];
        }
    }
    return lowGrade;
}
int Gradebook::getMaximum()
{
    int hightGrade = 0;
    for ( int student = 0; student < students; student++ )
    {
        for ( int test = 0; test < tests; test++ )
        {
            if ( grades[ student ][ test ] > hightGrade )
                hightGrade = grades[ student ][ test ];
        }
    }
    return hightGrade;
}
double Gradebook::getAverage( const int setOfGrades[], const int grades )
{
    int total = 0;
    for ( int grade = 0; grade < grades; grade++ )
        total += setOfGrades[ grade ];
    return static_cast<double>( total ) / grades;
}
void Gradebook::outputBarChart()
{
  cout << "\nOverall grade distribution:" << endl;
  const int frequencySize = 11;
  int frequency[ frequencySize ] = { 0 };
  for ( int student = 0; student < students; student++ )
      for ( int test = 0; test < tests; test++ )
        ++frequency[ grades[ student ][ test ] / 10 ];
  for( int count = 0; count < frequencySize; count++ )
  {
      if ( count == 0 )
          cout << "  0-9: ";
      else if( count == 10 )
          cout << "  100: ";
      else
          cout << count * 10 << "-"
               << ( count * 10 ) + 9<< ": ";
      for ( int stars = 0; stars < frequency[ count ]; stars++ )
          cout << '*';
      cout << endl;
  }
}

void Gradebook::outputGrades()
{
    cout << "\nThe grades are:\n\n";
    cout << "Average:\n\n";
    cout << "Student";
         for ( int test = 0; test < Gradebook::tests; test++)
               cout << setw( 7 ) << "Test " << test + 1;
         cout << setw( 10 ) << "Average" << endl;
    for ( int student = 0; student < students; student++ )
    {
        cout << setw( 4 ) << student + 1;
         for ( int test = 0; test < tests; test++ )
             cout << setw( 8 ) << grades[ student ][ test ];
         double average = getAverage( grades[ student ], tests );
         cout << setw( 12 ) << setprecision( 2 )
              << fixed << average << endl;
    }
}
