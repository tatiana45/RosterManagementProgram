#include "student.h"
#include "roster.h"
#include <array>
#include <string>
#include "degree.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

roster::roster() {
    this->numberOfSudents = 0;
    this->addIndex = -1;
    this->classRosterArray = nullptr;
}

roster::roster(int numberOfSudents) {
    this->numberOfSudents = numberOfSudents;
    this->addIndex = -1;
    this->classRosterArray = new student * [numberOfSudents];
}
//adding students to the classRosterArray
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    addIndex++;
    int numberOfDays[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[addIndex] = new student(studentID, firstName, lastName, emailAddress, age, numberOfDays, degreeProgram);
}

//removing students from the classRosterArray by studentID
void roster::remove(string studentID) {
    int tempAddIndex = addIndex;
    for (int i = 0; i <= addIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[addIndex]; 
            addIndex--;
        }
    }
    //studentID not found if addIndex remains the same
    if (addIndex == tempAddIndex) {
        cout << "Student not found for id: " << studentID << endl;
    }
}
//printing all student data
void roster::printAll() {
    for (int i = 0; i <= addIndex; i++) {
        (this->classRosterArray)[i]->print();
    }
}


//printing average day for course completion based on studentID
void roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= addIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* studentDays = classRosterArray[i]->getNumberOfDays();
            int averageDays = (studentDays[0] + studentDays[1] + studentDays[2]) / 3;
            cout << "The average days in course for studentID of " << studentID << " is " << averageDays << endl;
        }
    }
}
//printing invalid emails 
void roster::printInvalidEmails() {
    for (int i = 0; i <= addIndex; i++) {
        string studentEmail = classRosterArray[i]->getEmailAddress();
        if ((studentEmail.find("@") == string::npos) || (studentEmail.find(".") == string::npos) || (studentEmail.find(" ") != string::npos)) {
            cout << "The email address " << studentEmail << " for student id:" << classRosterArray[i]->getStudentID() << " is invalid." << endl;
        }
    }
}

//printing student data based on degree program
void roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    string degree;
    switch (degreeProgram)
    {
    case DegreeProgram::SECURITY:
        degree = "SECURITY";
        break;
    case DegreeProgram::NETWORKING:
        degree = "NETWORK";
        break;
    default:
        degree = "SOFTWARE";
    }

    for (int i = 0; i <= addIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degree) {
            this->classRosterArray[i]->print();
        }
    }

}
//deconstructor
roster::~roster()
{
    for (int i = 0; i <= addIndex; i++)
    {
        delete this->classRosterArray[i];
    }
    delete classRosterArray;
}