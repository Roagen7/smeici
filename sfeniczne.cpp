#include <iostream>
#include <vector>
#include <random>

using namespace std;

bool isPrime(int num){
	if(num < 2){
		return false;
	}
	if(num == 2){
		return true;
	}
	
	for(int i = 2; i < num; i++){
		if(num % i == 0){
			return false;
		}
	}
	return true;
}
	
void divisors(int num, int *divArray){
	for(int i = 1; i <= num; i++){
		if(num % i == 0){
			*divArray = i;
			divArray++;
		}
	}
}

int numOfDivisors(int num){
	int counter = 0;
	for(int i = 1; i <= num; i++){
		if(num % i == 0){
			counter ++;
		}
	}
	return counter;
}


void splitToEl(int num, int *arr){
	int i = 2;
	
	while(num != 1){
		if(num % i == 0){
			num /= i;
			*arr = i;
			arr++;
		} else {
			i ++;
		}
	}
	
}

int numOfFactors(int num){
	int counter = 0;
	int i = 2;
	
	while(num != 1){
		if(num % i == 0){
			num /= i;
		       	counter++;	
		} else {
			i ++;
		}
	}


	return counter;
}



int main(){
		

	vector <int> lPierwsze;
	int liczba;
	
	int woal;
	cout << "1) podaj liczbe z klawiatury 2) wygeneruj iloczyn losowych liczb pierwszych" << endl;
	cin >> woal;
	switch(woal){
		case 1:
			cout << "podaj liczbe" << endl;
			cin >> liczba;
			break;
		case 2:
			srand(time(NULL));
			for(int i = 2; i < 1000; i++){
				if(isPrime(i)){
					lPierwsze.push_back(i);
				}
			}
			liczba = lPierwsze[rand() % lPierwsze.size()] * lPierwsze[rand() % lPierwsze.size()] * lPierwsze[rand() % lPierwsze.size()];

			break;	
	}

	


	int divArr[numOfDivisors(liczba)];
	int facArr[numOfFactors(liczba)];	
	divisors(liczba,divArr);
	splitToEl(liczba, facArr);
	
	bool flag = true;
	for(int i = 0; i < numOfFactors(liczba); i++){
		if(!isPrime(facArr[i])){
			flag = false;
		}
	};
	


	bool APP_ON = true;
	int wyborG;

	while(APP_ON){
		
		if(flag && numOfFactors(liczba) == 3){
			cout << "liczba " << liczba <<" jest sfeniczna" << endl;
		} else {
			cout << "liczba " << liczba << " nie jest sfeniczna" << endl;
		}		
		
		cout << "1) czynniki liczby " << liczba  << " 2) dzielniki liczby " << liczba <<" 3) wyjscie" << endl;
		cin >> wyborG;
		switch(wyborG){
			case 1:
				cout << liczba <<" = "<<facArr[0];
				for(int i = 1; i < numOfFactors(liczba); i++){
					cout <<" * " << facArr[i];	
				}
				cout << endl;

				break;				
			case 2: 
				cout << "D = {";
				for(int i = 0; i < numOfDivisors(liczba); i++){
					cout << divArr[i] << ", ";  
				}
				cout << "}" << endl;
				cout<< "ciekawostka, wszystkie liczby sfeniczne maja 8 dzielnikow, ale nie wszystkie liczby z 8 dzielnikami sa sfeniczne" << endl;
				break;	
			case 3:
				APP_ON = false;	
		
		}

	
	
	}


//	for(int i = 0; i < numOfDivisors(liczba); i++){
//		cout << divArr[i] << endl;	
//	}



}




