#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include<string>
#include<iostream>
#include<conio.h>
using namespace std;
class Gradebook
{
public:
    const static int maxStudents = 100;
    const static int maxTests = 10;
    Gradebook( string, int , int  );
    void setStudents( int students );
    void setTests( int tests );
    int getStudents();
    int getTests();
    void setCourseName( string name );
    string getCourseName();
    void displayMessage();
    void processGrades();
    int getMinimum();
    int getMaximum();
    double getAverage(const int [], const int);
    void outputBarChart();
    void outputGrades();
private:
    int students;
    int tests;
    int grades[ maxStudents ][ maxTests ];
    string courseName;
};
#endif // GRADEBOOK_H
