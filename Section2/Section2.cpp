// Section2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;


struct Address {
	int streetNumber;
	string streetName;
	string city;
	string state;
	string postalCode;
};

struct Person {
	int id;
	string firstName;
	string lastName;
	Address address;
	string email;
	string phoneNumber;
};

void printOptions() {
	cout << "1. Create and add student." << endl;
	cout << "2. Search for a student by id." << endl;
	cout << "3. Display the student list." << endl;
	cout << "4. Exit the application." << endl << endl;

	cout << "Enter your choice: ";
}

void printMainMenu() {
	cout << "Welcome to Student Management Application!" << endl;
	cout << "Please choose one of the following options: " << endl << endl;
	printOptions();
}

Person createPerson(Person student) {
	// Info
	cout << "Enter a student ID." << endl;
	cin >> student.id;
	cin.ignore();
	cout << "Enter the students first name." << endl;
	getline(cin, student.firstName);
	cout << "Enter the students last name." << endl;
	getline(cin, student.lastName);
	cout << "Enter the students email." << endl;
	getline(cin, student.email);
	cout << "Enter the students phone number." << endl;
	getline(cin, student.phoneNumber);
	Sleep(1500);
	cout << endl;
	// Address
	cout << "You will now be asked to input the students address." << endl << endl;
	Sleep(500);

	cout << "Enter a street number." << endl;
	cin >> student.address.streetNumber;
	cin.ignore();
	cout << "Enter a street name." << endl;
	getline(cin, student.address.streetName);
	cout << "Enter a city." << endl;
	getline(cin, student.address.city);
	cout << "Enter a state/province." << endl;
	getline(cin, student.address.state);
	cout << "Enter a postal code." << endl << endl;
	getline(cin, student.address.postalCode);

	return student;
}

Person getStudentByID(vector<Person> students, int id) {
	if (students.size() <= 0) {
		throw "No students to search through.";
		return students[0];
	}

	for (int i = 0; i < students.size(); i++) {
		if (students[i].id == id) {
			return students[i];
			break;
		}
		else {
			cout << "Error, could not find student!" << endl;
			return students[0];
			throw "Student not found.";
		}
	}
}

void printStudentList(vector<Person> students) {
	for (int i = 0; i < students.size(); i++) {
		cout << "Basic Student Info: " << endl << endl;
		Sleep(500);
		cout << "Student ID: " << students[i].id << endl;
		cout << "Student First Name: " << students[i].firstName << endl;
		cout << "Student Last Name: " << students[i].lastName << endl;
		cout << "Student Email: " << students[i].email << endl;
		cout << "Student Phone Number: " << students[i].phoneNumber << endl << endl;
		Sleep(350);

		cout << "Student Address Info: " << endl << endl;
		Sleep(500);
		cout << "Street Number: " << students[i].address.streetNumber << endl;
		cout << "Street Name: " << students[i].address.streetName << endl;
		cout << "City: " << students[i].address.city << endl;
		cout << "State/Province: " << students[i].address.state << endl;
		cout << "Postal Code: " << students[i].address.postalCode << endl << endl;

		Sleep(1000);
	}
}

void printStudent(Person student) {
	cout << "Basic Student Info: " << endl << endl;
	Sleep(500);
	cout << "Student ID: " << student.id << endl;
	cout << "Student First Name: " << student.firstName << endl;
	cout << "Student Last Name: " << student.lastName << endl;
	cout << "Student Email: " << student.email << endl;
	cout << "Student Phone Number: " << student.phoneNumber << endl << endl;
	Sleep(350);

	cout << "Student Address Info: " << endl << endl;
	Sleep(500);
	cout << "Street Number: " << student.address.streetNumber << endl;
	cout << "Street Name: " << student.address.streetName << endl;
	cout << "City: " << student.address.city << endl;
	cout << "State/Province: " << student.address.state << endl;
	cout << "Postal Code: " << student.address.postalCode << endl << endl;

	Sleep(1000);
}

int main()
{
	int option = -1, id;
	Person student = Person();
	vector<Person> studentList;

	printMainMenu();

	while (option != 4) {
		cin >> option;
		switch (option) {
		case 1:
			student = createPerson(student);
			studentList.push_back(student);
			cout << "Student added." << endl << endl;
			system("CLS");
			break;
		case 2:
			cout << "Please enter a student id." << endl;
			cin >> id;
			student = getStudentByID(studentList, id);
			cout << "Student with id" << id << " was found. Their first name is: " << student.firstName << endl << endl;
			printStudent(student);
			Sleep(5000);
			system("CLS");
			break;
		case 3:
			cout << "Displaying all student info.";
			system("CLS");
			printStudentList(studentList);
			break;
		case 4:
			cout << "Thanks for using this application." << endl;
			Sleep(1000);
		}
		printOptions();
	}

	system("pause");
	return 0;
}

