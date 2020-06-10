#include <iostream>




using namespace std;


int main(){
	int n;//stopien wielomianu
	int w;//liczba W(w)
	cout << "podaj stopien wielomianu" << endl;
	cin >> n;
	int arr[n + 1];


	for(int i = 0; i < n + 1; i++){
		
		cout << "podaj " << i + 1 << " wspl. wielomianu" << endl;
		cin >> arr[i];		
	}
	
	cout << "dla jakiej liczby sprawdz rozwiazanie" << endl;
	cin >> w;
	int u = 0;

	for(int i = 0; i < n+1; i++){
		u = arr[i] + u;
		
		if(i != n){
			u = w * u;
		}
		
	}
	cout << "wynik: " << u;




}
