/*
Να γραφεί template κλάση η οποία θα παριστά ένα ορθογώνιο χώρο
τιμών δύο διαστάσεων (δισδιάστατο πίνακα). Το πλήθος των γραμμών και των
στηλών του χώρου θα ορίζεται κατά την δημιουργία του στιγμιότυπου της κλάσης.
Η κλάση θα παρέχει στον χρήστη της την ακόλουθη λειτουργικότητα:

Δημιουργία στιγμιότυπου συγκεκριμένων διαστάσεων και δημιουργία
στιγμιότυπου το οποίο θα είναι αντίγραφο άλλου στιγμιότυπου της ίδιας
κλάσης.

Εκχώρηση στιγμιότυπου σε άλλο στιγμιότυπο με χρήση του τελεστή “=”

Εκχώρηση τιμής σε συγκεκριμένη θέση και επιστροφή της τιμής
συγκεκριμένης θέσης.

Αντικατάσταση όλων των τιμών μιας γραμμής με νέες (οι νέες τιμές δίνονται
ως παράμετρος)

Για την υλοποίηση της template κλάσης δεν θα χρησιμοποιηθεί η template κλάση
“vector”. Να επιδειχθεί η λειτουργία της κλάσης με τιμές τύπου δεδομένων της
επιλογής του εξεταζόμενου.

Το πρόγραμμα θα αναπτυχθεί, στο σύνολό του, σε ένα ενιαίο .cpp αρχείο το οποίο θα
αναρτηθεί στο eclass.



*/

#include <iostream>
using namespace std;

template<typename T>
class RectangularSpace{
	private:
		//pointer to a pointer
		//creating an array of pointers where each pointer points to another array of type T
		T** data;
		int rows;
		int cols;
		void allocateSpace();
		void deallocateSpace();
	public:
		RectangularSpace(const int&, const int&);
		RectangularSpace(const RectangularSpace&);
		RectangularSpace& operator=(const RectangularSpace&);
		~RectangularSpace();
		void addToCertainPosition(const int ,const int ,const T);
		void replaceRows(const int ,const T*);

};


template<typename T>
void RectangularSpace<T>::replaceRows(const int r, const T* newRow) {
	if (r >= 0 && r < rows) {
		for (int j = 0; j < cols; ++j) {
			data[r][j] = newRow[j];
 	}
	} else {
		cout << "Invalid row index!" << endl;
	}
}


template<typename T>
void RectangularSpace<T>::addToCertainPosition(const int r, const int c, const T element){
	if (r<rows && r>=0 && c<cols && c>=0)
	{
		data[r][c]=element;
	}

cout<<"data["<<r<<"]["<<c<<"]: "<<element;
}


template <typename T>
RectangularSpace<T>& RectangularSpace<T>::operator=(const RectangularSpace& other){
	if (this==&other){return *this;}

	deallocateSpace();
	rows = other.rows;
	cols = other.cols;

	allocateSpace();
	for (int i=0;i<rows;++i){
		for (int j=0;j<cols;++j){
			data[i][j]=other.data[i][j];
		}
	}
return *this;
}

template <typename T>
RectangularSpace<T>::~RectangularSpace(){deallocateSpace();}

template<typename T>
RectangularSpace<T>::RectangularSpace(const RectangularSpace& other){
	allocateSpace();
	rows = other.rows;
	cols = other.cols;
	for (int i=0;i<rows;++i){
		for (int j=0;j<cols;++j){
			data[i][j]=other.data[i][j];
		}
	}

}


template<typename T>
RectangularSpace<T>::RectangularSpace(const int& r, const int& c):rows(r),cols(c){
	allocateSpace();
}


template<typename T>
void RectangularSpace<T>::deallocateSpace(){
	for (int i=0 ;i <rows;++i){
		delete[] data[i];
	}
	delete[] data;
}

template <typename T>
void RectangularSpace<T>::allocateSpace(){
	//Create an array of size rows (this array can hold an array inside it, size of column
	data = new T*[rows];
	for (int i=0;i<rows;++i){
		data[i] = new T[cols];
	}
}




int main () {


	RectangularSpace<int> matrix(3, 3); // 3x3 matrix
	// Adding values
	matrix.addToCertainPosition(0, 0, 1);
	matrix.addToCertainPosition(0, 1, 2);
	matrix.addToCertainPosition(0, 2, 3);

	matrix.addToCertainPosition(1, 0, 4);
	matrix.addToCertainPosition(1, 1, 5);
	matrix.addToCertainPosition(1, 2, 6);

	matrix.addToCertainPosition(2, 0, 7);
	matrix.addToCertainPosition(2, 1, 8);
	matrix.addToCertainPosition(2, 2, 9);

	// Replacing a row
	int newRow[3] = {10, 11, 12};
	matrix.replaceRows(1, newRow);


	// Copying the matrix
	RectangularSpace<int> matrixCopy(matrix);

	// Assigning one matrix to another
	RectangularSpace<int> matrixAssigned(3, 3);
	matrixAssigned = matrix;

	return 0;
};


