#include <cstring>
#include <iostream>


using namespace std;



class MyString{
	private:
		char* ch;
	public:
		MyString();
		~MyString();
		MyString(const char*);
		MyString(const MyString& );
		MyString& operator= (const MyString&);
		bool operator==(const MyString&)const;
		bool operator !=(const MyString&)const;
		bool operator>(const MyString&)const;
		bool operator<(const MyString&)const;
		int size()const;
		const char* toCString()const;
};



const char* MyString::toCString()const{

return ch;
}


int MyString::size()const{
return (strlen(ch));
}




int main () {
//TESTS


//Empty Constructor
MyString em;

//Argument constructor
MyString arg("alekos");

//Copy Constructor
MyString cp=arg;

//Overloading operator =
em=cp;


char* c=  new char[7];
strcpy(c,"alexis");

char* c1=  new char[7];
strcpy(c1,"aloxis");


char* c2=  new char[6];

//Overloading operator ==
bool check = (arg==cp);

cout <<"Check -> "<<check<<endl;

//Overloading operator !=
check= (arg!=cp);

cout <<"Check -> "<<check<<endl;

//Overloading operator >
check = (arg>cp);
cout <<"Check -> "<<check<<endl;

//Overloading operator <
check = (arg<cp);
cout <<"Check -> "<<check<<endl;

//size
int size = arg.size();

//toCstring


cout<<arg.toCString()<<endl;


return 0;
}




bool MyString::operator>(const MyString& other)const{
	return (strcmp(ch,other.ch)>0);
}

bool MyString::operator<(const MyString& other)const{
	return (strcmp(ch,other.ch)<0);
}


bool MyString::operator==(const MyString& other)const{

return (!strcmp(ch,other.ch));
}

bool MyString::operator!=(const MyString& other)const{

return (strcmp(ch,other.ch));
}



MyString& MyString::operator=(const MyString& other){
	if (this == & other) {return *this;}

	delete[] ch;
	ch = new char[strlen(other.ch)+1];
	ch = strcpy(ch,other.ch);

return *this;
}







MyString::MyString(const MyString& other){
	if (other.ch){
		ch = new char[strlen(other.ch)+1];
		ch = strcpy(ch,other.ch);
	}
	else{
		ch = new char[1];
		ch[0]='\0';
	}


}



MyString::MyString(const char* c)
{
	if (c){
		ch = new char[strlen(c)+1];
		ch = strcpy(ch,c);
	}
	else{
		ch = new char[1];
		ch[0]='\0';
	}
}

MyString::MyString(){
	ch = new char[1];
	ch[0] = '\0';
}


MyString::~MyString(){
	delete[] ch;
}




