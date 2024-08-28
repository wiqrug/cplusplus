#include <iostream>
#include <list>
#include <string>
#include <list>

using namespace std;


class Bike{
	protected:
		double cost;
		double length;
		string name;
	public:
		Bike(const string&,const double&,const double&);
		virtual ~Bike();
		virtual bool isNice() const;
		virtual string getName() const;
		double getCost() const;
		virtual bool isElectric()const;
};




class ElectricBike:public Bike{
	private:
		bool isFancy;
	public:
		ElectricBike(const string&,const double&,const double&,const bool&);
		bool isNice()const;
		string getName() const;
		bool isElectric() const override;
		double getCost() const;

};



void calculateAverageElectric(const list<Bike*>& bikes){
	int count=0;
	int sum=0;
	for (const auto& bike:bikes){
		if (bike->isElectric()){
		count++;
		sum+=bike->getCost();
		}

	}
	cout<<sum/count<<" on average"<<endl;
}



//overloading

ostream& operator<<(ostream& os, const list<Bike*>& bikes){
	for(const auto& bike:bikes){
		os<<bike->getName()<<endl;
	}
return os;
}





int main () {

list<Bike*> l;

l.push_back(new Bike("pipi",2,3));
l.push_back(new Bike("pipi",2,3));
l.push_back(new ElectricBike("lili",2,3,0));
l.push_back(new ElectricBike("ili",2,3,1));

cout<<l<<endl;


calculateAverageElectric(l);


return 0;
}





//Bike
Bike::Bike(const string& n,const double& c,const double& l):name(n),cost(c),length(l){}
Bike::~Bike()=default;
bool Bike::isNice() const{return false;}
string Bike::getName() const{return name;}
bool Bike::isElectric() const{return false;}
double Bike::getCost() const{return cost;}




//ElectricBike
ElectricBike::ElectricBike(const string& n, const double& c, const double& l,const bool& i):Bike(n,c,l),isFancy(i){}

bool ElectricBike::isNice() const{return true;}

string ElectricBike::getName() const {return name;}

bool ElectricBike::isElectric()const{return true;}
double ElectricBike::getCost()const{return cost;}


