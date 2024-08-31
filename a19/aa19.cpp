/*
Δημιουργήστε την κλάση “ορθογώνιο παραλληλόγραμμο”. Το μήκος και
το πλάτος είναι ακέραιοι αριθμοί και ως attributes της κλάσης μπορούν να
χρησιμοποιηθούν μόνο δείκτες. Δημιουργήστε μία template συνάρτηση η οποία θα
ταξινομεί πίνακα οποιουδήποτε τύπου και χρησιμοποιήστε την για να ταξινομήσετε
πίνακα ορθογωνίων παραλληλογράμμων, κατά αύξουσα τάξη εμβαδού.
*/



#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Rectangle{
	private:
		int* width;
		int* length;
	public:
		Rectangle(const int,const int);
		~Rectangle();
		Rectangle(const Rectangle&);
		Rectangle& operator= (const Rectangle&);
		int getArea() const;
		bool operator<(const Rectangle&)const;
};

bool Rectangle::operator<(const Rectangle& other) const{
	if (this->getArea()>other.getArea()){return true;}
	return false;

}


template<typename T>
void sortAnyArray(T& arr,int size){
	sort(arr,arr+size);
}


int main () {
	Rectangle r(1,2);
        Rectangle rects[] = {Rectangle(3,4),Rectangle(4,5)};

        sortAnyArray(rects,2);

        int x = r.getArea();

        cout<<x<<endl;




return 0;}




int Rectangle::getArea()const {return ((*width)*(*length));}

Rectangle::Rectangle(const int w,const int l){
	width = new int(w);
	length = new int(l);
}

Rectangle::~Rectangle(){
	delete width;
	delete length;
}

Rectangle::Rectangle(const Rectangle& other){
	width = new int(*other.width);
	length = new int(*other.length);

}


Rectangle& Rectangle::operator=(const Rectangle& other){
	if (this==&other){return *this;}

	delete width;
	delete length;

	width = new int(*other.width);
	length = new int(*other.length);
return *this;
}
