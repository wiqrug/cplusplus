/*
Να δημιουργηθεί κλάση η οποία θα παριστά την οντότητα “Λήμμα
Λεξικού”. Κάθε λήμμα θα περιέχει μόνο τον όρο και τη σημασία του.
Να δημιουργηθεί κλάση η οποία θα παριστά την οντότητα “Λεξικό” η οποία θα
περιέχει μία συλλογή λημμάτων και θα έχει τις εξής δυνατότητες:
Θα προσθέτει ένα λήμμα στο λεξικό.
Θα διαγράφει ένα λήμμα από το λεξικό.
Θα επιστρέφει ένα λήμμα από το λεξικό (αναζήτηση με βάση τον όρο).
Θα αποθηκεύει το λεξικό σε text αρχείο με γραμμογράφηση που επιλέγεται
από τον εξεταζόμενο φοιτητή.
Θα διαβάζει το λεξικό από text αρχείο (με την προηγούμενη γραμμογράφηση)
Θα επιστρέφει μία ταξινομημένη “λίστα” των όρων που περιέχονται στο λεξικό
(σε δομή επιλογής του εξεταζόμενου φοιτητή).
Να επιδειχθεί η λειτουργία των παραπάνω μέσω κατάλληλης main συνάρτησης.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


class Entry{
	private:
		string term;
		string meaning;
	public:
		Entry(const string&,const string&);
		bool operator==(const Entry&)const;
		string getTerm()const;
		string getMeaning() const;
		Entry& operator= (const Entry&);
		void display()const;

};


class Dictionary{
	private:
		vector<Entry> entries;
	public:
		void addToDictionary(const Entry&);
		void deleteFromDictionary(const Entry&);
		Entry searchByTerm(const string& t)const;
		void saveToFile(const string&)const;
		void readFromFile(const string&)const;
		vector<string> sortedTerms()const;

};





int main () {

Entry e1("earth","the planet that we live in");
Entry e2("venus","a planet in our solar system");
Dictionary d1;
d1.addToDictionary(e1);
d1.addToDictionary(e2);
Entry search = d1.searchByTerm("earth");

search.display();

d1.saveToFile("pipi.txt");
d1.readFromFile("pipi.txt");
return 0;
}


//Dictionary
vector<string> Dictionary::sortedTerms() const {
	vector<string> terms;
	for (const auto& entry : entries) {
	terms.push_back(entry.getTerm());
	}

	sort(terms.begin(), terms.end());
	return terms;
}

void Dictionary::readFromFile(const string& filename)const{
	ifstream ifs(filename);
		if (ifs.is_open()){
		string text;
		while(getline(ifs,text)){
				cout<<text<<endl;
			}

		}
		else{cerr<<"Error finding file"<<endl;}

}



void Dictionary::saveToFile(const string& filename)const{
		ofstream of(filename);
		if(of.is_open()){
			for (const auto& entry:entries){
				of<<entry.getTerm()<<","<<entry.getMeaning()<<endl;
			}
		of.close();
		}
		else{
			cerr<<"Could not open file"<<endl;
		}

}





Entry Dictionary::searchByTerm(const string& t)const{
	for (const auto& entry:entries){
			if (entry.getTerm()==t){
				return entry;
			}
		}
	return Entry("","");
}



void Dictionary::deleteFromDictionary(const Entry& en){
	for (int i=0;i<entries.size();i++){
		if(en==entries[i]){
			entries.erase(entries.begin() + i);
			return;
		}
	}
}

void Dictionary::addToDictionary(const Entry& en){
	entries.push_back(en);
}


//Entry
void Entry::display()const{
	cout<<term<<endl;
	cout<<meaning<<endl;

}

Entry& Entry::operator=(const Entry& other){
	if (this==&other){return *this;}

	term= other.term;
	meaning=other.meaning;

	return *this;
}



string Entry::getTerm()const{return term;}
string Entry::getMeaning()const{return meaning;}


bool Entry::operator==(const Entry& other)const{

	if (term==other.term && meaning==other.meaning){return true;}
	return false;
}



Entry::Entry(const string& o, const string& s):term(o),meaning(s){}
