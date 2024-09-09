#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class UString{
	private:
		string ustring;
	public:
		UString(const string&);
		void display() const;
		UString();
		UString& operator=(const UString&);
		UString& operator=(const string&);
		string getUString()const;

};

void printCollection (ostream&,UString*,int);
UString* getRandomString( int n, int k);





int main () {
UString s("ERE");
UString test("test");

int n=5;
int k=5;

UString* arrUString = getRandomString(n,k);

printCollection(cout,arrUString,n);

delete[] arrUString;

s.display();



return 0;
}

string UString::getUString() const{return ustring;}

UString::UString(){ustring="";}
UString& UString::operator=(const string& other){
	ustring="";
	for (const auto& s:other){
		if (s>='A' && s<='Z'){ustring+=s;}
		else{ustring="";break;}
	}
return *this;
}

UString& UString::operator=(const UString& other){
	ustring = other.ustring;
return *this;
}


void UString::display() const {
	cout<<ustring<<endl;
}


UString::UString(const string& other){
//Έλεγχος για κεφαλαία
for (const auto& s:other){
	if (s>='A' && s<='Z'){
		ustring+=s;
	}

	else{cout<<"Ένα UString έχει  μόνο κεφαλαίους λατινικούς χαρακτήρες, το string "<<other<<" δεν είναι έγκυρο"<<endl;
	ustring="";
	return;
	}
}



}



//UTILS
void printCollection(ostream& os, UString* collection, int size){
	for (int i=0;i<size;i++){
		os<<collection[i].getUString()<<endl;
	}

}



UString* getRandomString(int n, int k){
	UString* temp = new UString[n];
	string tempStr="";
	for (int i=0; i<n; i++){
		for (int j=0;j<k;j++){
			char tempChar='A' + rand()%26;
			tempStr= tempStr+ tempChar;
		}
		temp[i] = tempStr;
		tempStr="";
	}

return temp;
}
