/*
Δημιουργήστε την κλάση “ορθογώνιο παραλληλόγραμμο”. Το μήκος και
το πλάτος είναι ακέραιοι αριθμοί και ως attributes της κλάσης μπορούν να
χρησιμοποιηθούν μόνο δείκτες. Δημιουργήστε μία template συνάρτηση η οποία θα
ταξινομεί πίνακα οποιουδήποτε τύπου και χρησιμοποιήστε την για να ταξινομήσετε
πίνακα ορθογωνίων παραλληλογράμμων, κατά αύξουσα τάξη εμβαδού.
 */


#include <iostream>
#include <algorithm>


using namespace std;






class Rectangle{
	private:
		int* length;
		int* width;
	public:
		int area() const;
		Rectangle(int,int);
		~Rectangle();
		Rectangle(const Rectangle& other); // Copy constructor
		Rectangle& operator=(const Rectangle& other); 

	   	 bool operator<(const Rectangle& other) const {
       		 return area() < other.area();
   		 }


};


template<typename T>
void sortAnyArray(T& arr, int size){ sort(arr,arr+size);}



int main () {
	Rectangle r(1,2);
	Rectangle rects[] = {Rectangle(3,4),Rectangle(4,5)};

	sortAnyArray(rects,2);

	int x = r.area();

	cout<<x<<endl;


return 0;
}



Rectangle::~Rectangle(){
	delete length;
	delete width;
}

Rectangle::Rectangle(int l,int w){
	length = new int(l);
	width = new int(w);

}

Rectangle::Rectangle(const Rectangle& other) {
    length = new int(*other.length);
    width = new int(*other.width);
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this == &other) {
        return *this;
    }
    delete length;
    delete width;
    length = new int(*other.length);
    width = new int(*other.width);
    return *this;
}
int Rectangle::area() const{

	return (*length)*(*width);
}

