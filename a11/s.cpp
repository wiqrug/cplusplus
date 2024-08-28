#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

//dont forget about the rule of 3

class Gradebook {

	private:
		map<string,double> student_grades;
	public:
		void addStudent(const string&);
		void addGrade(const string&, const double&); //Search for the student using map functions and put grade to him if he exists
		void exportToCSV();				//use fstream

};



int main() {

Gradebook s;
	s.addStudent("Mikakos");
	s.addStudent("Alexilaos");
	s.addGrade("Mikakos",4);
	s.addGrade("pipilas",1);
	s.exportToCSV();


return 0;
}






void Gradebook::addStudent(const string& student_name){
	student_grades[student_name] = 0;
}


void Gradebook::addGrade(const string& student_name, const double& student_grade) {
    auto it = student_grades.find(student_name);
    if (it != student_grades.end()) {
        student_grades[student_name] = student_grade;  // Update the grade
    } else {
        cout << "Student not found: " << student_name << endl;  // Print an error message
    }
}


void Gradebook::exportToCSV(){
	ofstream file("pilates.txt");
	if (file.is_open()){
	for (const auto& entry: student_grades){file<<entry.first<<","<<entry.second<<endl;}
	file.close();
	}
	else{cerr<<"Failed to open file"<<endl;}
}



