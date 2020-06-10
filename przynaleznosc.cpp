#include <iostream>

using namespace std;


int main(){

	float x1,x2,y1,y2,x0,y0;
	float const_x;
	float a, b;
	bool NALEZY = true;
	cout << "odcinek start(x1,y1), koniec(x2,y2)" << endl;
	cout << "x1: ";
	cin >> x1;
	cout << "y1: ";
	cin >> y1;
	cout << "x2: ";
	cin >> x2;
	cout << "y2: ";
	cin >> y2;
	
	x0 = 0;
	y0 = 0;
	
	if(x1 - x2 == 0){
		const_x = x1;
		if(!(x0 == const_x && y0 <= max(y1,y2) && y0 >= min(y1,y2))){
			NALEZY = false;
		}	
	} else {
		a = (y1 - y2)/(x1-x2);
		b = y1 - a * x1;
		
		if(y0 == x0 * a + b){
			if(!(x0 <= max(x1,x2) && x0 >= min(x1,x2))){
				NALEZY = false;
			}	

		} else {
			NALEZY = false;
		}

	}
	if(NALEZY){
		cout << "nalezy" << endl;
	} else {
		cout << "nie nalezy" << endl;
	}

}



