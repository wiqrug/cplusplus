#include <iostream>
#include <string>
#include <cstring>
using namespace std;



class BigInt{
	private:
		string number;
	public:
		BigInt(const string&);
		BigInt(int);
		BigInt(const BigInt&);
		void display() const;

		const char* toCString() const;
		bool operator>(const BigInt&) const;
		string getNumber() const;
		BigInt operator+(const BigInt&)const;
		BigInt& operator++();
		BigInt& operator=(const BigInt&);

};







int main () {
BigInt numb(5);
BigInt secondNumb(10);


bool isGreaterThan = numb>secondNumb;

cout <<isGreaterThan<<endl;

++numb;
numb.display();
numb = numb+ numb;

numb.display();

cout<<numb.toCString()<<endl;

return 0;
}












BigInt& BigInt::operator=(const BigInt& other){
	number = other.number;

return *this;
}






BigInt BigInt::operator+(const BigInt& other)const
{
	int firstNumber = stoi(other.getNumber());
	int secondNumber = stoi(number);


	int result = firstNumber+secondNumber;

return BigInt(result);
}



BigInt& BigInt::operator++() {
	int value = stoi(number);
	value += 1;
	number = to_string(value);
	return *this;
}


string BigInt::getNumber() const{return number;}

bool BigInt::operator>(const BigInt& other)const{
	return number>other.number;
}





const char* BigInt::toCString() const{
	return number.c_str();
}



void BigInt::display() const{cout<<number<<endl;}


BigInt::BigInt(const string& other){
	for (const auto& o:other){
		if (o>='0' && o <='9'){
			number+=o;
		}
		else{
			cout<<"This is not an integer"<<endl;
			return;
		}
	}


}


BigInt::BigInt(int n){
	number = to_string(n);
}


BigInt::BigInt(const BigInt& other){
	number = other.number;
}
