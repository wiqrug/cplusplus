#include <iostream>
#include <list>
#include <string>


using namespace std;

class Animal{
	protected:
		string name;
	public:
		Animal(const string&);
		virtual ~Animal();

		virtual string getName() const=0;
		virtual bool isFish() const=0;

};



class Bird:public Animal{
	private:
		string wingSpan;
	public:
		Bird(const string&,const string&);
		string getName() const override;
		bool isFish() const override;

		string getWingSpan() const;
};



class Fish: public Animal{
	private:
		string habitat;
	public:
		Fish (const string&,const string&);
		string getName() const override;
		bool isFish() const override;
		string getHabitat() const;
};



//Animal
Animal::Animal(const string& n){name=n;}

Animal::~Animal()=default;



//Bird
Bird::Bird(const string& n, const string& w): Animal(n), wingSpan(w){}

string Bird::getName() const{
	return name;
}


bool Bird::isFish() const{return false;}

string Bird::getWingSpan()const{return wingSpan;}




//Fish
Fish::Fish(const string& n, const string& h):Animal(n),habitat(h){}

string Fish::getName()const {return name;}

bool Fish::isFish() const {return true;}

string Fish::getHabitat() const {return habitat;}



//overload operator


ostream& operator<<(ostream& os, const list<Animal*>& animals) {
	for (const auto& animal : animals) {
	if (animal->isFish()) {
	os << animal->getName() << endl;
	}
	}
	return os;
}

int main (){

list <Animal*> animals;

animals.push_back(new Bird("Sparrow", "15cm"));
animals.push_back(new Fish("Salmon", "Freshwater"));
animals.push_back(new Bird("Eagle", "2m"));
animals.push_back(new Fish("Clownfish", "Saltwater"));

cout << "Fish in the list:" << endl;
cout << animals;

for (auto& animal : animals) {
	delete animal;
}

return 0;

}
