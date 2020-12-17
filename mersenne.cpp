#include <iostream>
#include <math.h>
#include <cstdlib>
#include <random>
#include <iomanip>
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

bool isPerfect(int num){
	int sumDiv = 0;
	for(int i = 1; i < num; i++){
		if(num % i == 0){
			sumDiv += i;
		}
	
	}
	if(sumDiv == num){
		return true;
	}
	return false;
}

bool isMersenne(int num){
	int j = 1;
	while(pow(2,j) - 1 <= num){
		if(isPrime(pow(2,j) - 1)){
		}
		j++;
	}
	if(pow(2,j - 1) - 1 == num){
		return true;
	}
	return false;

}



int main(){
	int marsWo1;
	int marsWo2;
	int zakres;

	bool APP_ON = true;
	cout << "liczby Mersenne'a to liczby postaci 2^(n) - 1" << endl;
	cout << "by liczba Mersenne'a byla pierwsza, wykladnik n musi byc pierwszy, jednak nie jest to czynnik gwarantujacy" << endl;
	while(APP_ON){
	cout << "1) generowanie liczb Mersenne'a z zakresu k liczb" << endl << "2) sprawdzanie, czy podana liczba jest liczba Mersenne'a" << endl << "3) generowanie liczb doskonalych 4) wypisywanie liczby mersenna na postawie n 5) wyjscie" << endl;
	cin >> marsWo1;
	
	int j = 1;
	int counter = 0;
	bool pierwsze;
	int marsWo77;

	
	switch(marsWo1){
		case 1:
			cout << "podaj zakres, do ktorego wygenerowac liczby marsenne'a" << endl;
						
			cin >> zakres;
			cout << endl << "czy chcesz by liczby byly 1)wszytkie 2)tylko pierwsze (w tym wypadku wygeneruje rowniez liczby doskonale) 3)tylko zlozone" << endl;
			cin >> marsWo2;
			cout << endl;
			switch(marsWo2){
				case 1:
					j = 1;
					cout << "{";
					while(pow(2,j) - 1 <= zakres){
						cout << pow(2,j) - 1 << ", ";
						j++;
					}
					cout << "}"<<endl;
					break;
				case 2:
					j = 1;
					setprecision(1);
					cout << "zapis - (liczba mersenna: liczba doskonala)" << endl;
					cout << "{";
					while(pow(2,j) - 1 <= zakres){
						
						if(isPrime(pow(2,j) - 1)){
							cout << fixed<<pow(2,j) - 1 << ":" << pow(2, j-1) * (pow(2,j) - 1) << ", ";
						}
						j++;
					}
					cout << "}"<<endl;
					break;
				case 3:
					j = 1;
					cout << "{";
					while(pow(2,j) - 1 <= zakres){
						if(!isPrime(pow(2,j) - 1)){
							cout << pow(2,j) - 1 << ", ";
						}
						j++;
					}
					cout << "}"<<endl;
					break;
				default:
					cout << "podaj liczbe z zakresu 1-3" << endl; 
			}
			break;
		case 2:
			cout << "wprowadz liczbe do sprawdzenia " << endl;
			cin >> j; 
			if(isMersenne(j)){
				cout << "liczba jest liczba Mersenne'a" << endl;
			} else {
				cout << "liczba nie jest liczba Mersenne'a" << endl;
			}
			break;
		case 3:
			int marsWo3;
			cout << "wzor na liczbe doskonala to 2^(n-1) * (2^n - 1)"<<endl;
			cout << "1) wprowadz klucz do funkcji random, na podstawie ktorego wygenerujemy 10 losowych liczb za pomoca powyzszego algorytmu"<<endl << "2) losowy klucz" << endl; 
			cin >> marsWo3;
			switch(marsWo3){
				case 1:
					cin >> j;
					break;
				case 2:
					j = time(NULL);
					break;
				default:
					cout << "podaj liczbe z zakresu 1-2" << endl;
			}
			
			
		
				
			counter = 0;
			srand(j);
			for(int i = 0; i < 9; i++){
				int P = rand() % 25;
				long long int D = 0;		


				D = pow(2, P-1) * (pow(2,P) - 1); 	
				cout << D;
				if(isPerfect(D)){
					cout << " - doskonala";
					counter ++;
				}
				cout << "      liczba Mersenna na podstawie ktorej ja otrzymalismy:  " << pow(2,P) - 1; 
				cout << endl;
			}
			cout << "z 10 liczb " << counter << " okazalo sie doskonalymi, ciekawe!" << endl;
			cout << "jak mozesz zauwazyc wzor dziala wtedy gdy uzyjemy do niego liczby Mersenna, ktora jest liczba pierwsza" << endl;

			break;
		
		case 4:
			cout << "podaj n" << endl;
			cin >> counter;
			cout << pow(2,counter) - 1;
			

			
	
		case 5:
			APP_ON = false;	
			break;

		default:
			cout << "podaj liczbe z zakresu 1 - 3";
	
	}


	}





}









