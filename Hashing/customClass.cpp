/*
(4)
Hash function for Custom Class. (key is a custom object)

Create a hashmap whose key is of type Student and value int.
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Student {

public:
	string firstName;
	string lastName;
	string rollno;

	Student(string f, string l , string no) {
		firstName = f;
		lastName = l;
		rollno = no;
	}

	//operator overloading
	bool operator==(const Student &s) const {
		return rollno == s.rollno;  //since roll no of every student is unique therefore we will compare through roll no
	}
};

class HashFn {

public:

	size_t operator()(const Student &s) const {
		return s.firstName.length() + s.lastName.length();
	}
};

int main() {

	unordered_map <Student, int, HashFn> student_map;

	Student s1("Prateek" , "Narang" , "010");
	Student s2("Rahul" , "Kumar" , "023");
	Student s3("Prateek", "Gupta", "030");
	Student s4("Rahul", "Kumar", "120");

	//Add students - marks to hashmap
	student_map[s1] = 100;
	student_map[s2] = 120;
	student_map[s3] = 11;
	student_map[s4] = 45;

	cout << student_map[s3] << endl;

	//iterate over all students
	for (auto s : student_map)     //s will be a pair
		cout << "Name: " << s.first.firstName << " Roll No. " << s.first.rollno << " Marks -> " << s.second << endl;
}