#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;

class Student 
{
public: //public items are visible everwhere
	const static int daysArraySize = 3;

private: //private items are not visible outside of the class
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numDays[daysArraySize];
	DegreeProgram degree;

public: //public items are visible everwhere
	Student(); //Empty constructor
	//Full constructor
	Student(string ID, string fName, string lName, string email, int age, int numDays[], DegreeProgram degree);
	~Student(); //Destructor

	//Accessors - getter functions
	string getId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getCourseDays();
	DegreeProgram getDegree();

	//Mutators - setter functions
	void setId(string ID);
	void setFirstName(string fName);
	void setLastName(string lName);
	void setEmail(string email);
	void setAge(int age);
	void setCourseDays(int numDays[]);
	void setDegree(DegreeProgram dpro);
	
	void print(); //print() will display student data
};