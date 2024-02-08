#include "student.h"

Student::Student() //Empty constructor defined
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++) this->numDays[i] = 0;
	this->degree = DegreeProgram::UNDECIDED; //Default degree value
}

//Full constructor defined
Student::Student(string ID, string fName, string lName, string email, int age, int Days[], DegreeProgram degree)
{
	this->studentID = ID;
	this->firstName = fName;
	this->lastName = lName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->numDays[i] = Days[i];
	this->degree = degree;
}

Student::~Student() {}

//getters

string Student::getId()
{
	return this->studentID;
}

string Student::getFirstName()
{
	return this->firstName;
}

string Student::getLastName()
{
	return this->lastName;
}

string Student::getEmail()
{
	return this->email;
}

int Student::getAge()
{
	return this->age;
}

int* Student::getCourseDays()
{
	return this->numDays;
}

DegreeProgram Student::getDegree()
{
	return this->degree;
}

//setters

void Student::setId(string ID)
{
	this->studentID = ID;
}

void Student::setFirstName(string fName)
{
	this->firstName = fName;
}

void Student::setLastName(string lName)
{
	this->lastName = lName;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setCourseDays(int numDays[])
{
	for (int i = 0; i < daysArraySize; i++) this->numDays[i] = numDays[i];
}

void Student::setDegree(DegreeProgram degree)
{
	this->degree = degree;
}

//Print method to display all fields
void Student::print()
{
	//Format: A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program : Security
	cout << this->getId() << '\t';
	cout << "First Name : " << this->getFirstName() << '\t';
	cout << "Last Name : " << this->getLastName() << '\t';
	cout << "Age : " << this->getAge() << '\t';
	cout << "dayInCourse : " << "{" << this->getCourseDays()[0] << ", ";
	cout << this->getCourseDays()[1] << ", ";
	cout << this->getCourseDays()[2] << "}" << '\t';
	cout << "Degree Program : " << degreeTypeStrings[this->getDegree()] << endl;
}