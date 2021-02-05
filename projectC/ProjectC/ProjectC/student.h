#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class student
{

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numberOfDays[3];
    DegreeProgram degreeProgram;

public:
    student();
    student(string studentID, string firstName, string lastName, string emailAddress, int age, int* numberOfDays, DegreeProgram degreeProgram);

    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getNumberOfDays();
    string getDegreeProgram();

    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setNumberOfDays(int day_0, int day_1, int day_2);
    void setDegreeProgram(DegreeProgram degreeProgram);

    void print();
    ~student();


};

#endif