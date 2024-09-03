/*
Να δημιουργηθούν οι απαραίτητες κλάσεις για να περιγραφούν οι
οντότητες “Ποδήλατο” και “Ηλεκτρικό Ποδήλατο” για ένα κατάστημα που πουλάει
σχετικά προϊόντα. Κάθε κλάση θα έχει, συνολικά, 2 με 3 χαρακτηριστικά της επιλογής
του εξεταζόμενου / ης .

Να δημιουργηθεί ενιαία λίστα (list) αντικειμένων που θα περιλαμβάνει και ποδήλατα
και ηλεκτρικά ποδήλατα.

Να γραφεί συνάρτηση που θα υπολογίζει τον μέσο όρο τιμής των ηλεκτρικών
ποδηλάτων.

Να υλοποιηθεί ότι είναι απαραίτητο ώστε η εντολή: XXX << YYY; (όπου ΧΧΧ ένα
στιγμιότυπο της κλάσης ostream και ΥΥΥ μία ενιαία λίστα με ποδήλατα (ηλεκτρικά και
μη) να τυπώνει, από μία φορά, ολες τις μάρκες ποδηλάτων (ηλεκτρικών και μη) που
πωλούνται στο κατάστημα.

Να γραφεί κύριο πρόγραμμα το οποίο θα επιδεικνύει την λειτουργία των
προηγούμενων.

*/
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Bike{
	protected:
		int price;
		string brand;
	public:
		Bike();
		virtual ~Bike();
		Bike(const int&, const string&);
		virtual bool isElectric()const;
		virtual void display() const;
		int getPrice()const;
		void displayBrand()const;
};




class ElectricBike:public Bike{
	private:
		bool hasEfficientCharger;
	public:
		ElectricBike();
		ElectricBike(const int&, const string&, const bool&);
		bool isElectric()const override;
		void display() const override;
};

void display(list<Bike*>& bikes);

list<Bike*> generateBikes();

int calculateAverage(const list<Bike*>& );


ostream& operator<<(ostream&,const list<Bike*>&);



int main () {

list<Bike*> bikes = generateBikes();

display(bikes);
cout<<"----------------------------"<<endl;
cout<<calculateAverage(bikes)<<endl;


cout<<bikes<<endl;

for (const auto& bike:bikes){
	delete bike;
}
return 0;

}


ostream& operator<<(ostream& os,const list<Bike*>& bikes){
	for (const auto bike:bikes){
		bike->displayBrand();
	}
return os;
}


int calculateAverage(const list<Bike*>& bikes){
	int c=0;
	int sum=0;
	for (const auto& bike:bikes){
		if (bike->isElectric()){
			++c;
			sum+=bike->getPrice();
		}

	}
if (c>0){return sum/c;}
else{return 0;}
}



void display(list<Bike*>& bikes){
	for (const auto& bike:bikes){
		bike->display();
	}
}


list<Bike*> generateBikes(){

	list<Bike*> bikes;
	bikes.push_back(new Bike(100,"daytona"));
	bikes.push_back(new Bike(200,"toyota"));
	bikes.push_back(new Bike(300,"lambo"));
	bikes.push_back(new Bike(400,"fiat"));
	bikes.push_back(new ElectricBike(400,"porsche",true));
	bikes.push_back(new ElectricBike(600,"datsu",true));
	bikes.push_back(new ElectricBike(800,"ferrari",true));

return bikes;

}

void Bike::displayBrand()const{
	cout<<"------------------------------"<<endl;
	cout<<brand<<endl;
}

int Bike::getPrice() const{
	return price;
}


void Bike::display() const{
	cout<<"Brand: "<<brand<<" | price: "<<price<<" | is electric? -> "<<(this->isElectric()?"yes":"no")<<endl;
}


bool Bike::isElectric()const{return false;}

Bike::Bike():price(0),brand(""){}


Bike::~Bike()=default;

Bike::Bike(const int& p, const string& c):price(p),brand(c){}





ElectricBike::ElectricBike():Bike(),hasEfficientCharger(false){}

ElectricBike::ElectricBike(const int& p ,const string& c, const bool& h):Bike(p,c),hasEfficientCharger(h){}

bool ElectricBike::isElectric() const {return true;}

void ElectricBike::display() const{
	cout<<"Brand: "<<brand<<" | price: "<<price<<" | is electric? -> "<<(this->isElectric()?"yes":"no")<<endl;
}


