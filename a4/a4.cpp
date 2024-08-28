#include <iostream>
#include <cstring>
#include <cstddef>
using namespace std;

class MyString{
	private:
		char* str;
	public:
		MyString();
		MyString(const char*);
		MyString( const MyString&);
		~MyString();
		bool  operator==(const MyString& )const;
		bool operator!=(const MyString& )const ;
		bool operator>(const MyString& )const ;
		bool operator<(const MyString& ) const;

		void operator+=(const char*);
		int getLength();
		const char* getCString();

};


int main() {
    MyString maa;

    MyString m("veligradi");
    MyString n("montenegro");

    bool isEqual = (m == n);
    bool isNotEqual = (m != n);
    bool isGreaterThan = (m > n);
    bool isNotGreaterThan = (m < n);

    int length = m.getLength();

    m += "a";  // Appending "a" to "veligradi"

    const char* c = m.getCString();
    cout << c << endl;  // Expected output: "veligradia"

    return 0;
}



const char* MyString::getCString() {return str;}




int MyString::getLength(){
	return strlen(str);
}


MyString::MyString(){
	str = new char[2];
	*str=' ';
	*(str+1)='\0';
}


MyString::MyString(const char* newChar){
	if (newChar){str = new char[strlen(newChar)+1]; strcpy(str,newChar);}
	else{str = nullptr;}
}

MyString::MyString(const MyString& other){
	if (other.str){str = new char[strlen(other.str)+1];strcpy(str,other.str);}
	else{str=nullptr;}
}

MyString::~MyString(){delete[] str;}

bool MyString::operator==(const MyString& other) const
{
	if (strcmp(str,other.str)){
		return 1;
	}
	else {return 0;}

}

bool MyString::operator!=(const MyString& other) const
{
	if (strcmp(str,other.str)){
		return 0;
	}
	else {return 1;}

}
bool MyString::operator>(const MyString& other) const
{
	if (strcmp(str,other.str)>0){
		return 1;
	}
	else {return 0;}

}
bool MyString::operator<(const MyString& other) const
{
	if (strcmp(str,other.str)<0){
		return 1;
	}
	else {return 0;}

}

void MyString::operator+=(const char* c) {
    if (c) {
        size_t newLength = strlen(str) + strlen(c) + 1;
        char* newStr = new char[newLength];
        strcpy(newStr, str);
        strcat(newStr, c);
        delete[] str;
        str = newStr;
    }
}
