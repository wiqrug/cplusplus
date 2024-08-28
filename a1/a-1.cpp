#include <iostream>
using namespace std;

/*
Θέμα (A-1). Να γραφεί κλάση η οποία θα παριστά μία χρονική στιγμή της ημέρας
(ώρα, λεπτά, δευτερόλεπτα). Το αντικείμενο της κλάσης θα αρχικοποιείται με τις τρεις
τιμές ή με ένα άλλο αντικείμενο της ίδιας κλάσης.
Η κλάση θα υποστηρίζει τις ακόλουθες λειτουργίες:



Δημιουργία νέας χρονικής στιγμής που θα προκύπτει από την αύξηση μίας
υπάρχουσας κατά ένα αριθμό δευτερολέπτων (υπερφόρτωση τελεστή “+”)


Δημιουργία νέας χρονικής στιγμής που θα προκύπτει από την αύξηση μίας
υπάρχουσας κατά μία άλλη χρονική στιγμή (υπερφόρτωση τελεστή “+”)

Επιστροφή της χρονικής στιγμής ως string
Έλεγχος ισότητας μεταξύ δύο αντικειμένων της κλάσης (υπερφόρτωση
τελεστή “==”).
Να γραφεί main συνάρτηση η οποία θα επιδεικνύει τη λειτουργία της κλάσης.

 */

//ask gpt if this solution is good

class MomentOfDay{

private:
	int second;
	int hour;
	int minute;

public:
	MomentOfDay (int,int,int);
	MomentOfDay( const MomentOfDay& momentOfDay);
	//why is const in the end ? does this make the otherSecond readonly?
	MomentOfDay operator+ (int otherSecond) const;
	MomentOfDay operator+ (const MomentOfDay& momentOfDay) const;
	void printAll();

	bool operator== (const MomentOfDay& momentOfday) const;

};

bool MomentOfDay::operator== ( const MomentOfDay& momentOfDay) const
{

	return momentOfDay.hour==hour && momentOfDay.minute==minute && momentOfDay.second==second;

}

void MomentOfDay::printAll(){
	cout<<"Hour is "<< hour<< endl;
	cout<<"Minute is "<< minute<< endl;
	cout<<"Second is "<< second<< endl;
}

MomentOfDay MomentOfDay::operator+ (const MomentOfDay& momentOfDay)const  {
		int newSecond = momentOfDay.second + second;
		int newMinute = momentOfDay.minute + minute;
		int newHour = momentOfDay.hour + hour;
		while (newSecond>=60){
			newSecond=newSecond-60;
			newMinute++;
		}
		while (newMinute>=60){
			newMinute=newMinute-60;
			newHour++;
		}

		while (newHour>=24){
			newHour= newHour-24;
		}

		return MomentOfDay(newHour,newMinute,newSecond);

}


MomentOfDay::MomentOfDay(int h, int m, int s)
{
	hour=h;
	minute=m;
	second=s;
}

MomentOfDay::MomentOfDay (const MomentOfDay& momentOfDay){
	hour=momentOfDay.hour;
	minute=momentOfDay.minute;
	second=momentOfDay.second;
}

//We need to return another object using the constructor
MomentOfDay MomentOfDay::operator+ (int otherSecond) const{
		//if otherSecond + this.second< 60, its just added
		// if othersecond + this second == 60, then, increase minute by 1
		// if otherSecond + this second >60, 40+40 = 80, add 1 minute and add for second 60-40+40


		int newSecond = otherSecond+second;
		int newHour=hour;
		int newMinute=minute;

		if (newSecond>=60){
			newMinute++;
			newSecond=newSecond-60;
		}

		if (newMinute >=60 ) {
			newHour++;
			newMinute=newMinute-minute;
		}

		if (newHour >=24) {
			newHour=24-newHour;
		}
		return MomentOfDay(newHour,newMinute,newSecond);
}



int main () {
	cout<<"Hello"<<endl;
	MomentOfDay d1(1,2,3);
	MomentOfDay d2(3,64,65);
	d2=d2+d1;

	d2.printAll();

	if (d2==d1) {cout<<"They are equal"<<endl;}
	else {cout<<"They are not equal"<<endl;}

return 0;

}
