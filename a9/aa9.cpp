#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <exception>
#include <filesystem>
using namespace std;

class FileManager{
	private:
		string filename;
	public:
		void copyFile(string&)const;
		void invertFile(string&)const;
		FileManager(const string&);
		void showFileSize() const;
		void copyInverted(const string&) const;

};

//i should use seekg and tellg here
void FileManager::copyInverted(const string& dest)const{
	ifstream ifs(filename);
	ofstream ofs(dest);
	if (ofs.is_open() && ifs.is_open()){
		string text;
		while (getline(ifs,text)){
			reverse(text.begin(),text.end());
			ofs<<text<<endl;
		}

	ifs.close();
	ofs.close();
	}

}


void FileManager::showFileSize() const{
	ifstream ifs(filename,ios::binary|ios::ate);
	try{
		if (ifs.is_open()){
			auto fileSize = ifs.tellg();
			ifs.close();
			cout<<"File size is: "<<fileSize<<endl;
		}
	}
	catch(exception& e) {cerr<<"error opening file"<<endl;}
}


FileManager::FileManager(const string& s):filename(s){}

void FileManager::copyFile(string& dest) const{
	ifstream ifsCheck(dest);
	ifstream ifs(filename);

	if (ifsCheck.is_open()){
		ifsCheck.close();
		throw logic_error("file already exists");
	}
	else{
		ofstream ofs(dest);

		if (ifs.is_open() && ofs. is_open()){
			string text;
			while (getline(ifs,text)){
				ofs<<text<<endl;
			}
		}
	}

}




int main () {

FileManager f("temp.txt");
string dest="stemp.txt";
//f.copyFile(dest);

f.showFileSize();



return 0;
}
