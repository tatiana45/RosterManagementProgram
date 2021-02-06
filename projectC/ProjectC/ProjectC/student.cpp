#include <iostream>
#include "student.h"
#include "degree.h"
#include <string>
using namespace std;


student::student()
{
    studentID = "";
    firstName = "";
    lastName = "";
    emailAddress = "";
    age = 1;
    numberOfDays[0] = 1;
    numberOfDays[1] = 2;
    numberOfDays[2] = 3;
    degreeProgram = DegreeProgram::SOFTWARE;
}

student::student(string student_Id, string first_name, string last_name, string email, int student_age, int* days, DegreeProgram degree) {
    studentID = student_Id;
    firstName = first_name;
    lastName = last_name;
    emailAddress = email;
    age = student_age;
    numberOfDays[0] = days[0];
    numberOfDays[1] = days[1];
    numberOfDays[2] = days[2];
    degreeProgram = degree;
}

//getters
string student::getStudentID() {
    return studentID;
}
string student::getFirstName() {
    return firstName;
}
string student::getLastName() {
    return lastName;
}
string student::getEmailAddress() {
    return emailAddress;
}
int student::getAge() {
    return age;
}
int* student::getNumberOfDays() {
    return numberOfDays;
}
string student::getDegreeProgram() {
    string result;
    switch (degreeProgram)
    {
    case DegreeProgram::SECURITY:
        result = "SECURITY";
        break;
    case DegreeProgram::NETWORKING:
        result = "NETWORK";
        break;
    default:
        result = "SOFTWARE";
    }
    return result;
}

//setters
void student::setStudentID(string student_Id) {
    studentID = student_Id;
}
void student::setFirstName(string first_name) {
    firstName = first_name;
}
void student::setLastName(string last_name) {
    lastName = last_name;
}
void student::setEmailAddress(string email) {
    emailAddress = email;
}
void student::setAge(int student_age) {
    age = student_age;
}
void student::setNumberOfDays(int day_0, int day_1, int day_2) {
    student::numberOfDays[0] = day_0;
    student::numberOfDays[1] = day_1;
    student::numberOfDays[2] = day_2;
}
void student::setDegreeProgram(DegreeProgram degree) {
    degreeProgram = degree;
}

void student::print() {
    cout << getStudentID();
    cout << "\tFirst Name: " << getFirstName();
    cout << "\tLast Name: " << getLastName();
    cout << "\tAge: " << getAge();
    cout << "\tdaysInCourse: {" << getNumberOfDays()[0] << ", " << getNumberOfDays()[1] << ", " << getNumberOfDays()[2] << "}";
    cout << "\tDegree Program: " << getDegreeProgram() << "." << endl;
}

student::~student()
{

}

