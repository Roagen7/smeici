#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<char> vc;



vector<string> seats;


void print_matrix(vector<string> MATRIX){
	for(string row : MATRIX){
		for(char col : row){
			cout << col; 	
		}
		cout << endl;
	}
}


int lookUpDiagDownRight(int x, int y){
	int i = 1;
	while(x+i < seats.size() && y+i < seats[0].length()){
		if(seats[x+i][y+i] == '#'){
			return 1;
		}
		if(seats[x+i][y+i] == 'L'){
			return 0;
		}	
		i++;		
	}
	return 0;
}

int lookUpDiagDownLeft(int x, int y){
	int i = 1;
	while(x+i < seats.size() && y-i >= 0){
		if(seats[x+i][y-i] == '#'){
			return 1;
		}
		if(seats[x+i][y-i] == 'L'){
			return 0;
		}	
		i++;		
	}
	return 0;
}

int lookUpDiagUpRight(int x, int y){
	int i = 1;
	while(x-i >= 0 && y+i < seats[0].length()){
		if(seats[x-i][y+i] == '#'){
			return 1;
		}
		if(seats[x-i][y+i] == 'L'){
			return 0;
		}	
		i++;		
	}
	return 0;
}

int lookUpDiagUpLeft(int x, int y){
	int i = 1;
	while(x-i >= 0 && y-i >= 0){
		if(seats[x-i][y-i] == '#'){
			return 1;
		}
		if(seats[x-i][y-i] == 'L'){
			return 0;
		}	
		i++;		
	}
	return 0;
}

int lookUpUp(int x, int y){
	int i = 1;
	while(x-i >= 0){
		if(seats[x-i][y] == '#'){
			return 1;
		}
		if(seats[x-i][y] == 'L'){
			return 0;
		}	
		i++;		
	}
	return 0;
}

int lookUpDown(int x, int y){
	int i = 1;
	while(x+i < seats.size()){
		if(seats[x+i][y] == '#'){
			return 1;
		}
		if(seats[x+i][y] == 'L'){
			return 0;
		}	
		i++;		
	}
	return 0;
}
int lookUpRight(int x, int y){
	int i = 1;
	while(y+i < seats[0].length()){
		if(seats[x][y+i] == '#'){
			return 1;
		}
		if(seats[x][y+i] == 'L'){
			return 0;
		}	
		i++;		
	}
	return 0;
}

int lookUpLeft(int x, int y){
	int i = 1;
	while(y-i >= 0){
		if(seats[x][y-i] == '#'){
			return 1;
		}
		if(seats[x][y-i] == 'L'){
			return 0;
		}	
		i++;		
	}
	return 0;
}

char newCheckTaken(int x,int y){
	int COUNTER = lookUpLeft(x,y) + lookUpRight(x,y) + lookUpDown(x,y) + lookUpUp(x,y) + lookUpDiagUpRight(x,y) + lookUpDiagUpLeft(x,y) + lookUpDiagDownRight(x,y) + lookUpDiagDownLeft(x,y);
	if(COUNTER == 0 && seats[x][y] == 'L'){
		//#
		
		return '#';	
	}
	if(COUNTER >= 5 && seats[x][y] == '#'){
		//L
		return 'L';
	}
	return seats[x][y];

}



char checkTaken(int x, int y){

	int COUNTER = 0;
	if(x != 0){
		if(seats[x-1][y] == '#'){
			COUNTER++;
		}	
	}
	if(x!= seats.size()-1){
		if(seats[x+1][y] == '#'){
			COUNTER++;
		}	
	}
	if(y != 0){
		if(seats[x][y-1] == '#'){
			COUNTER++;
		}
	}
	if(y != seats[x].length()-1){
		if(seats[x][y+1] == '#'){
			COUNTER++;
		}
	}
	if(x != 0 && y!= 0){
		if(seats[x-1][y-1] == '#'){
			COUNTER++;
		}
	}

	if(x!= 0 && y!= seats[x].length()-1){
		if(seats[x-1][y+1] == '#'){
			COUNTER++;
		}
	}

	if(y != 0 && x != seats.size()-1){
		if(seats[x+1][y-1] == '#'){
			COUNTER++;
		}
	}
	
	if(x!= seats.size()-1 && y != seats[x].length()-1){
		if(seats[x+1][y+1] == '#'){
			COUNTER++;
		}
	}

	
	if(COUNTER == 0 && seats[x][y] == 'L'){
		//#
		
		return '#';	
	}
	if(COUNTER >= 4 && seats[x][y] == '#'){
		//L
		return 'L';
	}
	return seats[x][y];
	

}






int main(){
	ifstream INPUT("input");
	while(!INPUT.eof()){
		string current_line;
		getline(INPUT,current_line);
		seats.PB(current_line);	
	}
	vector<string> seats_after = seats;
	bool changed;
	do{	
		changed = false;
		for(int i = 0; i < seats.size(); i++){
			for(int j = 0; j < seats[i].length(); j++){
				seats_after[i][j] = newCheckTaken(i,j);
				if(seats_after[i][j] != seats[i][j]){
					changed = true;
				}	
			}
		}
		print_matrix(seats_after);
		seats = seats_after;
	} while(changed);
	
	int OCCUPIED = 0;
	for(string s : seats){
		for(char c : s){
			if(c == '#'){
				OCCUPIED++;
			
			}
		
		}
	}
	cout << OCCUPIED << endl;
	}
