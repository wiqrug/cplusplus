#include <iostream>
#include <string>
#include <list>
using namespace std;

class Animal{
	protected:
		string name;
		double weight;
	public:
		Animal();
		Animal(const string&,const double&);
		virtual ~Animal();
		virtual bool isFish() const=0;
		virtual bool isBird() const=0;
		void displayName() const;
};



class Bird:public Animal{
	private:
		bool hasWings;
	public:
		Bird();
		Bird(const string&,const double&,const bool&);
		bool isFish() const override;
		bool isBird() const override;
};
 class Fish:public Animal{
	private:
		bool isTasty;
	public:
		Fish();
		Fish(const string&,const double&,const bool&);
		bool isFish() const override;
		bool isBird() const override;
};


list<Animal*> initializeAnimals();

ostream& operator<<(ostream&os, list<Animal*>&);

void handleMemory(list<Animal*>&);

int main () {
list<Animal*> animals = initializeAnimals();


cout<<animals<<endl;


handleMemory(animals);

return 0;
}

//Utils


list<Animal*> initializeAnimals(){
	list<Animal*> animals;
	animals.push_back(new Fish("Lionfish",30,false));
	animals.push_back(new Fish("Golden",40,true));
	animals.push_back(new Fish("Tsipoura",1,true));
	animals.push_back(new Bird("Chicken",3,true));
	animals.push_back(new Bird("Eagle",31,true));
	animals.push_back(new Bird("Pterosaur",321,true));



return animals;
}



ostream& operator<<(ostream& os, list<Animal*>& animals){
	for (const auto& animal:animals){
		if (animal->isFish()){animal->displayName();}
	}
return os;
}


void handleMemory(list<Animal*>& animals){
	for (auto& animal:animals){
		delete animal;
	}
}



//Animal class implementation
Animal::Animal():name(""),weight(0){}
Animal::Animal(const string& n, const double& w):name(n),weight(w){}
Animal::~Animal()= default;
void Animal::displayName()const{cout<<"Name is: "<<name<<endl;}

//Bird class implementation
Bird::Bird():Animal(),hasWings(false){}
Bird::Bird(const string& n,const double& w, const bool& h):Animal(n,w),hasWings(h){}

bool Bird::isFish()const{return false;}
bool Bird::isBird()const{return true;}

//Fish implementation
Fish::Fish():Animal(),isTasty(false){}
Fish::Fish(const string& n,const double& w, const bool& i):Animal(n,w),isTasty(i){}

bool Fish::isFish()const{return true;}
bool Fish::isBird()const{return false;}
