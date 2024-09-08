#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
	protected:
		string name;
		int age;
	public:
		Person();
		Person(const string&,int);
		virtual ~Person();
		virtual bool isStudent() const =0;
		virtual bool isTeacher() const=0;

};


class Teacher: public Person{
	private:
		bool hasPHD;
	public:
		Teacher();
		//No need for destructor
		Teacher(const string&,int,bool);
		bool isStudent() const override;
		bool isTeacher() const override;

};


class Student: public Person{
	private:
		bool hasStudentId;
	public:
		Student();
		//No need for destructor
		Student(const string&,int,bool);
		bool isStudent() const override;
		bool isTeacher() const override;

};





int main () {


Person* p;

vector<Person *> people;
people.push_back(new Student("alek",22,1));
people.push_back(new Teacher("Ee",22,1));

for (const auto& p:people){
	if (p->isStudent()){cout<<"its student"<<endl;}
}


for (auto& p:people){
	delete p;
}

}









Person::Person(){}
Person::~Person()=default;
Person::Person(const string& n, int a):name(n),age(a){}

Teacher::Teacher():Person(),hasPHD(false){}
Teacher::Teacher(const string& n, int a, bool h):Person(n,a),hasPHD(h){}

bool Teacher::isTeacher() const{return true;}
bool Teacher::isStudent() const{return false;}


Student::Student():Person(),hasStudentId(false){}
Student::Student(const string& n, int a, bool h):Person(n,a),hasStudentId(h){}

bool Student::isTeacher() const{return false;}
bool Student::isStudent() const{return true;}
