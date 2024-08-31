#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;

template <typename T>
class BinaryArrayManager{
	private:
		T* arr;
		int size;
	public:
		BinaryArrayManager(const T*,const int);

		void readFromBinary(const string&);
		void saveToBinary(const string&)const;
		void display()const;

};


template<typename T>
void BinaryArrayManager<T>::display() const{
	for (int i=0;i<size;i++){
		cout<<arr[i]<<endl;
	}

}


int main () {

int arr[] = {1,2,3,4,5};
int size = 5;

BinaryArrayManager b(arr,size);

b.saveToBinary("bin");

b.readFromBinary("bin");

b.display();
return 0;}



template<typename T>
void BinaryArrayManager<T>::readFromBinary(const string& fname){
	ifstream ifs;
	ifs.exceptions(ifstream::failbit | ifstream::badbit);
	try {
		ifs.open(fname,ios::binary);

		//This moves the pointer to the end of the file in order to determine its length
		ifs.seekg(0,ios::end);
		//returns the current position of the file pointer. Tell g tells what seekg seeks
		streamsize  fileSize = ifs.tellg();
		//Moving the pointer again to the beginning of the file
		ifs.seekg(0,ios::beg);
		//Determine the size
		int newSize = fileSize/sizeof(T);

		T* newArr = new T[newSize];

		ifs.read((char*)newArr,fileSize);
		ifs.close();

		delete[] arr;
		arr = newArr;
		size = newSize;
	}
	catch(exception&e ){
		cerr<<"There was an error opening the file ig"<<endl;
		throw;
	}

}


template<typename T>
BinaryArrayManager<T>::BinaryArrayManager(const T* values, const int s){
	size=s;
	arr = new T[size];
	for (int i=0;i<s;i++){
		arr[i] = values[i];
	}
}

template<typename T>
void BinaryArrayManager<T>::saveToBinary(const string& fname)const{
	ofstream ofs;

	ofs.exceptions(ofstream::badbit | ofstream::failbit);
	try{
		ofs.open(fname,ios::binary);
		ofs.write((char*)arr,size*sizeof(T));
		ofs.close();
	}catch (exception& e ){cerr<<"error"<<endl;
		throw;
	}
}
