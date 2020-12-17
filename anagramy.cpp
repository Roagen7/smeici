#include <iostream>
#include <string>

using namespace std;

string combinations(string str, string crossedOut){
	string possible = "";
	
	if(str.length() == 1){
		//return str + "     ";
		return crossedOut + str + "   ";
	}
	for(int i = 0; i < str.length(); i++){
		possible+= (combinations(str.substr(0,i) + str.substr(i + 1,str.length()), crossedOut + str[i]));
	}
	
	return possible;

}

int main(){
	cout << "anagram to wyraz powstaly w wyniku przestawienia wszystkich liter innego wyrazu" << endl;
	bool APP_ON = true;
	string strX, strY;
	int wo1;	
	while( APP_ON ) {
	cout << "1) wszystkie mozliwe anagramy danej liczby 2) czy dwie liczby sa anagramami 3) wyjscie" << endl;
	cin >> wo1;	
	char maxVal;
	int maxIndex;

	switch(wo1){
		case 1: 
			cout << "podaj liczbe" << endl;
			cin >> strX;
			cout << endl;
			cout << combinations(strX, "") << endl;
			break;	
		case 2:
			cout << "podaj liczbe 1" << endl;
			cin >> strX;
			cout << "podaj liczbe 2" << endl;
			cin >> strY;
			


			for(int i = 0; i < strX.length() ; i++){
				maxVal = strX[i];
				maxIndex = i;
				for(int j = i; j < strX.length(); j++){
					if(strX[j] > strX[i]){
						maxVal = strX[j];
						maxIndex = j;
					}
				}
				swap(strX[i], strX[maxIndex]);
		
			}

			for(int i = 0; i < strY.length() ; i++){
				maxVal = strX[i];
				maxIndex = i;
				for(int j = i; j < strY.length(); j++){
					if(strY[j] > strY[i]){
						maxVal = strX[j];
						maxIndex = j;
					}
				}
				swap(strY[i], strY[maxIndex]);
		
			}
			if(strX == strY){
				cout << "sa anagramami" << endl;
			} else {
				cout << "nie sa anagramami" << endl;
			}
			
			break;

		case 3: 
			APP_ON = false;
	}

	}

}
