#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;


//I want to handle the memory because of char
//Rule of 3 says that i need also copy constructor and operator overload

class Student{

	private:
		int am;
		char* name;
		int sem;
		bool isActive;
	public:
		bool getActive() const;

		const char* getName() const;
		int getAM() const;

		Student(int, const char*, int, bool);

		Student( const Student& stud);

		Student& operator=(const Student& stud);

		~Student();

};


Student::~Student(){
	delete[] name;
}

Student& Student::operator=(const Student& stud){
	if (this == &stud){
		return *this;
	}

	delete[] name;
	am = stud.am;
	sem= stud.sem;
	isActive = stud.isActive;
	if (stud.name){
		name = new char[strlen(stud.name)+1];
		strcpy (name,stud.name);
	}
	else{name=nullptr;}


return *this;
}


Student::Student(const Student& stud){
	am=stud.am;
	sem=stud.sem;
	isActive=stud.isActive;

	if (stud.name){
		name = new char[strlen(stud.name)+1];
		strcpy(name,stud.name);
	}
	else{name=nullptr;}

}




Student::Student(int a,const char* n, int s, bool i){
	am=a;
	sem=s;
	isActive=i;

	if(n){
		name = new char[strlen(n)+1];
		strcpy(name,n);
	}
	else{
		name=nullptr;
	}
}







bool Student::getActive()const {
		return isActive;
}


const char* Student::getName()const{
		return name;
}


int Student::getAM() const{
		return am;
}


vector<Student> readFromCSV(string filename){
	vector<Student> students;
	ifstream file (filename);
	if (!file.is_open()){
		cerr<<"Error opening file."<<endl;
		return students;
	}

	string line;
	while (getline(file,line)){
		stringstream ss(line);
		string word;

		getline(ss,word,',');
		int am = stoi(word);

		getline(ss,word,',');
		string name_str = word;

		getline(ss,word,',');
		int sem = stoi(word);

		getline(ss,word,',');
		bool isActive =( word=="1" || word=="true");

		students.emplace_back(am, name_str.c_str(), sem, isActive);
	}

	file.close();
	return students;

}




void displayActiveStudents() {
    vector<Student> students = readFromCSV("test.csv");

    for (int i = 0; i < students.size(); i++) {
        if (students.at(i).getActive()) {
            cout << "AM: " << students.at(i).getAM() << ", Name: " << students.at(i).getName() << endl;
        }
    }
}




int main() {
    displayActiveStudents();
    return 0;
}
