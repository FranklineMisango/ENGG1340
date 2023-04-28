#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<sstream>
#include<iomanip>

using namespace std;

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

bool operator<(const Student&a, const Student&b) {
	return a.id < b.id;
}

class Table {
public:
	void InsertStudent(Student x, int y);
	void SearchbyID(int x);
	void SearchbyGrade(int y);
	void Statistics();
	void PrintAll();
private:
	map<Student, int> records;
};

void Table::InsertStudent(Student x, int y) {
	records[x] = y;
}

void Table::SearchbyID(int x) {
	map<Student, int>::iterator it;
	for (it = records.begin(); it != records.end(); it++) {
		if (it->first.id == x) {
			cout << it->first.name << endl;
			cout << it->second << endl;
			return;
		}
	}
	cout << "No such student." << endl;
}

void Table::SearchbyGrade(int y) {
	map<Student, int>::iterator it;
	bool found = false;
	for (it = records.begin(); it != records.end(); it++) {
		if (it->second == y) {
			cout << it->first.id << " " << it->first.name << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "No such record." << endl;
	}
}

void Table::Statistics() {
	map<Student, int>::iterator it;
	vector<int> grades;
	for (it = records.begin(); it != records.end(); it++) {
		grades.push_back(it->second);
	}
	sort(grades.begin(), grades.end());
	cout << "Maximum " << grades.back() << endl;
	if (grades.size() % 2 == 0) {
		cout << "Median " << (grades[grades.size() / 2 - 1] + grades[grades.size() / 2]) / 2.0 << endl;
	}
	else {
		cout << "Median " << grades[grades.size() / 2] << endl;
	}
	cout << "Minimum " << grades.front() << endl;
}

void Table::PrintAll() {
	map<Student, int>::iterator it;
	for (it = records.begin(); it != records.end(); it++) {
		cout << it->first.id << " " << it->first.name << " " << it->second << endl;
	}
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
