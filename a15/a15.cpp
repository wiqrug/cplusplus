#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>
using namespace std;


template <typename T>
class MyVector{
	private:
		unsigned int size;
		T* vector;
	public:
		MyVector();
		~MyVector();
		void push (const T&);
		void remove (const unsigned int&);
		T operator[](const unsigned int& ) const;
		void print() const;
};

template <typename T>
MyVector<T>::~MyVector(){delete[] vector;}


template <typename T>
MyVector<T>::MyVector(){
	vector=nullptr;
	size=0;
}

template<typename T>
void MyVector<T>::print() const{
	for (int i=0; i<size; i++) {
		cout<<"Vector["<<i<<"]"<<"="<<vector[i]<<endl;
	}

}




template <typename T>
void MyVector<T>::push(const T& element) {
	T* new_vector = new T[size+1];

	for (int i=0;i<size;i++){
		new_vector[i] = vector[i];
	}

	delete[] vector;
	vector = new_vector;

	vector[size] = element;
	++size;


}



template<typename T>
void MyVector<T>::remove (const unsigned int& pos){
   if (pos >= size) {
        std::cerr << "Error: Invalid position for removal." << std::endl;
        return;
    }

	int flag=0;
	T* new_vector = new T[size-1];

	for (int i=0;i<size;i++){
		if (i!=pos){
			if (flag!=1){new_vector[i] = vector[i];}
			if (flag==1){new_vector[i-1] = vector[i];}
		}
		if (i==pos){flag=1;}
	}
	delete[] vector;
	vector=new_vector;
	--size;
}


template<class T> T MyVector<T>::operator[](const
unsigned int& index) const {
if (index >= size) throw "Index out of bound!";
return vector[index];
}



class MyClass {
private:
    char* name;
    float value;

public:
    // Default constructor
    MyClass() : name(nullptr), value(0.0f) {}

    // Parameterized constructor
    MyClass(const char* n, float v) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        value = v;
    }

    // Copy constructor
    MyClass(const MyClass& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        value = other.value;
    }

    // Destructor
    ~MyClass() {
        delete[] name;
    }

    // Assignment operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            value = other.value;
        }
        return *this;
    }

    // Getter methods to allow external access for operator<<
    const char* getName() const { return name; }
    float getValue() const { return value; }

    void print() const {
        std::cout << "Name: " << (name ? name : "Unnamed") << ", Value: " << value << std::endl;
    }
};
// Define the operator<< outside the class, without friend
ostream& operator<<(ostream& os, const MyClass& obj) {
    os << "Name: " << (obj.getName() ? obj.getName() : "Unnamed") << ", Value: " << obj.getValue();
    return os;
}

int main() {
    try {
        MyVector<MyClass> v;

        // Pushing MyClass objects to the vector
        v.push(MyClass("First", 1.0f));
        v.push(MyClass("Second", 2.0f));
        v.push(MyClass("Third", 3.0f));
        v.push(MyClass("Fourth", 4.0f));

        std::cout << "Pushed 4 items:" << std::endl;
        v.print();

        // Accessing elements
        std::cout << "Accessing element at index 1:" << std::endl;
        v[1].print();

        // Removing an element
        v.remove(1);
        std::cout << "Removed item at index 1:" << std::endl;
        v.print();

        // Attempting to access an out-of-bounds index to trigger an exception
        std::cout << "Accessing element at an invalid index:" << std::endl;
        v[10].print();

    } catch (const char* msg) {
        std::cerr << "Exception: " << msg << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << std::endl;
    }

    return 0;
}
