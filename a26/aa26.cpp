/*
Να γραφεί κλάση προϊόντων (“Product”) με τα ακόλουθα χαρακτηριστικά:
Κωδικός (char *)
Περιγραφή (string)
Τιμή Μονάδας (float)
Η κλάση θα παρέχει στον χρήστη της την απαιτούμενη λειτουργικότητα ώστε να
μπορούν να υλοποιηθούν τα ακόλουθα ζητούμενα:
Να γραφεί συνάρτηση η οποία θα διαβάζει όλα τα προϊόντα από αρχείο κειμένου με γραμμογράφηση:
<Κωδικός>;<Περιγραφή>;<Τιμή Μονάδας> (ένα προϊόν ανά γραμμή) και θα τα επιστρέφει σε λίστα
Να γραφεί συνάρτηση η οποία θα διαγράφει από λίστα προϊόντων όλα τα
προϊόντα που έχουν συγκεκριμένο κόστος ανά μονάδα.
Να επιδειχθεί η λειτουργία των παραπάνω μέσω κατάλληλης main. Δεν χρειάζεται να
εισαχθούν δεδομένα από την standard είσοδο.
Το πρόγραμμα θα αναπτυχθεί, στο σύνολό του, σε ένα ενιαίο .cpp αρχείο το οποίο θα
αναρτηθεί στο eclass.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class Product{
	private:
		char* password;
		string description;
		float price;
	public:
		Product();
		Product(const char*,const string&, const float&);
		~Product();
		Product(const Product&);
		Product& operator= (const Product&);
		float getPrice()const;
		 void display()const;
};


float Product::getPrice()const{return price;}


// Function to delete products by price
vector<Product>& deleteByPrice(vector<Product>& products, float p) {
	auto it = products.begin();
	while (it != products.end()) {
		if (it->getPrice() == p) {
			it = products.erase(it);  // Remove product and update iterator
	} else {
		++it;
		}
	}
	return products;
}




vector<Product> products (const string& fname){
	ifstream ifs(fname);
	vector<Product> vec;
	if (ifs.is_open()){
		string text;
		while (getline(ifs,text)){
			stringstream ss(text);
			string password,description,price;
			getline(ss,password,';');
			getline(ss,description,';');
			getline(ss,price,';');

			int intPrice = stof(price);
			Product p(password.c_str(),description,intPrice);
			vec.push_back(p);
		}
	}
	else{cerr<<"Error opening file"<<endl;}
return vec;
}


int main () {
//testing empty constructor

Product emptyConstructor;
//testing argument constructor
Product argConstructor("iPhone","telephone",500);

//testing copy constructor
Product copyConstructor(argConstructor);


//testing = overload
emptyConstructor=copyConstructor;


//testing vector function
vector<Product> vec = products("products.txt");

for (const auto& item:vec){item.display();}







return 0;
}







void Product::display() const{
	cout<<"Password: "<<password<<" | ";
	cout<<"Description: "<<description<<" | ";
	cout<<"Price: "<<price<<endl;
	cout<<"----------------------------------------------"<<endl;
}



Product::Product(){
	description="";
	price=0;
	password = new char[1];
	password[0] = '\0';
}

Product::Product(const char* pass,const string& desc,const float& pr){
		description = desc;
		price = pr;
		if (pass){
			password = new char[strlen(pass)+1];
			strcpy(password,pass);
		}
		else{
			password = new char[1];
			password[0] = '\0';
		}

}


Product::~Product(){delete[] password;}

Product& Product::operator= (const Product& other){
	if (this == &other){return *this;}

	delete[] password;
	password = new char[strlen(other.password)+1];
	strcpy(password,other.password);

	description = other.description;
	price = other.price;

return *this;
}


Product::Product(const Product& other){
	description= other.description;
	price= other.price;

	password = new char[strlen(other.password)+1];
	strcpy(password,other.password);
}
