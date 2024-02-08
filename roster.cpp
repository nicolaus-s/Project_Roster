#include "roster.h"
void Roster::parse(string studentData)
{
	//string sID
	int rhs = studentData.find(","); //Finds first comma
	string sID = studentData.substr(0, rhs); //Extracts substring from 0 to comma

	//string sFName
	int lhs = rhs + 1; //Moves past first comma
	rhs = studentData.find(",", lhs); //Finds next comma
	string sFName = studentData.substr(lhs, rhs - lhs); //Finds First Name

	//string sLName
	lhs = rhs + 1; //Moves past previous comma
	rhs = studentData.find(",", lhs); //Finds next comma
	string sLName = studentData.substr(lhs, rhs - lhs); //Finds Last Name

	//string sEmail
	lhs = rhs + 1; //Moves past previous comma
	rhs = studentData.find(",", lhs); //Finds next comma
	string sEmail = studentData.substr(lhs, rhs - lhs); //Finds Email

	//int sAge
	lhs = rhs + 1; //Moves past previous comma
	rhs = studentData.find(",", lhs); //Finds next comma
	int sAge = stoi(studentData.substr(lhs, rhs - lhs)); //Finds Age - Converts to Integer

	//Find 3 Course Days
	lhs = rhs + 1; //Moves past previous comma
	rhs = studentData.find(",", lhs); //Finds next comma
	int sDay1 = stoi(studentData.substr(lhs, rhs - lhs)); //First Course Day length - Converts to Integer
	lhs = rhs + 1; //Moves past previous comma
	rhs = studentData.find(",", lhs); //Finds next comma
	int sDay2 = stoi(studentData.substr(lhs, rhs - lhs)); //Second Course Day length
	lhs = rhs + 1; //Moves past previous comma
	rhs = studentData.find(",", lhs); //Finds next comma
	int sDay3 = stoi(studentData.substr(lhs, rhs - lhs)); //Third Course Day length
	
	//DegreeProgram sDegree
	lhs = rhs + 1; //Moves past previous comma
	rhs = studentData.find(",", lhs); //Finds next comma
	string degProgram = studentData.substr(lhs, rhs - lhs); //Finds Degree as a String
	DegreeProgram sDegree = UNDECIDED; //Default Value
	//If statements set Enumerator to match string
	if (degProgram == "SECURITY") sDegree = SECURITY;
	if (degProgram == "NETWORK") sDegree = NETWORK;
	if (degProgram == "SOFTWARE") sDegree = SOFTWARE;

	add(sID, sFName, sLName, sEmail, sAge, sDay1, sDay2, sDay3, sDegree);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeprogram);
}

void Roster::printAll()
{
	for (int i = 0; i <= Roster::lastIndex; i++){
		classRosterArray[i]->print();
	}
}

//display students of given degree program type
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	//Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegree() == degreeProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string stuEmail = (classRosterArray[i]->getEmail());
		if (stuEmail.find('@') == string::npos || stuEmail.find('.') == string::npos || stuEmail.find(' ') != string::npos){
			any = true;
			cout << classRosterArray[i]->getId(); cout << '\t';
			cout << stuEmail << std::endl;
		}
	}
	if (!any) cout << "No Results" << std::endl;
	cout << std::endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getId() == studentID) {
			cout << classRosterArray[i]->getId() << '\t';
			cout << classRosterArray[i]->getCourseDays()[0] + classRosterArray[i]->getCourseDays()[1] + classRosterArray[i]->getCourseDays()[2] / 3 << std::endl;
		}
	}
}

 void Roster::remove(string studentID) //Student to be removed is identified by Student ID
{
	bool status = false; //Default value
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getId() == studentID) {
			status = true; //Student has been found
			if (i < numStudents - 1)
			{ 
				// The following 3 lines swap the current and last student.
				Student* temp = classRosterArray[i]; //Store current student in temp
				classRosterArray[i] = classRosterArray[numStudents - 1]; //Place LAST student into current student's position
				classRosterArray[numStudents - 1] = temp; // Place current student into LAST position
			}

			Roster::lastIndex--; //Decrement the pointer array. The last student (i.e. our current student) is no longer visible.
			//Student still exists, but is currently hidden.
		}
	}

	if (status)
	{
		cout << studentID << " has been removed from the roster and the roster has been updated." << std::endl;
		cout << endl;
		this->printAll(); //Display all students. Deleted student should not show.
	}

	else cout << "Student with ID " << studentID << " not found in roster." << std::endl;
}


	Roster::~Roster()
	{
		cout << "Destructor has been called!" << std::endl;
		for (int i = 0; i < numStudents; i++)
		{
			cout << "Destroying student #" << i + 1 << std::endl;
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}