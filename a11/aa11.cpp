/*
Να δημιουργηθεί μία κλάση “βαθμολόγιο μαθήματος”. Κάθε αντικείμενο
της κλάσης περιέχει βαθμούς ενός μαθήματος για ένα ακαδημαϊκό εξάμηνο. Η κλάση
θα δίνει τις ακόλουθες δυνατότητες:
Την εισαγωγή ενός φοιτητή στην λίστα των φοιτητών που παρακολουθούν το
μάθημα..
Την εισαγωγή βαθμού σε φοιτητή που βρίσκεται στην προηγούμενη λίστα.
Την εξαγωγή όλων των βαθμολογιών σε σε csv αρχείο.
Να επιδειχθεί η λειτουργία της κλάσης μέσω κατάλληλης main.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;




class Grade{
	private:
		string name;
		double grade;

	public:
		Grade(const string& ,const double&);
		Grade(const string&);
		string getName()const;
		double getGrade()const;
		void setGrade(const double&);
};






class Gradebook{
	private:
		vector<Grade> grades;
	public:
		void addStudent(const Grade&);
		void addGrade(const string&,const double&);
		void saveToFile(const string&);
};






int main () {
Gradebook g;

g.addStudent(Grade("nikolas"));
g.addGrade("nikolas",5);

g.saveToFile("nicolasGrade.txt");



return 0;
}





//Grade
void Grade::setGrade(const double& g){
	grade = g;
}


double Grade::getGrade()const{return grade;}
string Grade::getName()const{return name;}


Grade::Grade(const string& n):name(n),grade(-1){}
Grade::Grade(const string& n,const double& g):name(n),grade(g){}


//GradeBook
void Gradebook::saveToFile(const string& filename){
	ofstream ofs(filename);
	if (ofs.is_open()){
		for (const auto& item:grades){
			ofs<<item.getName()<<","<<item.getGrade()<<endl;
		}
	}
	else{
		cerr<<"could not open file"<<endl;
	}


}

void Gradebook::addGrade(const string& n, const double& g){
	for (auto& item:grades){
		if(item.getName() == n){
			item.setGrade(g);
		}
	}

}



void Gradebook::addStudent(const Grade& gr){
	grades.push_back(gr);

}
