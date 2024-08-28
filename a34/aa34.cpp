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
		virtual bool isFish()const =0;
		virtual string getName() const =0;

};



class Bird:public Animal{
	protected:
		bool hasLongWings;
	public:
		Bird(const string&,const bool&);
		bool isFish() const override;
		string getName() const override;

};


class Fish: public Animal {
	private:
		bool isTasty;
	public:
		Fish(const string&,const bool&);
		bool isFish() const override;
		string getName() const override;

};

ostream& operator << (ostream& os, const list<Animal*>& animals){
	for (const auto& animal:animals){
		if (animal->isFish()){
			os<<animal->getName()<<endl;
		}
	}

	return os;

}






int main () {

Bird* b1 = new Bird("petinos",false);

Fish* f1 = new Fish("gavros",false);

Fish* f2 = new Fish("lilik",true);





list<Animal*> f;
f.push_back(f1);
f.push_back(f2);

cout<<f<<endl;
for (auto& animal : f) {
	delete animal;
}
return 0;
}






//Animal


Animal::Animal(const string& n){
	name=n;
}


Animal::~Animal()=default;


//Fish
Fish::Fish(const string& s, const bool& i):Animal(s),isTasty(i){};

bool Fish::isFish() const {return true;}

string Fish::getName() const{return name;}



//Bird
Bird::Bird(const string& s, const bool& h): Animal(s),hasLongWings(h){};

bool Bird::isFish() const{return false;}

string Bird::getName() const{return name;}

