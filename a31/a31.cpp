#include <iostream>
#include <vector>

//na rotiso gpt gia constructors se templates typename T xoris vectors

using namespace std;



template<typename T>

class Stack{
	private:
		vector<T> elements;
	public:
		void push(const T&);
		void pop();

		int getSize() const;

};


template<typename T>
int Stack<T>::getSize() const{
	return elements.size();
}


template<typename T>
void Stack<T>::push(const T& element){
	elements.push_back(element);

}


template<typename T>
void Stack<T>::pop() {
	if (!elements.empty()) {
	elements.pop_back();
	} else {
	cerr << "Stack is empty! Cannot pop." << endl;
	}
}





int main () {

vector<int> vec;

vec.push_back(1);
vec.push_back(2);
vec.push_back(3);

Stack<int> s;
cout<<"hello"<<endl;

s.push(1);
s.push(1);
s.push(1);
s.push(1);

int x = s.getSize();

cout << x<< endl;

s.pop();

cout << s.getSize() << endl;




return 0;

}
