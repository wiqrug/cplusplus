#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <string>
using namespace std;



class MyString{
	private:
		char* word;
	public:
		MyString();
		MyString(const char*);
		~MyString();
		MyString(const MyString&);
		MyString& operator=(const MyString&);
		int getSize()const;
		const char* getWord()const ;
		bool operator==(const MyString&)const;
		bool operator>(const MyString&)const;
		bool operator<(const MyString&)const;
		vector<MyString> splitString(const char*,const char);
		void display() const;

};

void MyString::display() const{
	cout<<word<<endl;
}

vector<MyString> MyString::splitString(const char* words,const char delimiter ){
	vector<MyString> vec;
	stringstream ss(words);
	string text;
	while(getline(ss,text,delimiter)){
		MyString s(text.c_str());
		vec.push_back(s);
	}
return vec;
}

void displayVector(vector<MyString>& vec){
	for (const auto& item:vec){item.display();}
}



const char* MyString::getWord() const{
	return word;
}




int main () {
//TEST RULE OF 3
MyString emptyStr;
MyString argStr("lorem");
MyString copyStr(argStr);
MyString operatorTestStr = copyStr;
cout<< argStr.getSize()<<endl;

//TEST OVERLOADED OPERATORS
bool isEqual = argStr==copyStr;
cout<<isEqual<<endl;
isEqual = argStr<copyStr;
cout<<isEqual<<endl;
isEqual = argStr>copyStr;
cout<<isEqual<<endl;

cout<<"-------------------------------"<<endl;
cout<<argStr.getWord();

// TEST splitString FUNCTION
vector<MyString> splitWords = argStr.splitString(argStr.getWord(), ' ');

cout << "Split words:" << endl;
displayVector(splitWords);

return 0;
}









bool MyString::operator==(const MyString& other) const{
	return strcmp(word,other.word)==0;

}
bool MyString::operator>(const MyString& other) const{
	return strcmp(word,other.word)>0;

}
bool MyString::operator<(const MyString& other) const{
	return strcmp(word,other.word)<0;

}

int MyString::getSize() const{return strlen(word);}


MyString& MyString::operator=(const MyString& other){
	if(this==&other){return *this;}
	delete[] word;
	word = new char[strlen(other.word)+1];
	strcpy(word,other.word);

return *this;
}

MyString::MyString(const MyString& other){
	word = new char[strlen(other.word)+1];
	strcpy(word,other.word);
}


MyString::~MyString(){delete[] word;}
MyString::MyString(){
	word = new char[1];
	*word = '\0';
}

MyString::MyString(const char* w){
	if (w){
		word = new char[strlen(w)+1];
		strcpy(word,w);
	}
	else{
		word = new char[1];
		*word ='\0';
	}
}
