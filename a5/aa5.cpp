#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <sstream>
#include <algorithm>

using namespace std;


class Entry{
	private:
		string term;
		string meaning;
	public:
		Entry();
		Entry(const string,const string);
		void display() const;
		string getTerm()const;
		string getMeaning()const;
		void setTerm(const string&);
		void setMeaning(const string&);
};
void Entry::setTerm(const string& t ){
	term=t;
}

void Entry::setMeaning(const string& m){
	meaning=m;
}

class Dictionary{
	private:
		vector<Entry> entries;
	public:
		void addEntry(const Entry&);
		void deleteEntry(const Entry&);
		void displayEntries()const;
		Entry searchByTerm(string) const;
		void addToFile(string, const char) const;
		vector<Entry> readFromFile(string, const char) const;
		vector<string> getSortedTerms() const;
};



int main () {

Entry emptyConstr;
Entry argsConstr("Sun","is a star");
Entry earth("Earth","is the planet tha we live in");
Entry venus("Venus","a very hot planet");
Dictionary emptyDict;

emptyDict.addEntry(earth);
emptyDict.addEntry(venus);
emptyDict.displayEntries();

Entry searchEntry = emptyDict.searchByTerm("Earth");

emptyDict.addToFile("temp.txt",',');



return 0;
}





//ENTRY

string Entry::getTerm() const{return term;}
string Entry::getMeaning() const{return meaning;}

void Entry::display() const{
	cout<<"Term: "<<term<<" | Meaning:" << meaning<<endl;
}


Entry::Entry(){
	term="";
	meaning="";
}


Entry::Entry(const string t,const string m){
	term=t;
	meaning=m;

}





//DICTIONARY


vector<string> Dictionary::getSortedTerms() const{
	vector<string> temp;
	for (const auto& entry:entries){
		temp.push_back(entry.getTerm());
	}
	sort(temp.begin(),temp.end());

return temp;
}



vector<Entry> Dictionary::readFromFile(string fname,const char delimiter) const{
	vector<Entry> readEntries;
	ifstream ifs(fname);
	Entry temp;
	if (ifs.is_open()){
		string text;
		while(getline(ifs,text)){
			stringstream ss(text);
			string term,meaning;
			getline(ss,term,delimiter);
			getline(ss,meaning,delimiter);
			temp.setTerm(term);
			temp.setMeaning(meaning);
			readEntries.push_back(temp);

		}
	}
	else{cerr<<"could not open file"<<endl;}
return readEntries;

}



void Dictionary::addToFile(string dest,const char delimiter) const {
	ifstream ifs(dest);
	if (ifs.is_open()){
		cerr<<"File already exists"<<endl;
		ifs.close();
		return ;
	}

	ofstream ofs(dest);
	for (const auto& entry:entries){
		ofs<<entry.getTerm()<<delimiter<<entry.getMeaning()<<endl;
	}

	ofs.close();

}

Entry Dictionary::searchByTerm(string otherTerm) const{
	Entry e ("","");
	for (const auto& entry:entries){
		if (entry.getTerm() == otherTerm){
			return entry;
		}
	}
	cout<<"Entry not found, im returing an empty entry"<<endl;
return e;
}


void Dictionary::deleteEntry(const Entry& other){
	for (int i=0;i<entries.size();i++){
		if (entries[i].getTerm()==other.getTerm() && entries[i].getMeaning()==other.getMeaning()){
			entries.erase(entries.begin() +i);
			return;
		}
	}
}

void Dictionary::displayEntries()const{
	for (const auto& entry:entries){
		entry.display();
	}
}

void Dictionary::addEntry(const Entry& newEntry){
	entries.push_back(newEntry);
}

