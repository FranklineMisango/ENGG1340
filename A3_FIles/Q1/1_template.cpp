#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<sstream>
#include<iomanip>

// You can add more libraries here (if needed)
using namespace std;
// Define the classes and member functions here

struct Student {
	int id;
	string name;
	Student() {
		id = 0;
		name = "invalid";
	};
	Student(int inputid, string inputname) {
		id = inputid;
		name = inputname;
	};
};

class Table {
public:
	void InsertStudent(Student x, int y);
	void SearchbyID(int x);
	void SearchbyGrade(int y);
	void Statistics();
	void PrintAll();
	// You can add more member functions to help your implementation.
private:
	/* The data type is decided by you records; */ 
};

bool operator<(const Student&a, const Student&b) {
	// This function may be useful for your implementation.
}

//insert one record in to the stored records
void Table::InsertStudent(Student x, int y) {
	// To be implemented
}

//return the name and grade of the student with id x
void Table::SearchbyID(int x) {
	// To be implemented
}

//return the id and name of the student with grade y
void Table::SearchbyGrade(int y) {
	// To be implemented
}

//Print the maximum, minimum, and median of grades
void Table::Statistics() {
	// To be implemented
}

//Print all records in the ascending order of id
void Table::PrintAll() {
	// To be implemented
}


int main() {
	Table t;
	string command;
	int id;
	string name;
	int grade;
	
	while (cin >> command) {
		if (command == "InsertStudent") {
			cin >> id >> name >> grade;
			Student s = {id, name};
			t.InsertStudent(s, grade);
		}
		else if (command == "SearchbyID") {
			cin >> id;
			t.SearchbyID(id);
		}
		else if (command == "SearchbyGrade") {
			cin >> grade;
			t.SearchbyGrade(grade);
		}
		else if (command == "PrintAll") {
			t.PrintAll();
		}
		else if (command == "Statistics") {
			t.Statistics();
		}
		else if (command == "exit") {
			break;
		}
	}

	return 0;
}
