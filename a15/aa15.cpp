/*
α γραφεί template κλάση (MyVector) η οποία θα υλοποιεί τις
ακόλουθες λειτουργίες ενός vector:

Εισαγωγή ενός στοιχείου στο τέλος του Vector

Διαγραφή ενός στοιχείου από το Vector. Ορίζεται η θέση του στοιχείου που θα
διαγραφεί.

Ανάκτηση αντιγράφου του στοιχείου που βρίσκεται σε θέση του Vector. Η
θέση προσδιορίζεται με την χρήση του τελεστή “[ ]”

Να γραφεί πρόγραμμα το οποίο θα επιδεικνύει την λειτουργία της κλάσης MyVector
με αντικείμενα μίας κλάσης που θα περιέχει δύο attributes: ένα C-String και ένα float.

Για την υλοποίηση των προηγουμένων δεν θα χρησιμοποιηθεί η κλάση vector της
STL. Ο χειρισμός των λαθών θα γίνεται με exceptions

*/


#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

template<typename T>
class MyVector {
private:
	T* elements;
	int size;
	int capacity;

	void resize() {
		capacity *= 2;
		T* newElements = new T[capacity];
	for (int i = 0; i < size; ++i) {
		newElements[i] = elements[i];
	}
	delete[] elements;
	elements = newElements;
	}

public:
	MyVector(int initCapacity = 2) : size(0), capacity(initCapacity) {
		elements = new T[capacity];
	}

	~MyVector() {
		delete[] elements;
	}

	void addElement(const T& element) {
		if (size == capacity) {
			resize();
	}
		elements[size++] = element;
	}

	void deleteElement(const int& index) {
	if (index < 0 || index >= size) {
		throw out_of_range("Index out of bounds");
	}
	for (int i = index; i < size - 1; ++i) {
		elements[i] = elements[i + 1];
	}
		--size;
	}

	T& operator[](const int& index) {
	if (index < 0 || index >= size) {
		throw out_of_range("Index out of bounds");
	}
	return elements[index];
	}

	int getSize() const {
		return size;
    }
};

class MyClass {
private:
    char* name;
    float value;

public:
    MyClass(const char* n, float v) : value(v) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    MyClass(const MyClass& other) : value(other.value) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    MyClass& operator=(const MyClass& other) {
        if (this == &other) {
            return *this;
        }
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        value = other.value;
        return *this;
    }

    ~MyClass() {
        delete[] name;
    }

    void display() const {
        cout << "Name: " << name << ", Value: " << value << endl;
    }
};

int main() {
    MyVector<MyClass> myVector;

    myVector.addElement(MyClass("Object1", 1.1f));
    myVector.addElement(MyClass("Object2", 2.2f));
    myVector.addElement(MyClass("Object3", 3.3f));

    for (int i = 0; i < myVector.getSize(); ++i) {
        myVector[i].display();
    }

    myVector.deleteElement(1);

    cout << "\nAfter deletion:\n";
    for (int i = 0; i < myVector.getSize(); ++i) {
        myVector[i].display();
    }

    return 0;
}
