#include <iostream>

using namespace std;

int n;
int arr[20];

int horner(int i, int w,int u){
	u = w * u;
	if(i == n){	
		return arr[i] + u;
	}

	return horner(i+1,w,arr[i] + u);
}


int main(){
	int w;
	cout << "podaj st. W(x)" << endl;
	cin >> n;
	

	for(int i = 0; i < n+1; i++){
		cout << "podaj " << i + 1 << " wspolczynnik" << endl;
		cin >> arr[i];	
	}
	cout << "podaj liczbe do sprawdzenia" << endl;
	cin >> w;
	cout << horner(0,w,0);
	



}



