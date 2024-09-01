#include <iostream>
#include <string>
#include <list>
using namespace std;


class Animal{
	protected:
		string name;
	public:
		Animal();
		Animal(const string&);
		virtual ~Animal();
		virtual bool isFish() const=0;
		virtual bool isBird() const=0;
		virtual void display() const=0;
};


class Bird:public Animal {
	private:
		bool hasBigWings;
	public:
		Bird();
		Bird(const string&, const bool&);
		bool isFish() const override;
		bool isBird() const override;
		void display() const override;
};

void Bird::display() const{
	cout<<"Name: "<<name<<" Does it have big wings? "<< hasBigWings<<endl;
}



class Fish:public Animal{
	private:
		bool isTasty;
	public:
		Fish();
		Fish(const string&,const bool&);
		bool isFish() const override;
		bool isBird() const override;
		void display() const override;
};

void Fish::display() const {
	cout<<"Name: "<<name<<endl<<"Is it tasty? "<<(isTasty?"yes":"no")<<endl;
}


ostream& operator<<(ostream& os, list<Animal*>& animals){
	for (const auto& animal:animals){
		if (animal->isFish()){
			animal->display();
		}
	}
return os;
}



int main () {
list<Animal*> l;

l.push_back(new Bird("er",1));
l.push_back(new Fish("er",1));
l.push_back(new Bird("er",1));


cout<<l<<endl;


return 0;
}

Fish::Fish(){}
Fish::Fish(const string& n, const bool& i):Animal(n),isTasty(i){}

bool Fish::isBird() const {return false;}
bool Fish::isFish() const{return true;}


Bird::Bird(){}
Bird::Bird(const string& n, const bool& h):Animal(n),hasBigWings(h){}
bool Bird::isFish() const {return false;}
bool Bird::isBird() const{return true;}



Animal::Animal(){}
Animal::~Animal()=default;

Animal::Animal(const string& n):name(n){}
