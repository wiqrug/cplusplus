#include <iostream>
#include <string>



using namespace std;




class Date{
	private:
		int day;
		int month;
		int year;

	public:
		Date(int,int,int);
		Date(const Date&);
		Date operator+(int m);		//Αυξάνουμε κατα μήνα.
		string toString() const;
		bool operator>( const Date&) const;
};



Date Date::operator+(int m) {
    int totalMonths = month + m;
    int newYear = year + totalMonths / 12;
    int newMonth = totalMonths % 12;
    if (newMonth == 0) {
        newMonth = 12;
        newYear -= 1;
    }
    return Date(day, newMonth, newYear);
}
bool Date::operator> (const Date& date) const{
	if (year>date.year){return 1;}
	if(year == date.year && month>date.month){return 1;}
	if (year==date.year && month==date.month && day>date.day){return 1;}
	return 0;

}



Date::Date(int d,int m, int y){day=d; month=m; year=y;}
Date::Date(const Date& other){day=other.day; month=other.month; year=other.year;};



string Date::toString()const {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

int main() {
    Date date1(15, 8, 2023);
    Date date2(1, 1, 2024);

    cout << "Date 1: " << date1.toString() << endl;
    cout << "Date 2: " << date2.toString() << endl;

    Date newDate = date1 + 5;  // Adding 5 months
    cout << "Date 1 after adding 5 months: " << newDate.toString() << endl;

    if (newDate > date2) {
        cout << "New Date is greater than Date 2" << endl;
    } else {
        cout << "New Date is not greater than Date 2" << endl;
    }

    return 0;
}
