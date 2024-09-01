#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;



class BigInt2{
	private:
		vector<int> number;
	public:
		BigInt2();
		BigInt2(int);

		void display() const;
		BigInt2& operator++();
		BigInt2 operator+(const int&)const;
		int castToInt()const;

		BigInt2 operator+(const BigInt2&) const;
};

BigInt2 BigInt2::operator+(const BigInt2& other) const{
	string nu1,nu2;
	for (const auto& digit:number){
		nu1+=to_string(digit);
	}
	for (const auto& digit:other.number){
		nu2+=to_string(digit);
	}
	int res1 = stoi(nu1);
	int res2 = stoi(nu2);
	int total = res1 +res2;

return BigInt2(total);
}

int BigInt2::castToInt()const{
	string nu;
	for (const auto& digit:number){
		nu+=to_string(digit);
	}
	int result = stoi(nu);
return result;
}


BigInt2 BigInt2::operator+(const int& integer)const{
	int res1 = this->castToInt();
	res1=res1+integer;

return BigInt2(res1);
}




ostream& operator<<(ostream& os, const BigInt2& integer)
{
	integer.display();
return os;
}



void BigInt2::display() const{
	for (const auto& digit:number){
		cout<<digit;
	}

}


BigInt2& BigInt2::operator++(){
	reverse(number.begin(),number.end());

	int carry =1;

	for (auto& digit:number){
		digit=carry+digit;
		if (digit>=10){digit = digit%10;}
		else{carry=0;}
	}
	if (carry>=1){
		number.push_back(1);
	}



	reverse(number.begin(),number.end());


return *this;
}





//i need to remember how i did this constructor
BigInt2::BigInt2(int n) {
	if (n == 0) {
		number.push_back(0);
	} else {
		while (n > 0) {
		number.push_back(n % 10);
			n = n / 10;
		}
		reverse(number.begin(), number.end());
	}
}
BigInt2::BigInt2(){
	number.push_back(0);
}




int main() {
	BigInt2 t(999999);  // Initialize a BigInt2 object with a value
	++t;                // Increment the BigInt2 object (using your overloaded ++ operator)
	t.display();        // Display the value of t
	cout << endl;

	t = t + 1;          // Use the overloaded + operator to add 1 to t
	t.display();        // Display the result after addition
	cout << endl;

	BigInt2 t2 = t + 12345; // You can also add a larger number
	t2.display();           // Display the result
	cout << endl;

    return 0;
}
