#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <typeinfo>
#include <algorithm>
using namespace std;


class FileManager{
	private:
		string filename;
	public:
		FileManager(const string&);
		void copyFileToDest(const string&)const;
		streampos getFileSize()const;
		void invertedCopy(const string&)const;

};

void FileManager::invertedCopy(const string& dest) const
{
	ifstream checkDest(dest);
	if (checkDest.is_open()){
		checkDest.close();

		throw logic_error("Filename already exists");
		return ;
	}

	ifstream ifs(filename, ios::binary | ios::ate);
	ofstream ofs(dest,ios::binary);

   // Get the size of the file
    streampos fileSize = ifs.tellg();

    // Loop through the file from end to beginning
    for (streampos i = fileSize - 1; i >= 0; --i) {
        ifs.seekg(i);          // Move the "get" pointer to the position i
        char byte;
        ifs.read(&byte, 1);    // Read one byte from that position
        ofs.write(&byte, 1);   // Write that byte to the destination file
    }

    // Close the files
    ofs.close();
    ifs.close();

}





int main () {

FileManager("temp");


return 0;
}


streampos FileManager::getFileSize() const{
	ifstream ifs(filename, ios::binary | ios::ate);

	if (!ifs.is_open()){cerr<<"Error"<<endl;return -1;}

	streampos fileSize = ifs.tellg();
	ifs.close();

	return  fileSize;

}



FileManager::FileManager(const string& fname):filename(fname){}

void FileManager::copyFileToDest(const string& dest)const{
	ifstream checkExist(dest);
	if (checkExist.is_open()){throw logic_error("filename already exists"); checkExist.close();return; }

	ifstream ifs(filename);
	ofstream ofs(dest);
	if(ifs.is_open() && ofs.is_open()){
		string text;
		while(getline(ifs,text)){
		ofs<<text<<endl;
	}
	}


}
