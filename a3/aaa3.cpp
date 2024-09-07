#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


template<typename T>
class Queue{
	private:
		vector<T> elements;
	public:
		void enqueue(const T&);
		void dequeue();
		int getSize() const;
		T getElementAt(int)const ;
};

template<typename T>
T Queue<T>::getElementAt(int pos) const{
	if (pos<elements.size()){return elements.at(pos);}
	else{cerr<<"something bad happened"<<endl;return T();}
}


template<typename T>
bool isEqual(const Queue<T>&,const Queue<T>&);


class Temp{
	private:
		char* ch;
		int number;
	public:
		Temp();
		Temp(const char*,int);
		~Temp();
		Temp(const Temp&);
		Temp& operator =(const Temp&);
		bool operator==(const Temp&);
		const char* getChar()const;
		int getNumber() const;

};

int main () {
Queue<int> q;
Queue<int> q2;
q2.enqueue(1);
q.enqueue(1);
q.dequeue();
cout<<q.getSize()<<endl;
////////////////////////////////
//	TEST TEMP	///////

Temp emptyConstr;
Temp argsConstr("alex",1);
Temp copyConstr(argsConstr);
Temp assignment = copyConstr;

cout << isEqual(q,q2);


return 0;
}

template<typename T>
bool isEqual (const Queue<T>& q1,const Queue<T>& q2){
	if (q1.getSize() != q2.getSize()){return false;}

	for (int i=0; i<q1.getSize(); i++){
		if(q1.getElementAt(i)!=q2.getElementAt(i)){return false;}
	}

return true;

}




template<typename T>
int Queue<T>::getSize() const{
	return elements.size();
}

template<typename T>
void Queue<T>::enqueue(const T& element){
	elements.push_back(element);
}



template<typename T>
void Queue<T>::dequeue() {
	if (!elements.empty()){
		elements.erase(elements.begin());
	}

}





int Temp::getNumber()const{return number;}
const char* Temp::getChar()const{return ch;}


bool Temp::operator==(const Temp& other){
	if (this->getNumber() == other.getNumber() && strcmp(this->getChar(),other.getChar())==0)
	{return true;}
	else{return false;}

}



Temp::~Temp(){delete[] ch;}

Temp& Temp::operator=(const Temp& other){
	if (this == & other){return *this;}

	delete[] ch;
	number = other.number;
	ch = new char[strlen(other.ch)+1];
	strcpy(ch,other.ch);
return *this;
}


Temp::Temp(const Temp& other){
	number=other.number;
	ch = new char[strlen(other.ch)+1];
	strcpy(ch,other.ch);
}


Temp::Temp(){
	number=0;
	ch= new char[1];
	*ch='\0';
}

Temp::Temp(const char* c, int n){
	number=n;
	if (c){
		ch = new char [strlen(c) +1];
		strcpy(ch,c);
	}
	else{
		ch = new char[1];
		*ch='\0';
	}
}

