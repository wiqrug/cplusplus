#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include <sstream>
#include <exception>
using namespace std;




class Utilities{
	private:
		vector<double> numbers;
	public:
		void copyFile(const string&, const string&);
		bool fileExists(const string&) const;
		void saveDoubles(const string&);
		void display()const;
		void writeToBinaryFile(const string&) const;

};


void Utilities::writeToBinaryFile(const string& fname) const{
	ofstream ofs;
	ofs.exceptions(ofstream::failbit | ofstream::badbit);
	ofs.open(fname,ios::binary);

	for (const auto& number:numbers){
		ofs.write((char*)&number,sizeof(double));
	}
	ofs.close();
}

void Utilities::display() const{
	for (const auto& number:numbers){cout<<number<<endl;}

}


void Utilities::copyFile(const string& source, const string& destination){
	if(!fileExists(source)){cerr<<"File does not exist my friend"<<endl;}

	ifstream fi(source);
	ofstream fo(destination);
	if (fileExists(source)){
		if (fi.is_open() && fo.is_open()){
			string line;
			while (getline(fi,line)){
				fo<<line<<endl;
			}
		}
		else{cerr<<"There was an unexpected error"<<endl;}
	}
	else{
		cerr<<"File does not exist"<<endl;
	}
}

bool Utilities::fileExists(const string& name) const {return filesystem::exists(name);}

void Utilities::saveDoubles(const string& fname){
	if(fileExists(fname)){
		ifstream fi(fname);
		string line;
		while(getline(fi,line)){
			try{
				numbers.push_back(stod(line));

			}catch(const exception& e){cerr<<"erere"<<endl;}
		}

	}
	else{cerr<<"file name does not exist :) "<<endl;}

}




int main () {

Utilities u;

u.copyFile("lina.txt","nikitas");

u.saveDoubles("lina.txt");
u.display();

return 0;}
