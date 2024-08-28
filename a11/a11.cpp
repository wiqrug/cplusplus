#include <iostream>
#include <map>
#include <string>
#include <fstream>


using namespace std;

class Gradebook {
private:
    map<string, double> student_grades;

public:
    void addStudent(const string& student_name) {
        student_grades[student_name] = 0.0;
    }

    void assignGrade(const string& student_name, double grade) {
        if (student_grades.find(student_name) != student_grades.end()) {
            student_grades[student_name] = grade;
        } else {
            cerr << "Student not found!" << endl;
        }
    }

    void exportGradesToCSV(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            file << "Student Name,Grade\n";
            for (const auto& entry : student_grades) {
                file << entry.first << "," << entry.second << "\n";
            }
            file.close();
            cout << "Grades exported successfully to " << filename << endl;
        } else {
            cerr << "Failed to open file: " << filename << endl;
        }
    }
};

int main() {
    Gradebook course_grades;

    course_grades.addStudent("John Doe");
    course_grades.addStudent("Jane Smith");
    course_grades.addStudent("Alice Brown");
    course_grades.assignGrade("John Doe", 85.5);
    course_grades.assignGrade("Jane Smith", 92.0);
    course_grades.assignGrade("Alice Brown", 78.5);

    course_grades.exportGradesToCSV("grades.csv");

    return 0;
}
