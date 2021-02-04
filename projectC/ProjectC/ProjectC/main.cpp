#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"

using namespace std;

//parsing data by delimeter 
vector<string> split(const string& s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {

    cout << "Scripting and Programming - Applications - C867\nC++\nStudentID:000870741\nTatiana Piteli\n";
    int numberOfStudents = 5;
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Tatiana,Piteli,tpitel1@wgu.edu,27,25,35,24,SOFTWARE"
    };


    roster* classRoster = new roster(numberOfStudents);
    char delimiter = ',';
    //adding each student to the roster class
    for (int i = 0; i < numberOfStudents; i++) {
        string row = studentData[i];
        //parsing student data
        vector<string> splitRow = split(row, delimiter);
        DegreeProgram degree;
        if (splitRow[8] == "SECURITY") {
            degree = DegreeProgram::SECURITY;
        }
        else if (splitRow[8] == "NETWORK") {
            degree = DegreeProgram::NETWORKING;
        }
        else if (splitRow[8] == "SOFTWARE") {
            degree = DegreeProgram::SOFTWARE;
        }
        classRoster->add(splitRow[0], splitRow[1], splitRow[2], splitRow[3], std::stoi(splitRow[4]), std::stoi(splitRow[5]), std::stoi(splitRow[6]), std::stoi(splitRow[7]), degree);
    };
    cout << "\nPrint students details:" << endl;
    classRoster->printAll();

    cout << "\nPrint student with invalid emails:" << endl;
    classRoster->printInvalidEmails();

    cout << "\nPrint each student average days in course:" << endl;
    for (int i = 0; i < classRoster->numberOfSudents; i++) {
        string studentId = (classRoster->classRosterArray)[i]->getStudentID();
        classRoster->printAverageDaysInCourse(studentId);
    }

    cout << "\nPrint student with degree program of Software:" << endl;
    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    
    classRoster->remove("A3");

    cout << "\nPrint students details after A3 is removed:" << endl;
    classRoster->printAll();
    classRoster->remove("A3");
    return 0;
}

