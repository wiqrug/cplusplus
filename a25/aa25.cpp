#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



class FileManager{
	private:
		string source;
	public:
		FileManager();
		FileManager(const string&);
		void copyFile(const string&)const;
		void saveToFile(const string&,const vector<string>&);
		void readFromFile(const string&)const;
		long getFileSize(const string&) const;
};


//This was really fun
long FileManager::getFileSize(const string& source)const{
	ifstream file(source, ios::binary | ios::ate);

	if (file.is_open()){
		long size = file.tellg();
		file.close();
		return size;
	}
	else{
		cerr<<"Error: could not open file"<<endl;
		return -1;
	}
}




void FileManager::readFromFile(const string& source)const{
	ifstream ifs(source);

	if (ifs.is_open()){
		string text;
		while(getline(ifs,text)){
			cout<<text<<endl;
		}
	}

}


FileManager::FileManager(){}
FileManager::FileManager(const string& fname):source(fname){}

void FileManager::saveToFile(const string& dest, const vector<string>& vec){
	ofstream ofs(dest);

	if(ofs.is_open()){
		for (const auto& item:vec){
			ofs<<item<<endl;
		}
	}
	else{
		cerr<<"There was an error....."<<endl;
	}


}



void FileManager::copyFile(const string& dest)const{
	ofstream ofs(dest);
	ifstream ifs(source);

	if(ofs.is_open() && ifs.is_open()){

		string text;
		while (getline(ifs,text)){
			ofs<<text<<endl;
		}
	}
	else{cerr<<"there was an error copying the file"<<endl;}


}





int main () {
FileManager f("f.txt");

f.copyFile("f2.txt");

vector<string> s;
s.push_back("sdf");
s.push_back("sdf");
s.push_back("sdf");
s.push_back("sdf");
s.push_back("sdf");

FileManager t;

t.saveToFile("temp.txt",s);
t.readFromFile("temp.txt");
cout<<"-----------------------------"<<endl;
cout<<t.getFileSize("temp.txt")<<endl;


return 0;
}


