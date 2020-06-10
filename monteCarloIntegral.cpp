#include <iostream>
#include <random>


using namespace std;

float f(float x){

	return 3 * x * x + 2 * x + 7 ;
}


int main(){

	int n,a,b,k;
	cout << "podaj n" << endl;
	cin >> n;
	
	cout << "podaj a i b";
	cin >> a;
	cin >> b;
	int c = f(b); 
	int pods = b - a;
	float points[n][2];
		
	for(int i = 0; i < n; i++){
		points[i][0] = (b-a)* (float)rand()/RAND_MAX + a;
		points[i][1] = c* (float)rand()/RAND_MAX;
	}

	for(int i = 0; i < n; i++){
		if(points[i][1] < f(points[i][0])){
			k+= 1;
		}
	}
	
	cout << "pole: " << k * (b - a)*c / n;

}
