#include <iostream>


using namespace std;

void choinka(int n){
	const char lewa = '/';
	const char prawa = '\\';
	const char kreska = '_';
	const char pien = '|';
	const char spacja = ' ';
	
	for(int i = 0; i < n; i++){
		cout << spacja;		
	}
	cout << "*";

	for(int i = 0; i < n; i++){
		cout << spacja;		
	}

	cout << endl;

	for(int i = 1; i < n ; i++){
		for(int j = 0; j <= 2 * n; j++){
			if(j ==  n- i){
				cout << lewa;
			} else if(j == n + i) {
				cout << prawa;
			
			} else if(j == n){
				cout << pien;
			
			} else if(i == n - 1 && (j >= n - i && j <= n+i)){
				cout << kreska;
			
			} else {
				cout << spacja;
			}
		}
		
		cout << endl;

	}
	
	for(int i = 0; i < n; i++){
		cout << spacja;		
	}
	cout << pien;

	for(int i = 0; i < n; i++){
		cout << spacja;		
	
	}



}





int main(){
	int h;
	cout << "wprowadz wysokosc choinki [w pniach]"<< endl;
	cin >> h; 
	choinka(h);	

}

