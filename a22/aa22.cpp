#include <iostream>
#include <cstring>
using namespace std;

class MyString{
	private:
		char* ch;
	public:
		MyString();
		MyString(const char*);
		MyString(const MyString&);
		~MyString();
		MyString& operator=(const MyString&);
		bool operator==(const MyString&)const;
		const char* toCString()const;
};






int main () {
//test empty constructor
MyString emptyConstr;

//Test arguments constructor
MyString argConstr("cplusplus");

//Testing operator =
emptyConstr=argConstr;

//Testing operator ==

bool isEqual= (emptyConstr==argConstr);
cout<<isEqual<<endl;

//testing toCString

cout << "String from toCString: " << argConstr.toCString() << endl;


return 0;
}

MyString::~MyString(){delete[] ch;}


const char* MyString::toCString() const{
	return ch;
}


bool MyString::operator==(const MyString& other) const{
	return strcmp(ch,other.ch)==0;
}


MyString& MyString::operator=(const MyString& other){
	if (this==&other){return *this;}
	delete[] ch;
	ch = new char[strlen(other.ch)+1];
	strcpy(ch,other.ch);
return *this;
}


MyString::MyString(const MyString& other){
	if (other.ch){
		ch = new char[strlen(other.ch)+1];
		strcpy(ch,other.ch);
	}
	else{
		ch = new char[1];
		ch[0]='\0';
	}

}


MyString::MyString(){
	ch = new char[1];
	ch[0]='\0';
}


MyString::MyString(const char* c){
	if (c){
		ch = new char[strlen(c)+1];
		strcpy(ch,c);
	}
	else{
		ch = new char[1];
		ch[0]='\0';
	}
}

