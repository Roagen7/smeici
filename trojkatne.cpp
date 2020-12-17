#include <iostream>
#include <string>

using namespace std;

void trojkat(int n, bool jednaLiczba){
	//h - rzedy
	int obs = n;
	int numer;
	if(jednaLiczba){
		numer = 1;
	} else {
		 numer = 8;	
	}
	
	int level = 0;	


	for(int i = 0; i < n; i++){
		for(int j = 0; j <=  n *2; j++){
			if((((j >= obs - 1 && j <= n) || (j <= n* 2 - obs && j >= n)) && (j % 2 && i % 2 ==0 || j % 2 == 0 && i % 2)) && level < i + 1){
				level++;
				cout << numer;
				if(jednaLiczba){
					numer++;
				}

			} else {
				if(numer < 10){
					cout << " ";
	
				} else {
					cout << " ";
				}
			}
		}
		obs --;
		cout << endl;
		level = 0;	
	}
}

bool palindromiczna(string liczba){
	for(int i = 0; i < liczba.length(); i++){
		if(liczba[i] != liczba[liczba.length() - i - 1]){
			return false;
		}


	}
	return true;

}



bool checkTriangular(int num){
	if(num == 0){
		return true;
	}
	int kolejny = 2;
	int T = 1;
	while(num > T){
		T += kolejny;
		kolejny++;
	}
	if(num == T){
		return true;
	}
	return false;

}

int main(){
	cout << "liczba trojkatna to taka liczba n z ktorej po ustawieniu liczb od 1 do n da sie ulozyc trojkat" << endl;
	bool APP_ON = true;
	while(APP_ON){

	cout << "1) sprawdzanie, czy liczba jest trojkatna, 2) wizualizacja liczb trojkatnych, 3) n-liczb trojkatnych palindromicznych 4) wyjscie" << endl;
	int wybor;
	int wybor22;
	int n;
	int numN;
	int coconutCounter;
	cin >> wybor;	
	

	switch(wybor){
		
		case 1:
			cout << "wprowadz liczbe" << endl;
			cin >> n;
			cout << endl;
			if(checkTriangular(n)){
				cout << "jest" << endl;
			} else {
				cout << "nie jest" << endl;
			}
			break;

		case 2:
			cout << "wprowadz n - liczbe rzedow" << endl;
			cin >> n;
			cout << "1) piramida z liczb 1 do n 2) piramida osemek(ladniej wyglada)";
			cin >> wybor22;
			switch(wybor22){
				case 1:
					trojkat(n, true);
					break;
				case 2:
					trojkat(n,false);
					break;
			
			}

			break;

		case 3:
			cout << "wprowadz ile trojkatnych liczb palindromicznych wypisac" << endl;
			cin >> n;
			numN = 1;
			coconutCounter = 0;
				
			while(coconutCounter < n){
				if(palindromiczna(to_string(numN)) && checkTriangular(numN)){
					coconutCounter++;
					cout << numN << endl;
				}
				numN++;	
			}	

			break;
		case 4: 
			APP_ON = false;
	
	}

	}
}


