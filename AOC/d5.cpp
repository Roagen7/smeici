#include <bits/stdc++.h>

using namespace std;


int getRow(string rowString){
	int currentMin = 0;
	int currentMax = 127;
	for(int i = 0; i < 7; i++){
		if(rowString[i] == 'F'){
			currentMax = (currentMax + currentMin )/2;
		} else {
			currentMin = (currentMax+currentMin+1)/2;
		}	
	}

	return currentMax;

}


int getCol(string colString){
	int currentMin = 0;
	int currentMax = 7;
	for(int i = 0; i < 3; i++){
		if(colString[i] == 'L'){
			currentMax = (currentMax + currentMin)/2;
		} else {
			currentMin = (currentMax+currentMin+1)/2;
		}
	}
	return currentMax;

}

int countSeatId(int col, int row){
	return row * 8 + col;
}




int main(){
//	string in = "BBFFBBFRLL";
//	cout << countSeatId(getCol(in.substr(7,3)),getRow(in.substr(0,7)));
	ifstream INPUT("input");	

	int maxId=  0;
		
	bool seatsTaken[895];
	for(int i = 1; i <= 894; i++){
		seatsTaken[i] = 0;
	
	}

	while(!INPUT.eof()){
		string in;
		INPUT >> in;
		if(in == "*"){
			break;
		}

		cout << in << endl;	
		int id = countSeatId(getCol(in.substr(7,3)),getRow(in.substr(0,7)));
		seatsTaken[id] = 1;


		if(id > maxId){
			maxId = id;
		}
	}
	bool wasZero = false;


	for(int i = 1; i <= 894; i++){
		
		cout << i << "    :    " << seatsTaken[i] << endl;
	
	} 



	
	
}
