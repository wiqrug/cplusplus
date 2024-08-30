/*
Να γραφεί κλάση η οποία θα παριστά μία ημερομηνία (ημέρα, μήνας,
έτος). Το αντικείμενο της κλάσης θα αρχικοποιείται με τις τρεις τιμές ή με ένα άλλο
αντικείμενο της ίδιας κλάσης.
Η κλάση θα υποστηρίζει τις ακόλουθες λειτουργίες:

Δημιουργία νέας ημερομηνίας που θα προκύπτει από την αύξηση μιας
υπάρχουσας κατά Ν μήνες (υπερφόρτωση τελεστή “+”)

Επιστροφή της ημερομηνίας ως string

Υπερφόρτωση του τελεστή “>” ώστε να επιστρέφεται true αν η ημερομηνία
είναι μεταγενέστερη από μία άλλη.

Να γραφεί συνάρτηση η οποία θα ταξινομεί πίνακα ημερομηνιών.

Να γραφεί main συνάρτηση η οποία θα επιδεικνύει τη λειτουργία των προηγούμενων.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;



class Date{
	private:
		int day;
		int month;
		int year;
	public:
		Date(const int&,const int&,const int&);
		Date operator+(const int&)const;
		string toString()const;
		Date& operator= (const Date&);
		bool operator>(const Date&)const;
};

bool Date::operator>(const Date& other) const{
	if (day>other.day&&year>other.year&&month>other.month){return true;}
	return false;

}


Date& Date::operator=(const Date& other){
	if(this ==&other){return *this;}
	day = other.day;
	month= other.month;
	year = other.year;

	return *this;
}


string Date::toString()const{
	return to_string(day) +" "+ to_string(month)+" "+ to_string(year);
}

Date Date::operator+(const int& m)const{

	int totalMonth = month + m;
	int totalDay = this->day;
	int totalYear = this->year;
	if (totalMonth>12){
		totalYear = totalYear + totalMonth/12;
		totalMonth = totalMonth%12;
		if (totalMonth==0){
			totalMonth=12;
			totalYear--;
		}
	}

return Date(totalDay,totalMonth,totalYear);
}

bool compareDates(const Date& d1,const Date& d2){
	return d1>d2;
}

void sortDates(vector<Date>& dates){
	sort(dates.begin(),dates.end(),compareDates);
}



Date::Date(const int& d,const int& m, const int& y):day(d),month(m),year(y){}




int main() {
	Date d1(25, 11, 2011);
	Date d2(1, 1, 2021);
	Date d3(15, 8, 2020);

	cout << "Initial Dates:" << endl;
	cout << d1.toString() << endl;
	cout << d2.toString() << endl;
	cout << d3.toString() << endl;

	Date d4 = d1 + 3;  // Adding 3 months to d1
	cout << "\nDate after adding 3 months to d1:" << endl;
	cout << d4.toString() << endl;

	bool isGreaterThan = (d2 > d1);
	cout << "\nIs d2 greater than d1? " << (isGreaterThan ? "Yes" : "No") << endl;

	vector<Date> dates = {d1, d2, d3, d4};
	sortDates(dates);
	cout << "\nSorted Dates in Ascending Order:" << endl;
	for (const auto& date : dates) {
		cout << date.toString() << endl;
	}

return 0;
}
