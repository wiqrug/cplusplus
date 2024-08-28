#include <iostream>
#include <vector>
#include <cstring>
#include <vector>

using namespace std;


class MyString{
	private:
		char* cstring;
	public:
		MyString(const char*);
		MyString();
		~MyString();
		MyString(const MyString&);
		MyString& operator=(const MyString&);
		bool operator==(const MyString&);
		bool operator<(const MyString&);
		MyString* split(char delimiter, int& size) const;
};

MyString* MyString::split(char delimiter, int& size) const {
	int count = 0;
	int length = strlen(cstring);

	for (int i = 0; i < length; ++i) {
	if (cstring[i] == delimiter) {
	count++;
		}
	}

	size = count + 1;
	MyString* result = new MyString[size];

	int start = 0;
	int substringIndex = 0;

	for (int i = 0; i <= length; ++i) {
	if (cstring[i] == delimiter || cstring[i] == '\0') {
	int substrLength = i - start;
	char* substr = new char[substrLength + 1];
	strncpy(substr, cstring + start, substrLength);
	substr[substrLength] = '\0';
	result[substringIndex] = MyString(substr);
	delete[] substr;
	substringIndex++;
	start = i + 1;
	}
	}

	return result;
}

bool MyString::operator<(const MyString& other){
	return strcmp(cstring,other.cstring)<0;
}

bool MyString::operator==(const MyString& other){
	return strcmp(cstring,other.cstring)==0;
}


MyString::MyString(){
	cstring = new char[1];
	cstring[0] = '\0';
}


MyString::~MyString(){
	delete[] cstring;
}

MyString::MyString(const char* str){
	if (str){
		cstring = new char[strlen(str)+1];
		strcpy(cstring,str);
	}
	else{
		cstring = new char[1];
		cstring[0]='\0';
	}

}

MyString::MyString(const MyString& other){
	cstring = new char[strlen(other.cstring)+1];
	strcpy(cstring,other.cstring);
}


MyString& MyString::operator=(const MyString& other) {
	if (this == &other){return *this;}

	delete[] cstring;
	cstring = new char[strlen(other.cstring)+1];
	strcpy(cstring,other.cstring);

	return *this;

}




int main () {
MyString s("pipikakos");
MyString p("pipikakos");
MyString l("likakos");

bool sEqualp = (s==p);
bool pEquall = (p==l);

cout<<sEqualp<<" ---- " <<pEquall<<endl;


bool isGreaterThan = (s<p);

bool isGreaterThan2 = (l<s);


cout<<isGreaterThan<<" -----" << isGreaterThan2 << endl;

return 0;

}
