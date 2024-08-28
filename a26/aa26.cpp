#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;



class Product{
	private:
		char* password;
		string description;
		float value;


	public:
		Product();
		Product(const char*, const string, const float);
		Product(const Product&);
		~Product();
		Product& operator=(const Product&);
};


vector<Product> readFromFile(const string& filename){
	vector<Product> products;
	ifstream str(filename);


	if (str.is_open()){
	string line;
	while(getline(str,line)){
		stringstream ss(line);

		string password;
		string description;
		string value;
		getline(ss,password,';');
		getline(ss,description,';');
		getline(ss,value,';');
		float v = stof(value);
		Product product(password.c_str(),description,v);
		products.push_back(product);

	}
	str.close();
	}
	else{
		cerr<<"probably there was an error"<<endl;
	}

	return products;
}





Product& Product::operator=(const Product& other){
	if (this==&other){return *this;}

	delete[] password;
	description = other.description;
	value = other.value;
	password = new char[strlen(other.password)+1];
	strcpy(password,other.password);
	return *this;
}



Product::Product(){
	description="";
	value=0;

	password = new char[1];
	password[0] = '\0';

}

Product::Product(const char* p, const string d, const float v){
	description = d;
	value = v;

	if (p){
		password = new char[strlen(p)+1];
		strcpy(password,p);
	}
	else{
		password = new char[1];
		password[0] = '\0';
	}

}


Product::Product(const Product& other){
	description = other.description;
	value=other.value;
	password = new char[strlen(other.password)+1];
	strcpy(password,other.password);
}


Product::~Product(){delete[] password;}

int main () {
cout<<"Hello friends"<<endl;

return 0;

}
