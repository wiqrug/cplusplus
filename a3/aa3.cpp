/*
Να δημιουργηθεί μία template κλάση “Ουρά” η οποία θα υποστηρίζει τις
ακόλουθες λειτουργίες:

Εισαγωγή Αντικειμένου στο τέλος της ουράς (Enqueue)

Εξαγωγή του πρώτου στοιχείου της ουράς (Dequeue)

Επιστροφή μεγέθους της ουράς

Έλεγχος ισότητας με άλλη ουρά (Αν τα αντικείμενα που περιέχουν είναι “ίσα”
ένα προς ένα.

Να επιδειχθεί η λειτουργία της ουράς με αντικείμενα μίας κλάσης που θα έχει δύο
μόνο attributes: Έναν ακέραιο και ένα C-String.
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

template<typename T>
class Queue{
	private:
		vector<T> elements;
	public:
		void push(const T&);
		void pop();
		int getSize()const;
		bool operator==(const Queue&);

};

class Temp{
	private:
		int num;
		char* ch;
	public:
		Temp(const int&,const char*);
		~Temp();
		Temp& operator=(const Temp&);
		Temp(const Temp&);
		bool operator==(const Temp&)const;


};





int main () {

	Queue<Temp> q1;
	Queue<Temp> q2;

	Temp t1(1,"test");
	Temp t2(1,"te2st");

	q1.push(t1);

	q2.push(t2);


	bool isEqual = q1==q2;

	cout<<isEqual<<endl;
return 0;
}


//Temp class


Temp::Temp(const int& n, const char* c){
	num = n;
	if (c){
		ch= new char[strlen(c)+1];
		strcpy(ch,c);
	}
	else{
		ch= nullptr;
	}

}


Temp::Temp(const Temp& other){
	num=other.num;

	if (other.ch){
		ch = new char[strlen(other.ch)+1];
		strcpy(ch,other.ch);
	}
	else{
		ch=nullptr;
	}
}

Temp::~Temp(){delete[] ch;}


Temp& Temp::operator=(const Temp& other){
	if (this==&other){return *this;}

	delete[] ch;

	num=other.num;

	if (other.num){
		ch = new char[strlen(other.ch)+1];
		strcpy(ch,other.ch);
	}
	else{
		ch=nullptr;
	}
return *this;

}

bool Temp::operator==(const Temp& other)const{
	if (num==other.num&&!strcmp(ch,other.ch)){return true;}
return false;
}

//


//Queue class




template<typename T>
void Queue<T>::push(const T& element){
	elements.push_back(element);
}

template<typename T>
void Queue<T>::pop(){
	if (!elements.empty()){elements.erase(elements.begin());}
}


template<typename T>
int Queue<T>::getSize()const{return elements.size(); }


template<typename T>
bool Queue<T>::operator==(const Queue& q) {
	return elements==q.elements;

}


