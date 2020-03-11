#include <iostream>
#include <random>

using namespace std;

int main(){
	
	srand(time(NULL));
	int miniCena;
	int miniNumer = 1;
	int n;
	cout << "wprowadz n - ilosc miast" << endl;
	cin >> n;

	// 0 - lp , 1 - popyt, 2 - odl od poprzedniego miasta


	int miasta[n][3];

	for(int i = 0; i < n; i++){
		miasta[i][0] = i + 1; // wprowadzam liczbe porzadkowa
		miasta[i][1] = rand() % 10; // wprowadzam losowy popyt
		miasta[i][2] = rand() % 10 + 1; // wprowadzam losowa odleglosc 

		cout <<endl << "miasto nr: " << miasta[i][0] << " popyt: " << miasta[i][1] << " odleglosc od poprzedniego miasta: "<< miasta[i][2];

	}	
	cout << endl;
	// baza to n = 1 TYMCZASOWO
	
	for(int baza = 1; baza <= n; baza++){


		int cena = 0;
		int cel;
		int km1;
		int km2;	
		

		for(int cel = 1; cel <= n; cel++){
			km1 = 0;
			km2 = 0;


			int j = baza;
			int tymczasowyCel = baza;

			do {   
				if(j >= n){
					km1 += miasta[j - n][2];
					tymczasowyCel = miasta[j - n][0];	
				
				} else {
						
					km1 += miasta[j][2]; 	
					tymczasowyCel = miasta[j][0];
				}
					j++;

				
			} while(tymczasowyCel != cel);

			
			tymczasowyCel = baza;
			j = baza - 1;


			while(tymczasowyCel != cel){
					
				if(j < 0){
					km2 += miasta[j + n][2];
					tymczasowyCel = miasta[j + n][0];
				} else {
					km2 += miasta[j][2];
					tymczasowyCel = miasta[j][0];	
				}
				j--;
			}
			km2 -= miasta[cel - 1][2]; 
			
			
		//cout << endl << "odleglosc miedzy "<< baza << " a " << cel << ": " << endl << "		odwrotnie do wskazowek: " << km1 << endl << "		zgodnie ze wskazowkami: " << km2 << endl;
			int min; 
			
			if(cel == baza){
				km1 = 0;
				km2 = 0;
			}

			if(km1 > km2){
				min = km2;
			} else {
				min = km1;
			}

			cena += min * miasta[cel - 1][1] * 2;		
		}

		cout <<endl<< "cena w bazie " << baza <<" : " << cena<<endl;

		if(baza == 1){
			miniCena = cena;	
		}


		if(cena < miniCena){
			miniCena = cena;
			miniNumer = baza;
		}
	}
	
	cout << endl << "cena bedzie najmniejsza dla browaru w miescie nr " << miniNumer << " i bedzie wynosila " << miniCena << " talarow" << endl;
		
		
}

