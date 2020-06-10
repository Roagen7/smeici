#include <iostream>
#include <string>

using namespace std;


int main(){
	string num;
	cout << "podaj liczbe bin" << endl;
	cin >> num;

	int w = 2;
	float w2 = 0.5;
	float u = 0;
	float uPrime = 0;
	int startNext = num.length();

	for(int i = 0; i < num.length(); i++){
		if(num[i] == '.'){
			startNext = i+1;
			break;
		}	

		if(num[i] == '0'){
			u =  u * w;	
		} else {
			u = 1 + w* u;
		
		}
	}
	
	for(int i = num.length() - 1; i >= startNext; i--){
		
		if(num[i] == '0'){
			uPrime = uPrime * w2;
		} else {
			uPrime = 1 + uPrime * w2;
		}
	}
	uPrime = uPrime * w2;

	cout << "liczba w dec: "<< u + uPrime;
	




}











