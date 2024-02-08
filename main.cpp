#include "roster.h"

int main()
{
	//Print to screen: Course title  |  Programming language used  |   WGU student ID  |  Name
	cout << "Scripting and Programming - Applications - C867  |  C++  |  001097144  |  Nicolaus Shaffer" << endl;
	cout << endl; 

	string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Nick,Shaffer,nshaff6@wgu.edu,29,20,25,30,SOFTWARE"
	};

	const static int numStudents = 5;

	Roster classRoster; //Default constructor to create roster

	for (int i = 0; i < numStudents; i++) {
		classRoster.parse(studentData[i]);
	}

	cout << "Displaying all students: " << endl;
	cout << endl;

	classRoster.printAll();
	cout << endl;

	cout << "Displaying all students' average course days:" << endl;
	cout << endl;
	//loop through classRosterArray and for each element:
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getId());
	}
	cout << endl;
	//classRoster.printAverageDaysInCourse(/*current_object's student id*/);

	cout << "Displaying invalid email addresses: " << endl;
	cout << endl;
	classRoster.printInvalidEmails();

	cout << "Print all students in SOFTWARE degree program: " << endl;
	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);

	cout << "Removing student with ID A3: " << endl;
	cout << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << "Removing student with ID A3: " << endl;
	cout << endl;
	classRoster.remove("A3");
	cout << endl;

	system("pause");
	return 0;
}