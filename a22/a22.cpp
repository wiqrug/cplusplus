/*
Να δημιουργηθεί η κλάση “MyString” η οποία θα παριστά
συμβολοσειρές ως λίστες χαρακτήρων. Η κλάση θα πληροί τις ακόλουθες
προδιαγραφές:

Θα αρχικοποιείται με την κενή συμβολοσειρά, με ένα C String, ή ένα άλλο
αντικείμενο MyString.

Θα υπερφορτώνει τον τελεστή “==” και όποιους άλλους σχεσιακούς τελεστές
κριθεί απαραίτητο.

Θα επιστρέφει τη συμβολοσειρά ως C String.

Να γραφεί συνάρτηση η οποία θα ταξινομεί έναν πίνακα με αντικείμενα “MyString”. Η
λειτουργία των προηγούμενων θα επιδειχθεί μέσω κατάλληλης main συνάρτησης.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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
		string display()const ;
		MyString& operator=(const MyString&);
		bool operator==(const MyString&)const ;
		const char* toCString()const ;
};


const char* MyString::toCString()const {return ch;}


bool MyString::operator==(const MyString& other)const{
	return strcmp(ch,other.ch)==0;

}


MyString& MyString::operator= (const MyString& other){
	if (this==&other){return *this; }

	delete[] ch;

	if (other.ch){
	ch = new char[strlen(other.ch)+1];
	strcpy(ch,other.ch);
	}
	else{ch=new char[1];ch[0]='\0';}
	return *this;
}



MyString::MyString(const MyString& other){
	ch  = new char[strlen(other.ch)+1];
	strcpy(ch,other.ch);
}


string MyString::display()const {return ch;}

MyString::MyString(){ch=new char[1];
	ch[0] = '\0';
}


MyString::~MyString(){delete[] ch;}


MyString::MyString(const char* str){
	if (str){
		ch = new char[strlen(str)+1];

		strcpy(ch,str);
	}
	else{ch=new char[1]; ch[0]='\0';}
}





int main (){

MyString s("lorem");
s.display();


string str = s.display();

cout<<str<<endl;
return 0;}
