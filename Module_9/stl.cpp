#include <iostream>
#include <list>
#include <string>

using namespace std;

// Struct to hold student data
struct StudentRecord {
    string name;
    string major;
    int studentNumber;
};

// Function to add a new student record to the list
void addRecord(list<StudentRecord>& records) {
    string name, major;
    int studentNumber;
    cin >> name;
    cin >> major;
    cin >> studentNumber;
    StudentRecord record = {name, major, studentNumber};
    records.push_back(record);
    cout << "Added Successfully" << endl;
}

// Function to search for a student record by name and major
void searchRecord(list<StudentRecord>& records) {
    string name, major;
    cin >> name;
    cin >> major;
    bool found = false;
    for (auto& record : records) {
        if (record.name == name && record.major == major) {
            cout << "Student Number : " <<record.studentNumber << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No Record found" << endl;
    }
}

int main() {
    list<StudentRecord> records;
    string command;
    while (true) {
        cin >> command;
        if (command == "Add") {
            addRecord(records);
        } else if (command == "Search") {
            searchRecord(records);
        } else if (command == "Quit") {
            cout << "Bye" << endl;
            break;
        } else {
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}
