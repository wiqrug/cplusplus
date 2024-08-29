/*
Να δημιουργηθεί η κλάση “UString” η οποία παριστά συμβολοσειρές που
αποτελούνται “αποκλειστικά” από κεφαλαίους λατινικούς χαρακτήρες ([A..Z]). Η
κλάση θα προσφέρει την απαραίτητη λειτουργικότητα για να υλοποιηθούν τα επόμενα
ζητούμενα.
Να γραφεί συνάρτηση η οποία θα δέχεται δύο θετικούς ακέραιους αριθμούς Ν και Κ
και θα δημιουργεί και επιστρέφει μία συλλογή Ν διαφορετικών αντικειμένων UString
το κάθε ένα από τα οποία θα αποτελείται από μέχρι Κ χαρακτήρες.
Να γραφεί συνάρτηση που θα τυπώνει σε ostream κανάλι τις συμβολοσειρές της
προηγούμενης συλλογής.
Για την υλοποίηση των προηγούμενων δεν θα χρησιμοποιηθούν vectors.

*/


#include <iostream>
#include <string>

using namespace std;


class UString {
	private:
		string ustring;
	public:
		UString(const string&);
		UString();
		void display();
};




UString* getRandomStrings(int& n, int& k){
	UString* randStrings = new UString[n];

	for (int i=0; i<n;++i){
		string randomStr= "";
		for (int j=0; j<k; ++j){
			char randomChar = 'A' +rand()%26;
			randomStr+= randomChar;
		}
		randStrings[i] = UString(randomStr);
	}

	return randStrings;
}

void printCollection(UString* collection, int n){
	for( int i=0; i<n; ++i){
		collection[i].display();
	}


}




int main () {

	srand(time(0));
	int N=5;
	int K=8;

	UString* randomStrings = getRandomStrings(N, K);

	printCollection(randomStrings, N);

	delete[] randomStrings;


return 0;
}





void UString::display(){
	cout<<ustring<<endl;
}


UString::UString(){
	ustring="";

}


UString::UString(const string& s){
	for (const auto& ch:s){
		if (ch<'A' || ch>'Z'){
			cerr<<"only capitals are accepted"<<endl;
			return ;
		}
	}



	ustring=s;
}




