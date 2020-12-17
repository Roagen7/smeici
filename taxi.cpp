#include <iostream>
#include <math.h>

using namespace std;

// T(2) = a^3 + b^3 ; a^3 + b^3

bool isTaxi(int num){
	int SEARCH = 2;
	int notEqual;	
	for(int i = 1; pow(i,3) < num; i++){
		if(SEARCH == 0){
			break;
		}
		for(int j = 1; pow(j,3) + pow(i,3) <= num; j++){
			if(pow(j,3) + pow(i,3) == num && notEqual != i){
				notEqual = j;
				SEARCH--;
				break;
			}
		}
	}
	if(SEARCH == 0){
		return true;
	}
	return false;


}

void nthTaxi(int n){
	int counter = 0;
	int number = 1729;
	
	while(counter < n){
		if(isTaxi(number)){
			counter++;
			cout <<counter << ": "<<number << endl;
		}
		number++;
	}
}



int main(){
	
	cout<<"program wypisuje n pierwszych liczb taksowkowych Ta(2) czyli takich ktore mozna przedstawic na dwa rozne sposoby za pomoca sumy szescianow dwoch liczb" << endl;
	int n;
	cout << "wprowadz n" << endl;
	cin >>n;
	nthTaxi(n);

}
