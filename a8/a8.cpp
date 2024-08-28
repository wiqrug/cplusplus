#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;



template <typename T>
class Stack {
	private:
		vector<T> t;
	public:
		void push(T);
		void pop();
		int size() const;

		void saveStackToFile();

};

class Dummy{
	private:
		double x;
		char* ch;
	public:
		Dummy(double, const char*);
		~Dummy();
		Dummy(const Dummy&);
		Dummy& operator=(const Dummy&);
		double getX() const{return x;}
		const char* getCh() const {return ch?ch:"nullptr";}
};


int main() {
    // Create a stack of Dummy objects
    Stack<Dummy> d;

    // Push some Dummy objects onto the stack
    d.push(Dummy(3.14, "Hello"));
    d.push(Dummy(2.71, "World"));
    d.push(Dummy(1.41, "Stack"));

    // Print the size of the stack
    cout << "Stack size: " << d.size() << endl;

    // Save the stack to a file
    d.saveStackToFile();

    // Pop an element from the stack
    d.pop();

    // Print the size of the stack after popping
    cout << "Stack size after pop: " << d.size() << endl;

    // Save the stack to a file again after popping
    d.saveStackToFile();

    return 0;
}


Dummy& Dummy::operator=(const Dummy& other) {
    if (this == &other) {
        return *this;  // Handle self-assignment
    }

    delete[] ch;  // Correct syntax for deleting an array

    x = other.x;
    if (other.ch) {
        ch = new char[strlen(other.ch) + 1];  // Allocate memory
        strcpy(ch, other.ch);  // Copy the string
    } else {
        ch = nullptr;  // Handle case where other.ch is nullptr
    }

    return *this;  // Return *this to allow assignment chaining
}

Dummy::Dummy(const Dummy& other){
	x=other.x;
	if (other.ch){
		ch = new char[strlen(other.ch)+1];
		strcpy(ch,other.ch);
	}

}

Dummy::~Dummy(){delete[] ch;}

Dummy::Dummy(double d, const char* c){
	x=d;
	if (c){
	ch = new char[strlen(c)+1];
	strcpy(ch,c);
	}
	else{ch=nullptr;}
}


ostream& operator<<(ostream& os, const Dummy& d) {
    os << "Dummy(" << d.getX() << ", " << d.getCh() << ")";
    return os;
}


template <typename T>
void Stack<T>::saveStackToFile() {
	ofstream MyFile("filename.txt");

	if (!MyFile.is_open()) {
		cerr << "Failed to open file." << endl;
		return;
	}
	for (const auto& element: t){MyFile<<element<< " ";}



	MyFile.close();
}


template <typename T>
void Stack<T>::push(T tt){
	t.emplace_back(tt);
}

template<typename T>
void Stack<T>::pop() {
	if (!t.empty()) {
		t.pop_back();
	}
}


template<typename T>
int Stack<T>::size() const{
	return t.size();
}

