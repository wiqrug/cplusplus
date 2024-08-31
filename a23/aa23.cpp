#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class BigInt{
	private:
		vector<int> digits;
	public:
		BigInt(int);
		BigInt(const string&);
		BigInt(const BigInt&);
		void display()const;
		bool operator>(const BigInt&)const;
		BigInt();
		BigInt operator+(const BigInt&) const;

};


int main () {

BigInt i1(50);
BigInt i3("5");
BigInt i2=i1;
i2 = i2+ i2;
i2.display();
cout<<"-----------------------------------------"<<endl;

bool isGreaterThan = i1>i2;
cout<<isGreaterThan<<endl;

return 0;}


BigInt::BigInt(){}


BigInt BigInt::operator+(const BigInt& other)const{
	vector<int> result;
	int carry =0 ;
	//iterators that are pointing to the last element of each vector
	auto it1 = digits.rbegin();
	auto it2 = other.digits.rbegin();
	while (it1!=digits.rend() || it2!=other.digits.rend() || carry){
		int sum = carry;
		if (it1!=digits.rend()){
			sum += *it1;
			++it1;
		}


		if (it2!=other.digits.rend()){
			sum +=*it2;
			++it2;
		}

		carry = sum/10;

		result.push_back(sum%10);
	}

	reverse(result.begin(),result.end());

	BigInt rresult;
	rresult.digits = result;
return rresult;
}




bool BigInt::operator>(const BigInt& other)const{
	if(digits.size()>other.digits.size()){return true;}
	if(digits.size()<other.digits.size()){return false;}

	for (int i=0;i<digits.size();i++){
		if (digits[i] > other.digits[i]){return true;}
		if (digits[i] < other.digits[i]){return false;}
	}
return false;
}


void BigInt::display() const{
	for(const auto& digit:digits){
		cout<<digit;
	}

}

BigInt::BigInt(const BigInt& other){
	digits=other.digits;				//so simple
}


BigInt::BigInt(const string& s){
	int num =stoi(s);
	if (num == 0) {
		digits.push_back(0);
	} else {
		while (num > 0) {
 			digits.push_back(num % 10);  // Extract last digit
			num = num / 10;              // Remove last digit
		}
		reverse(digits.begin(),digits.end());

	}

}

BigInt::BigInt(int num) {
	if (num == 0) {
		digits.push_back(0);
	} else {
		while (num > 0) {
 			digits.push_back(num % 10);  // Extract last digit
			num = num / 10;              // Remove last digit
		}
		reverse(digits.begin(),digits.end());
	}
}


