#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>
using namespace std;


class Student{
	private:
		int am;
		char* name;
		int semester;
		bool isActive;
	public:
		Student();
		~Student();
		Student(const int&, const char*, const int&, const bool&);
		Student (const Student&);
		Student& operator=(const Student&);
		void display() const;
};

void Student::display()const{
	cout<<am<<", "<<name<<", "<<semester<<", "<<isActive<<" "<<endl;
}


vector<Student> readFromCSVAndSave(const string& source){
	ifstream ifs(source);
	vector<Student> students;
	if (ifs.is_open()){
		string text;
		while(getline(ifs,text)){
			stringstream ss(text);
			string am,name,semester,isActive;
			getline(ss,am,',');
			getline(ss,name,',');
			getline(ss,semester,',');
			getline(ss,isActive,',');

			int intAm = stoi(am);
			int intSemester = stoi(semester);
			bool boolIsActive = isActive=="true" || isActive=="1";
			Student temp(intAm,name.c_str(),intSemester,boolIsActive);
			students.push_back(temp);

		}
	}else{throw logic_error ("Probably something went wrong");}
return students;
}


void displayVector(vector<Student>& vec) {
	for (const auto& v:vec){
		v.display();
	}
}

int main () {
//TEST
Student emptyConstr;
Student argsConstr(1,"alex",1,1);
Student copyConstr(argsConstr);
Student operatorOverload = argsConstr;
///////////////////////////////////////

vector<Student> readAndSave = readFromCSVAndSave("test.csv");

displayVector(readAndSave);

return 0;
}



Student& Student::operator=(const Student& other){
	if (this ==&other) {return *this;}

	delete[] this->name;

	am = other.am;
	semester=other.semester;
	isActive = other.isActive;

	name = new char[strlen(other.name)+1];
	strcpy(name,other.name);

return *this;
}

Student::Student(const Student& other){
	am=other.am;
	semester=other.semester;
	isActive=other.isActive;
	name = new char[strlen(other.name)+1];
	strcpy(name,other.name);
}


Student::Student(){
	am=0;
	semester=0;
	isActive=false;
	name = new char[1];
	name[0] = '\0';
}


Student::Student(const int& a, const char* n, const int& s, const bool& i){
	am =a;
	semester=s;
	isActive=i;
	if (n){
		name = new char[strlen(n)+1];
		strcpy(name,n);
	}
	else{
		name = new char[1];
		name[0] = '\0';
	}

}


Student::~Student(){delete[] name;}
