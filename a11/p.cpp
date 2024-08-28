#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;


class Gradebook{
	private:
		map<string,double> student_grades;
	public:
		void addStudent(const string&);
		void addGrade (const string&, const double&);
		void exportToCSV();
};




void Gradebook::addStudent(const string& student_name){
	student_grades[student_name]=0;
}



void Gradebook::addGrade(const string& student_name, const double& student_grade){
	auto it = student_grades.find(student_name);

	if (it != student_grades.end()){
		student_grades[student_name]=student_grade;
	}
	else{
		cout<<"There is no student named "<<student_name<< endl;
	}
}



void Gradebook::exportToCSV() {
	ofstream file("pipila.txt");
	if (file.is_open()){
		for (const auto& entry:student_grades){file<<entry.first<<","<<entry.second<<endl;}
	}

}


int main () {
	Gradebook s;
	s.addStudent("nikitas");
	s.addGrade("nikitas",2);
	s.addGrade("ikitas",2);
	s.exportToCSV();


return 0;
}


