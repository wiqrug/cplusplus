/*
Ανάκτηση αντιγράφου του στοιχείου που βρίσκεται σε θέση του Vector. Η
θέση προσδιορίζεται με την χρήση του τελεστή “[ ]”

Να γραφεί πρόγραμμα το οποίο θα επιδεικνύει την λειτουργία της κλάσης MyVector
με αντικείμενα μίας κλάσης της επιλογής σας. Για την υλοποίηση των προηγουμένων
δεν θα χρησιμοποιηθεί κάποια κλάση της STL. Ο χειρισμός των λαθών θα γίνεται με
exceptions
*/


#include <iostream>


using namespace std;


template<typename T>
class Vector {
	private:
		unsigned int size;
		T* elements;

	public:
		void push (const T&);
		Vector();
		~Vector();
		void display() const;

		T operator[] (const unsigned int&) const;

};

template<typename T>
T Vector<T>::operator[](const unsigned int& index) const {
    if (index >= size) throw "Index out of bounds";
    return elements[index];
}

template<typename T>
void Vector<T>::display() const{
	for (unsigned int i=0;i<size;i++){cout<<"element "<<i<<"is: "<<elements[i]<<endl;}

}


template<typename T>
Vector<T>::Vector(){
	elements=nullptr;
	size=0;
}

template<typename T>
Vector<T>::~Vector() {
	delete[] elements;
}

template<typename T>
void Vector<T>::push(const T& t){
	T* temp = new T[size+1];
	for (int i=0;i<size;i++){
		temp[i] = elements[i];
	}
	temp[size+1]=t;

	delete[] elements;
	elements=temp;
	size++;
}


int main () {
	Vector<int> v;
	v.push(1);
	v.push(1);
	v.push(1);

	v.display();
return 0;
}




