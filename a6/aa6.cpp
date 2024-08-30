/*
Χρησιμοποιώντας τις Οντότητες: “Άτομο”, “Φοιτητής”, “Καθηγητής”, να
γραφεί παράδειγμα το οποίο θα επιδεικνύει:

Τους κατασκευαστές και τους καταστροφείς

Την κληρονομικότητα

Τις εικονικές μεθόδους

Τις αφηρημένες κλάσεις

Τη δημιουργία και την διαχείριση συλλογών αντικειμένων διαφορετικού τύπου.
Το παράδειγμα δεν χρειάζεται να διαβάζει δεδομένα από την standard είσοδο.
*/

#include <string>
#include <iostream>

using namespace std;


class Person{
	protected:
		string name;
		int age;
	public:
		Person();
		Person(const string&,const int&);
		virtual ~Person();
		virtual bool isStudent() const=0;
};



class Student:public Person{
	private:
		int semester;
	public:
		Student(const string&,const int&,const int&);
		bool isStudent()const override;
};


class Professor:public Person{
	private:
		bool hasPHD;
	public:
		Professor(const string&,const int&, const bool&);
		bool isStudent() const override;
};




int main (){

Student p1("alekos",51,10);
Professor pro1("alekos",51,0);

Person* p= new Student("1",51,10);

cout<<pro1.isStudent()<<endl;

cout<<p1.isStudent()<<endl;


cout<<p->isStudent()<<endl;

return 0;
}
Person::Person(const string& n,const int& a):name(n),age(a){}
Person::Person():name(""),age(0){}
Person::~Person()=default;


Student::Student(const string& n,const int& a,const int& s):Person(n,a),semester(s){}
bool Student::isStudent()const{return true;}

Professor::Professor(const string& n,const int& a,const bool& i):Person(n,a),hasPHD(i){}
bool Professor::isStudent()const {return false;}
