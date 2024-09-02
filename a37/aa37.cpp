/*
Να γραφεί κλάση που θα παρέχει στον χρήστη της την ακόλουθη
συλλογή ανεξάρτητων λειτουργιών:

Αντιγραφή αρχείου: Δημιουργεί αντίγραφο αρχείου στον αποθηκευτικό χώρο.
Τα ονόματα των δύο αρχείων (source, destination) δίδονται παραμετρικά ως
strings. Σε περίπτωση που το αρχείο προορισμού υπάρχει ήδη, θα
δημιουργείται εξαίρεση.

Αποθήκευση πίνακα ακεραίων σε binary αρχείο.

Διάβασμα αρχείου πραγματικών αριθμών. Θα διαβάζει ένα text αρχείο
συμβολοσειρά προς συμβολοσειρά και θα αποθηκεύει σε vector <double>
τους πραγματικούς αριθμούς που βρίσκονται σε αυτό.

Ο χειρισμός των πιθανών λαθών θα γίνεται με εξαιρέσεις.
Να γραφεί κύριο πρόγραμμα το οποίο θα επιδεικνύει την λειτουργία των
προηγούμενων.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <exception>
using namespace std;


class FileManager{
	private:
		vector<int> elements;
	public:
		void copyFileToDest(const string&, const string&) const;
		FileManager();
		FileManager(const vector<int>&);
		void addElement(const int&);
		void saveVectorToBinary(const string&)const;
		vector<double> readFileAndSaveDoubles(const string&) const;

};

void display(vector<double>& numbers);



void generateElements(vector<int>&);


int main () {
FileManager fmanager;

fmanager.copyFileToDest("test.txt","pest.txt");

vector<int> temp;
//Hide functionality from main
generateElements(temp);
FileManager testConstructor(temp);		//its ok

testConstructor.saveVectorToBinary("lorem.bin");


vector<double> numbers = testConstructor.readFileAndSaveDoubles("doubles.txt");
display(numbers);


return 0;}
void display(vector<double>& numbers){
	for (const auto& number:numbers){
		cout<<number<<endl;
	}

}



vector<double> FileManager::readFileAndSaveDoubles(const string& fname) const{
	vector<double> numbers;
	if (!filesystem::exists(fname)){
		cerr<<"Filename doesnt exist :)"<<endl;
	}
	else{
		ifstream ifs(fname);
		string text;
		while(getline(ifs,text)){
			try{
				double number = stod(text);
				numbers.push_back(number);
			}catch(const exception& e){cerr<<"Exception caught at: "<<e.what();}
		}
	}
return numbers;
}


void FileManager::saveVectorToBinary(const string& dest)const{
	if(filesystem::exists(dest)){
		cerr<<"Filename already exists"<<endl;
	}
	else{
		//please remember this. super important!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		ofstream ofs(dest,ios::binary);


		try { if(ofs.is_open()){
			ofs.write((char*)elements.data(),elements.size()*sizeof(int));
			ofs.close();
			cout<<"Data written to "<<dest<<endl;
			}
			else{throw "error";}
		}
		catch(exception& e){
			cerr<<"An error occured"<<e.what()<<endl;
		}

	}
}






void generateElements(vector<int>& t){
	for (int i=0;i<20;i++){
		t.push_back(i);
	}
}



FileManager::FileManager(){}

void FileManager::copyFileToDest(const string& source, const string& dest)const{
	//check that file doesnt exist
	if (!filesystem::exists(dest)){
	ifstream ifs(source);
	ofstream ofs(dest);
	string text;
	while(getline(ifs,text)){
		ofs<<text<<endl;
	}
	}
	else{cerr<<"Name of destination file already exists"<<endl;}
}


void FileManager::addElement(const int& element){
	elements.push_back(element);
}

FileManager::FileManager(const vector<int>& newElements){
	elements= newElements;
}
