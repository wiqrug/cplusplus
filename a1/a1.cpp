#include <iostream>
#include <string>
#include <exception>

using namespace std;

class TimeOfDay{
	private:
		int hour;
		int minute;
		int second;
	public:

		TimeOfDay(int,int,int);
		TimeOfDay(const TimeOfDay&);
		bool operator==(const TimeOfDay&)const;
		string toString() const;
		TimeOfDay operator+ (const int&) const;
		TimeOfDay operator+ (const TimeOfDay&) const;

};

TimeOfDay TimeOfDay::operator+ (const TimeOfDay& other) const{
	int totalSecond = second + other.second;
	int totalMinute = minute + other.minute;
	int totalHour = hour + other.hour;

	totalMinute += totalSecond / 60;
	totalSecond %= 60;  // Remaining seconds after overflow
	totalHour += totalMinute / 60;
	totalMinute %= 60;  // Remaining minutes after overflow

	totalHour %= 24;

	TimeOfDay t(totalHour, totalMinute, totalSecond);
	return t;
}

TimeOfDay TimeOfDay::operator+(const int& secs)const{
	int totalSecond = second+secs;

	int totalMinute =minute+ totalSecond/60;

	totalSecond = totalSecond%60;

	int totalHour =hour+ totalMinute/60;

	totalMinute=totalMinute%60;

	if (totalHour>=24){totalHour = totalHour%24;}

	TimeOfDay t(totalHour,totalMinute,totalSecond);

return t;
}



string TimeOfDay::toString() const{
	return to_string(hour) + ":"+to_string(minute)+":"+to_string(second);
}

bool TimeOfDay::operator==(const TimeOfDay& other)const{
	if (hour==other.hour &&  minute == other.minute && second == other.second){return true;}
return false;
}


TimeOfDay::TimeOfDay(int h, int m, int s){
	if (h>=0 && h<=24){hour=h;}
	else{throw logic_error("Hour out of range");}

	if(m>=0 && m<=59){minute=m;}
	else{throw logic_error("Minute out of rαnge");}

	if(s>=0 && s<=59){second=s;}
	else{throw logic_error("Second out of range");}

}

TimeOfDay::TimeOfDay(const TimeOfDay& other):hour(other.hour),minute(other.minute),second(other.second){}



int main () {
try{



TimeOfDay argsConstr(12,12,12);
TimeOfDay copyConstr = argsConstr;

cout<<copyConstr.toString()<<endl;

copyConstr=copyConstr+50;

copyConstr=copyConstr+copyConstr;

cout<<copyConstr.toString()<<endl;
}catch (exception& e){cout<<e.what()<<endl;}


return 0;
}
