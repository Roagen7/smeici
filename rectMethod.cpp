#include <iostream>


using namespace std;

float f(float x){
	return 3 *  x*x + 2 * x + 7;
}






int main(){
	float n,x1,x2;
	cout << "podaj n" << endl;
	cin >> n;
	cout << "podaj x1 i x2" << endl;
	cin >> x1;
	cin >> x2;
	
	float dx;
	dx = (x2 - x1)/n;
	float A = 0;
	
	float x = x1;
	
	for(int i = 0; i < n; i++){
		A+= dx * f(x);
	       	x += dx;	
	}
	
	cout << "pole pod krzywa " << A;
}

