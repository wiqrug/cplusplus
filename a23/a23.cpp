#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class BigInt{
	private:
		vector<int> digits;
	public:
		BigInt();
		BigInt(const int&);
		BigInt(const string&);
		BigInt(const BigInt&);
		BigInt& operator=(const BigInt&);
		string toString() const;
		bool operator>(const BigInt&);
		BigInt operator++();
		BigInt operator+(const BigInt&);


};
BigInt::BigInt(){digits.push_back(0);}

BigInt BigInt::operator+(const BigInt& other){
	BigInt result;
	int carry = 0;

	int maxSize = max(digits.size(), other.digits.size());
	result.digits.resize(maxSize);

	int thisIndex = digits.size() - 1;
	int otherIndex = other.digits.size() - 1;
	int resultIndex = maxSize - 1;

	while (resultIndex >= 0) {
	int thisDigit = thisIndex >= 0 ? digits[thisIndex] : 0;
	int otherDigit = otherIndex >= 0 ? other.digits[otherIndex] : 0;

	int sum = thisDigit + otherDigit + carry;
	result.digits[resultIndex] = sum % 10;
	carry = sum / 10;

	--thisIndex;
	--otherIndex;
	--resultIndex;
	}

	if (carry > 0) {
	result.digits.insert(result.digits.begin(), carry);
	}

	return result;
}

BigInt BigInt::operator++() {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
        digits[i] += carry;
        if (digits[i] == 10) {
            digits[i] = 0;
            carry = 1;
        } else {
            carry = 0;
            break;
        }
    }
    if (carry) {
        digits.insert(digits.begin(), 1);
    }
    return *this;
}



bool BigInt::operator>(const BigInt& other) {

	if (digits.size()>other.digits.size()) {return true;}
	if (digits.size()<other.digits.size()) {return false;}

	for (int i=0; i<digits.size(); i++ ) {
		if (digits[i]!= other.digits[i]){
			return digits[i] > other.digits[i];
		}
	}

	return false;
}


string BigInt::toString() const{
	string fullNumber;

	for (const auto& digit:digits){
		fullNumber.append(to_string(digit));
	}

	return fullNumber;


}


BigInt& BigInt::operator=(const BigInt& other) {
	if (this != &other){
		digits=other.digits;
	}
	return *this;

}

BigInt::BigInt(const BigInt& other){
	digits=other.digits;
}

BigInt::BigInt(const int& number){
	string numb = to_string(number);
	for (const auto& digit:numb){
		int intDigit = digit - '0';
		digits.emplace_back(intDigit);
	}
}


BigInt::BigInt(const string& number){
	for (const auto& digit:number){
		int intDigit = digit - '0';
		digits.emplace_back(intDigit);
	}

}



int main (){

	BigInt v("12345");

	BigInt v1("1");
	BigInt g(v);

	BigInt o(12345);

	o=g;

	string result = o.toString();
	cout<<"result is "<<result<<endl;

	cout<<"Test operator >" << endl;
	bool isGreaterthan = v>o;
	cout<<isGreaterthan<<endl;

	bool isgt = o>v1;
	cout<<isgt<<endl;

return 0;
}




