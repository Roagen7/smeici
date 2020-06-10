#include <iostream>

using namespace std;

int n;
float arr[20];

float horner(int i, float w,float u){
	u = w * u;
	if(i == n){	
		return arr[i] + u;
	}

	return horner(i+1,w,arr[i] + u);
}

int main(){
	int w;
	float a;
	float b;
	cout << "podaj st. W(x)" << endl;
	cin >> n;
	

	for(int i = 0; i < n+1; i++){
		cout << "podaj " << i + 1 << " wspolczynnik" << endl;
		cin >> arr[i];	
	}
	float d = 0.001;
	float fa = 1;
	float fb = 1;
	
	while(fa * fb > 0){
		cout << "podaj a i b" << endl;
		cin >> a;
		cin >> b;

		fa = horner(0,a,0);
		fb = horner(0,b,0);
	
	}
	float valX = (b+a)/2;	
	float fMid = horner(0,valX,0);
	while(abs(fMid) > d){

		valX = (b+a)/2;
		fMid = horner(0,valX,0);
		if(fa * fMid < 0){
			b = valX;
		} else {
			a = valX;
		}

	}

	
	cout << "miejsce zerowe to: " << valX;
}


