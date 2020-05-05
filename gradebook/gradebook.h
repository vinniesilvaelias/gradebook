#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include<string>
#include<iostream>
#include<conio.h>
using namespace std;
class Gradebook
{
public:
    const static int students = 10;
    const static int tests = 3;
    Gradebook( string, const int [][ tests ] );
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
    int grades[ students ][  tests ];
    string courseName;
};
#endif // GRADEBOOK_H
