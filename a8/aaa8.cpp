#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template<typename T>
class Stack{
	private:
		vector<T> elements;
	public:
		void push(const T&);
		void pop();
		int getSize() const;
		void display() const;
		void saveToFile(const string)const;

};



int main () {

Stack<int> t;
t.push(1);

t.pop();
t.push(2);
t.display();

cout<<t.getSize()<<endl;

t.saveToFile("lorem");



return 0;
}





template<typename T>
void Stack<T>::saveToFile(const string fname)const {
	ifstream ifs(fname);
	if (ifs.is_open()){
		cerr<<"Filename already exists, choose another one"<<endl;
		ifs.close();
		return;
	}
	else{
		ofstream ofs(fname);
		for (const auto& element:elements){
			ofs<<element<<endl;
		}
		ofs.close();
	}


}

template<typename T>
void Stack<T>::display() const{
	for (const auto& element:elements){
		cout<<element<<endl;
	}
}

template<typename T>
void Stack<T>::push(const T& element){
	elements.push_back(element);
}

template<typename T>
void Stack<T>::pop(){
	if(!elements.empty()){
		elements.erase(elements.begin()+elements.size()-1);

	}
}

template<typename T>
int Stack<T>::getSize()const{
	return elements.size();
}
