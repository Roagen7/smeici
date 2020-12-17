#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define E first
#define N second


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


pair<int,int> wayp_loc;
pair<int,int> ship_loc;

int face = 90;


char translate(){
	int dir = face/90;

	int s = dir%4;
	switch(s){
		case 0:
			return 'N';
		break;
		
		case -3:
		case 1:
			return 'E';
		break;

		case 2:
		case -2:
			return 'S';
		break;
		case 3:
		case -1:
			return 'W';
		break;
	}	
	return 'E';
}


void rotate(char side, int degrees){
	
	/*
	switch(side){
		case 'L':
			face-= degrees;
		break;
		
		case 'R':
			face+= degrees;
		break;
		
	}*/
	
			
		for(int i = 0; i < degrees/90; i++){
			int dX = wayp_loc.E - ship_loc.E;
			int dY = wayp_loc.N - ship_loc.N;

			wayp_loc.E = ship_loc.E;
			wayp_loc.N = ship_loc.N;

			switch(side){
			case 'R':
				wayp_loc.E += dY;
				wayp_loc.N -= dX;
			break;
			case 'L':
				wayp_loc.E -= dY;
				wayp_loc.N += dX;
			break;
		
		
		}
			
	}
	



}

void forward(int num){
	int move_north = wayp_loc.N - ship_loc.N;
	int move_east = wayp_loc.E - ship_loc.E;
	

	for(int i = 0; i < num;i++){
		wayp_loc.N += move_north;
		ship_loc.N += move_north;
	
		wayp_loc.E += move_east;
		ship_loc.E += move_east;
	}
	

}


void move(char side, int num){
	
	switch(side){
		case 'N':
			wayp_loc.N += num;
		break;

		case 'S':
			wayp_loc.N -= num;
		break;

		case 'E':
			wayp_loc.E += num;
		break;

		case 'W':
			wayp_loc.E -= num;
		break;
	}	
}


int main(){
	
	ifstream INPUT("input");
	ship_loc.N = ship_loc.E = 0;
	wayp_loc.E = 10;
	wayp_loc.N = 1;


	
	while(!INPUT.eof()){
		string line;
		INPUT >> line;
		if(line.length() == 0){
			break;
		}
		int param = atoi(line.substr(1,line.length()).c_str());	
		char instr = line[0];
		
		switch(instr){
			case 'L':
			case 'R':
				rotate(instr, param);
			break;

			case 'N':
			case 'S':
			case 'W':
			case 'E':
				move(instr, param);
			break;

			case 'F':
				forward(param);
		}
	
	}

	cout << ship_loc.E << "E " << ship_loc.N << "N " << endl;
	cout << wayp_loc.E << "E " << wayp_loc.N << "N " << endl;
	cout << "Manhattan distance: " << abs(ship_loc.E) + abs(ship_loc.N);	
	}
