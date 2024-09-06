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
#include <filesystem>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <exception>
using namespace std;



class FileManager{
	private:
		vector<int> numbers;
	public:
		void copyFile(const string&,const string&) const;
		void addNumber(int);
		void display() const;
		void addNumbers(int*,int);
};

void readFromFileAndSaveDoubles(const string& filename,vector<double>& vec);


void saveToBinary(const vector<int>& numbers, const string& dest);




int main () {

try{
FileManager f;
int numbers[] = {1,2,3,4,5};

vector<int> integerNumbers;

vector<double> doubleNumbers;
integerNumbers.push_back(1);
integerNumbers.push_back(1);
integerNumbers.push_back(1);


//f.copyFile("test.txt","chest.txt");


f.addNumber(1);

f.addNumbers(numbers,5);
f.display();

saveToBinary(integerNumbers,"intnumberss.csv");

readFromFileAndSaveDoubles("doubles.txt",doubleNumbers);

for (const auto& number:doubleNumbers){
	cout<<number<<" | " ;
}


}

catch(const logic_error& e ){
cerr<<e.what()<<endl;
}


return 0;
}


void saveToBinary(const vector<int>& numbers, const string& dest){
	ifstream checkDest(dest);
	if (checkDest.is_open()){
		checkDest.close();
		throw logic_error("File already exists");
	}

	ofstream ofs(dest,ios::binary);
	//check for badbit etc
	for (const auto& number:numbers){
		ofs.write((char*)&number,sizeof(int));
	}

}


void readFromFileAndSaveDoubles(const string& filename,vector<double>& vec){
	ifstream ifs(filename);
	vec.clear();
	if (ifs.is_open()){
		string text;
		while(getline(ifs,text)){
			double number = stod(text);
			vec.push_back(number);
		}
	}
	else{
		throw logic_error("This is not something convertable to double");
	}
}


void FileManager::copyFile(const string& source, const string& dest)const{
	ifstream ifs(source);
	ifstream checkDest(dest);
	if (checkDest.is_open()){
		checkDest.close();
		throw logic_error("File already exists");
	}

	ofstream ofs(dest);
	if (ifs.is_open() && ofs.is_open()){
		string text;
		while(getline(ifs,text)){
		ofs<<text<<endl;
		}
	}
	ifs.close();
	ofs.close();

}




void FileManager::addNumbers(int* numbersArray,int size)
{
	for (int i=0;i<size;++i){
		numbers.push_back(numbersArray[i]);
	}

}

void FileManager::display() const{
	for (const auto& n:numbers){
		cout<<n<<endl;
	}
}

void FileManager::addNumber(int number){
	numbers.push_back(number);
}
