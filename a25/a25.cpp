#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


class FileManager{
	private:
		string fileName;
	public:
		void getFileSize()const;
		FileManager(const string&);
		FileManager();
		void copyFile(const string&);

		string returnFileContent(const string&);
		void addVector(const vector<string>&);
};


void FileManager::addVector(const vector<string>& vec){
	ofstream ofs(fileName);

	if (ofs.is_open()){
		for (const auto& element: vec){
		ofs<<element<<endl;
	}
	ofs.close();}

	else{cerr<<"Failed"<<endl;}

}


string FileManager::returnFileContent(const string& fname){
	ifstream fs(fname);

	if (fs.is_open()){
		stringstream buffer;
		buffer<<fs.rdbuf();
		fs.close();
		return buffer.str();
	}
	else
	{cerr<<"There was an error"<<endl;
		return "";
	}

}



void FileManager::copyFile(const string& fname){
	ifstream readFile(fileName);
	ofstream writeToFile(fname);

	if (readFile.is_open() & writeToFile.is_open()){
		string text;
		while (getline(readFile,text)){
			writeToFile<<text<<endl;
		}
	}
	else{
		cerr<<"Failed to copy file"<<endl;
	}

}




FileManager::FileManager(){
	fileName="";
}


FileManager::FileManager(const string& fname){
	fileName=fname;
}



void FileManager::getFileSize() const{
	filesystem::path filePath = fileName;

	cout<<filesystem::file_size(filePath)<<" bytes"<<endl;
}



int main () {
	FileManager file("pipi.txt");

	file.getFileSize();

	file.copyFile("klanila.txt");

return 0;}
