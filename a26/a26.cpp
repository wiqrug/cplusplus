#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


class Product{
	private:
		char* password;
		string description;
		float value;
	public:
		Product(const char*, const string,const float);
		~Product();
		Product();

		Product(const Product&);
		Product& operator=(const Product&);
		bool operator>(const Product&);
};




vector<Product> readProductsFromFile(const string& filename){
	vector<Product> products;
	ifstream file(filename);

	if (file.is_open()){
		string line;
		while(getline(file,line)){
			stringstream ss(line);
			string password,description,valueStr;
			getline(ss,password,';');
			getline(ss,description,';');
			getline(ss,valueStr,';');
			float value = stof(valueStr);

			Product product(password.c_str(),description,value);
			products.push_back(product);
		}
	file.close();
	}
	else{cerr<<"failed to open file"<<endl;}
	return products;

}



Product::Product(){
	password = new char[1];
	password[0] = '\0';
	description="";
	value=0;
}

Product::~Product(){delete[] password;}


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
	description=other.description;
	value=other.value;

	password = new char[strlen(other.password)+1];
	strcpy(password,other.password);

}


Product& Product::operator=(const Product& other) {
	if (this==&other){return *this;}

	delete[] password;
	description = other.description;
	value = other.value;

	password = new char[strlen(other.password)+1];
	strcpy(password,other.password);

return *this;
}


int main () {




cout<<"Hello"<<endl;
return 0;

}
