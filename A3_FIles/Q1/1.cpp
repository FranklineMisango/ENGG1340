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

class Table {
public:
    void InsertStudent(Student x, int y) {
        studentData[x.id] = make_pair(x.name, y);
    }

    void SearchbyID(int x) {
        if (studentData.find(x) != studentData.end()) {
            auto record = studentData[x];
            cout << record.first <<endl;
            cout <<record.second << endl;
        }
        else {
            cout << "Record not found" << endl;
        }
    }

    void SearchbyGrade(int y) {
        bool found = false;
        for (auto& record : studentData) {
            if (record.second.second == y) {
                cout << record.first << " " << record.second.first << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Record not found" << endl;
        }
    }
    void Statistics() {
    vector<int> grades;
    for (auto& record : studentData) {
        grades.push_back(record.second.second);
    }
    sort(grades.begin(), grades.end());
    int n = grades.size();
    int max_grade = grades[n-1];
    int min_grade = grades[0];
    float median;
    if (n % 2 == 0) {
        median = (grades[n/2 - 1] + grades[n/2]) / 2.0;
    } else {
        median = grades[n/2];
    }
    cout << "Maximum " << max_grade << endl;
    cout << "Median " << median << endl;
    cout << "Minimum " << min_grade << endl;
}
    void PrintAll() {
        for (auto& record : studentData) {
            cout << record.first << " " << record.second.first << " " << record.second.second << endl;
        }
    }

private:
    map<int, pair<string, int>> studentData;
};

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