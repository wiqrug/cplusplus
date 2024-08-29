/*
Να γραφεί κλάση η οποία θα παριστά μία χρονική στιγμή της ημέρας
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


#include <iostream>
#include <string>

using namespace std;



class TimeOfDay{
	private:
		int hour;
		int minute;
		int second;
	public:
		TimeOfDay(const int&,const int&, const int&);
		TimeOfDay(const TimeOfDay&);
		string display()const ;

		bool operator==(const TimeOfDay&)const;
		TimeOfDay operator+(const int)const;
		TimeOfDay operator+(const TimeOfDay&)const;
		TimeOfDay& operator=(const TimeOfDay&);
};





int main () {
//Tests

int x =50;
TimeOfDay t1(12,20,59);

TimeOfDay t2 = t1+50;

cout<<t2.display()<<endl;

t2=t2+t1;

cout<<t2.display()<<endl;
return 0;
}


TimeOfDay TimeOfDay::operator+(const int s)const{
	int totalSecond = s+second;
	totalSecond = totalSecond%60;
	int totalMinute = minute+(totalSecond/60);

	int totalHour = hour + (minute/60);
	if (totalHour>=24){
		totalHour = totalHour%24;
	}

return TimeOfDay(totalHour,totalMinute,totalSecond);
}



TimeOfDay TimeOfDay::operator+(const TimeOfDay& other)const{
		int totalSecond = second+other.second;
		int totalMinute = minute + other.minute + (totalSecond/60);
		int totalHour = hour+ other.hour + (totalMinute/60);

return TimeOfDay(totalHour%24,totalSecond%60,totalMinute%60);

}


bool TimeOfDay::operator==(const TimeOfDay& other) const{
		if (this == &other){return true;}

		return (hour==other.hour && minute==other.minute && second == other.second);

}


string TimeOfDay::display() const{return (to_string(hour)+ " " +to_string(minute)+ " "+ to_string(second));}

TimeOfDay::TimeOfDay(const int& h, const int& m, const int& s):hour(h),minute(m),second(s){}
TimeOfDay::TimeOfDay(const TimeOfDay& other):hour(other.hour),minute(other.minute),second(other.second){}




TimeOfDay& TimeOfDay::operator=(const TimeOfDay& other){
	hour = other.hour;
	minute=other.minute;
	second=other.second;

return *this;
}
