/*
Να δημιουργηθεί μία κλάση “γενικού χειρισμού αρχείων” η οποία θα
αρχικοποιείται με ένα string το οποίο θα παριστά το όνομα του αρχείου και θα μπορει
να εκτελέσει τις ακόλουθες λειτουργίες:
Θα επιστρέφει το μέγεθος του αρχείου σε bytes.

Θα αντιγράφει το αρχείο σε ένα άλλο

Θα δημιουργεί ένα νέο αρχείο το οποίο θα περιέχει τα δεδομένα του αρχικού
με ανάποδη σειρά byte προς byte.

Να επιδειχθεί η λειτουργία της κλάσης μέσω κατάλληλης main.
*/

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <algorithm>
using namespace std;

class FileHandler{
	private:
		string filename;
	public:
		FileHandler(const string&);
		void copyFile(const string&)const;
		void copyInverted(const string&)const;
		streamsize getFileSize()const;

};

streamsize FileHandler::getFileSize() const {
	ifstream ifs(filename, ios::binary | ios::ate);
	if (!ifs.is_open()) {
		cerr << "Error opening file: " << filename << endl;
		return -1;
		}
	return ifs.tellg();
}


FileHandler::FileHandler(const string& fname):filename(fname){}


void FileHandler::copyFile(const string& dest)const{
	ofstream ofs(dest);
	ifstream ifs(filename);
	if (ofs.is_open()&&ifs.is_open()){
		string text;
		while(getline(ifs,text)){
			ofs<<text<<endl;
		}
	}
}



void FileHandler::copyInverted(const string& dest)const{
	ofstream ofs(dest);
	ifstream ifs(filename);
	if (ofs.is_open() && ifs.is_open()){
		string text;
		while(getline(ifs,text)){
			reverse(text.begin(),text.end());
			ofs<<text<<endl;
		}
	}
}



int main () {
FileHandler f1("temp.txt");

f1.copyFile("pemp.txt");

f1.copyInverted("lemp.txt");

return 0;
}
