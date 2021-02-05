#ifndef ROOSTER_H
#define ROOSTER_H

#include "student.h"
#include "degree.h"
#include <array>
#include <string>
using namespace std;

class roster
{
public:
    student** classRosterArray;
    int numberOfSudents;
    int addIndex;
    roster();
    roster(int numberOfSudents);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~roster();


};


#endif