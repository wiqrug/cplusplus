/*
Να δημιουργηθεί η κλάση Student η οποία θα έχει τα ακόλουθα
χαρακτηριστικά:
ΑΜ: (int)
Όνομα: (char *)
Εξάμηνο: (int)
Ενεργός;: (bool)

Να γραφεί συνάρτηση η οποία δημιουργεί και επιστρέφει μία συλλογή αντικειμένων
της κλάσης Students με δεδομένα τα οποία διαβάζονται από csv αρχείο. Το όνομα
του αρχείου δίνεται ως όρισμα στη συνάρτηση.

Να γραφεί συνάρτηση η οποία θα τυπώνει τον ΑΜ και το Όνομα κάθε ενεργού
φοιτητή που βρίσκεται σε συλλογή της προηγούμενης συνάρτησης.

Να γραφεί main συνάρτηση η οποία θα επιδεικνύει την λειτουργία των παραπάνω. Η
κλάση Student δεν θα έχει public χαρακτηριστικά και θα έχει μόνο τις απαραίτητες
μεθόδους για την υλοποίηση των παραπάνω ζητούμενων.
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;


class Student{
	private:
		int am;
		char* name;
		int semester;
		bool isActive;
	public:
		Student(const int&,const char* ,const int& ,const bool&);
		~Student();
		Student(const Student&);
		Student& operator=(const Student&);

		void display()const;


};


void displayStudents(const vector<Student>& );

vector<Student> getStudentsFromCSV(const string&);





int main () {

Student s1(151045,"alekos",10,true);
Student s2(152045,"lekos",1,false);

vector<Student> st = getStudentsFromCSV("test.csv");

displayStudents(st);



return 0;}


void displayStudents(const vector<Student>& vec) {
	for (const auto& student:vec){
		student.display();
		}

}


vector<Student> getStudentsFromCSV(const string& filename){
	vector<Student> students;
	ifstream ifs(filename);

	if (ifs.is_open()){
		string line;
		while(getline(ifs,line)){
		stringstream ss(line);
			string am,name,semester,isActive;
			getline(ss,am,',');
			getline(ss,name,',');
			getline(ss,semester,',');
			getline(ss,isActive,',');
			int intAm = stoi(am);
			int intSemester = stoi(semester);
			bool boolIsActive = (isActive=="1" || isActive=="true");
		Student s(intAm,name.c_str(),intSemester,boolIsActive);
		students.push_back(s);
		}
	}
	else{cerr<<"error"<<endl;}


return students;
}


void Student::display() const{
	cout<<" "<<am;
	cout<<" "<<name;
	cout<<" "<<semester;
	cout<<" "<<isActive<<endl;
	cout<<"--------------------------"<<endl;

}


Student& Student::operator=(const Student& other){
	if (this == &other){return *this;}
	delete[] name;
	am=other.am;
	semester=other.semester;
	isActive=other.isActive;

	name = new char[strlen(other.name)+1];
	strcpy(name,other.name);
return *this;
}


Student::Student(const Student& other){
	am = other.am;
	semester=other.semester;
	isActive=other.isActive;

	name = new char[strlen(other.name)+1];
	strcpy(name,other.name);
}


Student::~Student(){delete[] name;}

Student::Student(const int& a, const char* n,const int& s,const bool& i):am(a),semester(s),isActive(i){
	if (n){
		name = new char[strlen(n)+1];
		strcpy(name,n);
	}
	else{
		name=nullptr;
	}

}



