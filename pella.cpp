#include <iostream>
#include <iomanip> 
#include <math.h>

using namespace std;




long double pella(int n){
	if(n == 1){
		return 0;
	}
	if(n == 2){
		return 1;
	}
	int pocz_a = 0;
	int pocz_b = 1;
	int c;
	while(n > 2){
		c = pocz_a + 2 * pocz_b;	
		pocz_a = pocz_b;
		pocz_b = c;
		n--;
	}

	return c;

}
bool isPell(int num){
	int j = 1;
	while(pella(j) < num){
		j++;
		}
	if(pella(j) == num){
		return true;
	}
	return false;
}

int main(){
	cout << "liczba Pella to liczba ktora powstaje wedlug wzoru rekurencyjnego:" <<endl << endl;
	cout << "       {       0           gdy n = 0" << endl;
	cout << "P(n) = {       1           gdy n = 1" << endl;
	cout << "       {  2P(n-1) + P(n-2) gdy n > 1" << endl << endl;
	bool APP_ON = true;
	int wyB;
	long long int n, a, b ,c;
	long double suma = 0;
	while(APP_ON){
	cout << "1) generowanie kolejnych liczb Pella i srebrna liczba 2) zbieznosc liczb Pella 3)";
	cout << " liczby Pella a trojkat Pitagorejski 4) czy liczba jest Pella? 5) wyjscie" << endl;
	cin >> wyB;
	
	switch(wyB){
		case 1:
			cout << "wprowadz ile wyrazow od 1 do n chcesz zebym wypisal" << endl;
			cin >> n;
				for(int i = 1; i <= n; i++){
					cout << pella(i);
					if(i != 1 && i != 2){
					cout << "      "<<pella(i)/pella(i-1);
					}
					cout << endl;

				}
			cout << "jak mozesz dostrzec stosunek kolejnych wyrazow ciagu liczb Pella zbiega sie do srebrej liczby czyli 2.41(sumy jeden i pierwiasta z dwoch)" << endl;
			cout << "liczby te mozemy wykorzystac do wyznaczania wartosci pierwiastka z dwoch" << endl;
			cout << "z wprowadzonego przez ciebie ciagu wartosc pierwiastka z dwoch wynosi: " <<fixed<< pella(n)/pella(n-1) - 1 << endl; 
			break;
		case 2:
			cout << "podaj n, na jej podstawie zsumuje odwrotnosci liczb Pella do n-tego wyrazu" << endl;
			cin >> n;
			cout << "0 ";			
			
			cout << pella(n-1) << " + " << pella(n) << "/ " << pella(n) << endl; 
			suma = (pella(n-1) + pella(n))/ pella(n);
			cout << " = " << suma << endl;

			break;
		case 3:
			cout << "wprowadz n, na podstawie tego wygeneruje n-ty zestaw liczb tworzacych trojkat pitagorejski" << endl;
			cin >> n;
			

			a =  2 * pella(n) * pella(n+1);
			b = pow(pella(n+1),2) - pow(pella(n),2);
			c = pow(pella(n+1),2) + pow(pella(n),2);			
			
			cout << "       xx" << endl;
			cout << "       x  x" << endl;
			cout << "       x   x" << endl;
		       	cout << "       x    x" << endl;
			cout << "       x     x" << endl;
			cout << "       x      x" << endl;
			cout << "     A x       x  C" << endl; 
			cout << "       x        x" << endl;
			cout << "       x         x" << endl;
			cout << "       x          x" << endl;
			cout << "       x           x" << endl;
			cout << "       xxxxxxxxxxxxxx" << endl;	
			cout << "              B        " <<endl;
			cout << "A: " << a << endl;
			cout << "B: " << b << endl;
			cout << "C: " << c << endl;

			break;
		case 4:
			cout << "wprowadz liczbe: " << endl;
			cin >> n;
			
			if(isPell(n)){
				cout << "jest" << endl;
			} else {
				cout << "nie jest" << endl;
			}


			break;

		case 5:
			APP_ON = false;
			
	}
	}
}
