#include <iostream>
#include <vector>
using namespace std;




template<typename T>
class Stack{
	private:
		vector<T> elements;
	public:
		Stack();
		Stack(const T&);
		void push(const T&);
		void pop();
		void display() const;
		int getSize() const;
		vector<T> getElements()const;
};
template<typename T>
vector<T> Stack<T>::getElements()const{
	vector<T> v;
	for (const auto& element:elements){
	v.push_back(element);
	}
return v;
}

template<typename T>
Stack<T> copyStack(const Stack<T>& other){
	Stack<T> temp;
	for (const auto& item:temp.getElements()){
		temp.push(item);
	}

return temp;
}


int main () {
Stack<int> t;
t.push(1);
t.push(1);
t.push(1);
t.push(1);
t.pop();

t.display();


int size = t.getSize();

cout<<"size = "<<size<<endl;



Stack<int> p;

p = copyStack(t);
p.display();

return 0;}




template<typename T>
int Stack<T>::getSize() const{
	return elements.size();
}

template<typename T>
void Stack<T>::display() const{
	for (const auto& element:elements){
		cout<<element<<endl;
	}

}


template<typename T>
Stack<T>::Stack(){}

template<typename T>
Stack<T>::Stack(const T& element){
	elements.push_back(element);
}

template<typename T>
void Stack<T>::push(const T& element){
	elements.push_back(element);
}


template<typename T>
void Stack<T>::pop(){
	if (!elements.empty()){
		elements.pop_back();
	}

}



