// Handling user commands

#include <iostream>
#include <string>
using namespace std;

struct Course {
string code;
string name;
string lecturer;
};

// Function to add a new course
void addCourse(Course courses[], int& numCourses) {
    Course newCourse;
    cin >> newCourse.code >> newCourse.name >> newCourse.lecturer;
    courses[numCourses] = newCourse;
    numCourses++;
}

// Function to show a course's information by code
void showCourse(Course courses[], int numCourses, string code) {
    for (int i = 0; i < numCourses; i++) {
        if (courses[i].code == code) {
            cout << "Name: " << courses[i].name << ", Lecturer: " << courses[i].lecturer << endl;
        return;
    }
}
    cout << "Course not found." << endl;
}

int main() {
    const int MAX_COURSES = 100;
    Course courses[MAX_COURSES];
    int numCourses = 0;
    string input;
    cin >> input;
    while (input != "exit") {
        if (input == "add") {
            addCourse(courses, numCourses);
        }
        if (input == "show") {
            string code;
            cin >> code;
            showCourse(courses, numCourses, code);
    }
    cin >> input;
}
return 0;
}
