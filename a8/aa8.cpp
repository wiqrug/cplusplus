/*
Να δημιουργηθεί μία template κλάση “Στοίβα” η οποία θα υποστηρίζει τις
ακόλουθες λειτουργίες:
Εισαγωγή Αντικειμένου στην κορυφή της στοίβας. (Push)

Εξαγωγή Αντικειμένου από την κορυφή της στοίβας (Pop).

Επιστροφή μεγέθους της στοίβας.

Αποθήκευση της στοίβας σε text αρχείο

Η στοίβα δεν θα έχει περιορισμούς μεγέθους πέρα από αυτούς που προκύπτουν από
την διαθέσιμη RAM.
Να επιδειχθεί η λειτουργία της στοίβας με αντικείμενα μιας
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;



template<typename T>
class Stack{
	private:
		vector<T> elements;
	public:
		void push(T& element);
		void pop();
		int stackSize() const;
		void save(const string&) const;
		void display() const;
		int getSize()const;
		const vector<T>& getElements()const;
};




class Dummy{
	private:
		char* ch;
		double number;
	public:
		Dummy(const char*, const double&);
		~Dummy();
		Dummy(const Dummy&);
		Dummy& operator=(const Dummy&);
		const char* getCh()const;
		const double getNumber()const;
};
ostream& operator<<(ostream& os, const Dummy& d) {
	os << "Dummy(" << d.getCh() << ", " << d.getNumber() << ")";
	return os;
}

ostream& operator<<(ostream& os, const Stack<Dummy>& s) {
    const vector<Dummy>& elems = s.getElements();
    for (const auto& elem : elems) {
        os << elem << endl;
    }
    return os;
}


int main () {

Stack<Dummy> s;

Dummy d1("dummy1",5);
Dummy d2("dummy2",6);
s.push(d1);
s.push(d2);
cout<<d1.getCh()<<endl;
//s.display();
return 0;
}
template<typename T>
const vector<T>& Stack<T>::getElements() const {
	return elements;
}

template<typename T>
int Stack<T>::getSize() const{return elements.size();}


template<typename T>
void Stack<T>::display() const{
	for (const auto& element:elements){
			cout<<element<<endl;
		}
}


template<typename T>
void Stack<T>::push(T& element){
	elements.push_back(element);
}

template<typename T>
void Stack<T>::pop(){
	if(!elements.empty()){
		elements.erase(elements.end());
	}
	else{cout<<"stack is already empty"<<endl;}
}

const double Dummy::getNumber()const{return number;}

const char* Dummy::getCh()const{return ch;}


Dummy::Dummy(const char* c, const double& n){
	number = n;
	if (c){
		ch = new char[strlen(c)+1];
		strcpy(ch,c);
	}
	else{
		ch= new char[1];
		ch[0]= '\0';
	}
}

Dummy::~Dummy(){delete[] ch;}

Dummy& Dummy::operator=(const Dummy& other){
	if (this ==&other){return *this;}

	delete[] ch;
	number = other.number;
	ch = new char[strlen(other.ch)+1];
	ch = strcpy (ch,other.ch);
return *this;
}

Dummy::Dummy(const Dummy& other){
	number= other.number;

	if (other.ch){
		ch= new char[strlen(other.ch)+1];
		strcpy(ch,other.ch);
	}
	else{
		ch = new char[1];
		ch[0]='\0';
	}

}

