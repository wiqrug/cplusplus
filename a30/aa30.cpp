#include <iostream>
#include <cstring>


using namespace std;


class MyString{
	private:
		char* ch;
	public:
		MyString();
		MyString(const char*);
		~MyString();
		MyString(const MyString&);
		MyString& operator= (const MyString&);
		bool operator==(const MyString&) const;
		bool operator<(const MyString&) const;
};



bool MyString::operator<(const MyString& other)const{
	return strcmp(ch,other.ch)<0;
}

bool MyString::operator==(const MyString& other)const{
	return strcmp(ch,other.ch)==0;
}


MyString::MyString(){
	ch = new char[1];
	ch[0] = '\0';
}

MyString::~MyString(){delete[] ch;}

MyString& MyString::operator=(const MyString& other){
	if (this==&other){return *this;}

	delete[] ch;
	ch = new char [strlen(other.ch)+1];
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
		ch[0] = '\0';
	}

}


MyString::MyString(const char* c){
	if (c){
		ch = new char [strlen(c)+1];
		strcpy(ch,c);
	}
	else{
		ch = new char[1];
		ch[0] = '\0';
	}
}


int main () {
bool isEqual1,isntGreaterThan1;

MyString emptyStr;
MyString actualStr("loream");

emptyStr=actualStr;

isEqual1 = (actualStr==emptyStr);
cout<<isEqual1<<endl;

isntGreaterThan1 = (actualStr<emptyStr);
cout<<isntGreaterThan1<<endl;

return 0;}
