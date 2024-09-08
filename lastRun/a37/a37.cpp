#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <exception>
#include <vector>
using namespace std;


class FileManager{
	public:
		void copyFile(const string&,const string&);
		void saveIntToBinary( const vector<int>&, const string&);
		vector<double> readAndSaveDoubles(const string&);

};



int main () {

FileManager fmanager;
vector<int> numbers = {1,2,4,5,6,7};
try{
	fmanager.copyFile("tempfile.txt","webfile.txt");
	fmanager.saveIntToBinary(numbers,"binary.bin");
vector<double> d=fmanager.readAndSaveDoubles("doubles.txt");

for (const auto& doubles:d){
	cout<<doubles<<endl;
}

}catch (exception& e){
cout<<e.what()<<endl;
}



return 0;
}



vector<double> FileManager::readAndSaveDoubles(const string& fname){
	vector<double> numbers;
	double number;
	ifstream ifs(fname);
	if (!ifs.is_open()){
		throw logic_error("could not open file");
	}

	string text;
	while(getline(ifs,text)){

		try{		number = stod(text);
				numbers.push_back(number);

		}
		catch(exception& e){cerr<<e.what();}
	}
return numbers;
}



void FileManager::saveIntToBinary(const vector<int>& numbers, const string& dest){
	ifstream checkExist(dest);
	if (checkExist.is_open()){
		checkExist.close();
		throw logic_error("Filename already exists");
		return ;
	}
	ofstream os(dest,ios::binary);
	for (const auto& number:numbers){
		os.write((char*)&number,sizeof(int));
	}

}


void FileManager::copyFile(const string& source, const string& dest){
	ifstream checkExist(dest);

	if(checkExist.is_open()){
		checkExist.close();
		throw logic_error ("File already exists");
		return;
	}

	ofstream ofs(dest);
	ifstream ifs(source);

	if (ifs.is_open() && ofs.is_open())
	{
		string text;
		while (getline(ifs,text)){
			ofs<<text<<endl;
		}

	}


}
