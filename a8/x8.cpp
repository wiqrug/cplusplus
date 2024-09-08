#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;




template <typename T>
class Stack{
	private:
		vector<T> elements;
	public:
		void push(const T&);
		void display() const;
		void pop();
		int getSize() const;
		void saveToText(const string&)const;

};

class Temp{
	private:
		char* ch;
		double number;
	public:
		Temp();
		Temp(const char*, double);
		Temp(const Temp&);
		~Temp();
		Temp& operator=(const Temp&);
		void display() const;

};

ostream& operator<<(ostream& os,const Temp&);


int main () {

Stack<Temp> tempStack;
Temp t("alekos",1.0);
tempStack.push(t);
//tempStack.pop();
cout<<"-------------------"<<endl;
cout<<tempStack.getSize()<<endl;

tempStack.saveToText("tempp.txt");





return 0;
}


ostream& operator<<(ostream& os,const Temp& t){
	t.display();

return os;
}



void Temp::display() const{
	cout<<"Number: "<<number<<endl;
	cout<<"Ch: "<<ch<<endl;
}




Temp& Temp::operator=(const Temp& other){
	if (this==&other){return *this;}
	else{
		number=other.number;
		delete[] ch;
		ch = new char [strlen(other.ch)+1];
		strcpy(ch,other.ch);
	}

return *this;
}

Temp::Temp(const Temp& other){
	number = other.number;
	ch = new char[strlen(other.ch)+1];
	strcpy(ch,other.ch);
}

Temp::Temp(const char* c,double n){
	number=n;
	ch = new char[strlen(c)+1];
	strcpy(ch,c);
}

Temp::Temp(){
	number=0;
	ch = new char[1];
	*ch='\0';
}

Temp::~Temp() {
	delete[] ch;
}




template<typename T>
void Stack<T>::saveToText(const string& fname)const{
	ifstream ifs(fname);
	if (ifs.is_open()){
		cerr<<"Το όνομα του αρχείο υπάρχει ήδη. Δοκιμάστε με διαφορετικό όνομα"<<endl;
		ifs.close();
		return;
	}
	else{
		ofstream ofs(fname);
		for (const auto& element:elements){
			ofs<<element<<endl;
		}
	}


}

template<typename T>
int Stack<T>::getSize() const{
	return elements.size();
}

template<typename T>
void Stack<T>::pop(){
	if (elements.size()>0){
		elements.pop_back();
	}
}

template<typename T>
void Stack<T>::display() const {
	for (const auto& element:elements){
		cout<<element<<endl;
	}
}

template<typename T>
void Stack<T>::push(const T& element){
	elements.push_back(element);
}


