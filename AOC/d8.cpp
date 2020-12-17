#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


bool works(vector<string> operations, vi values, int &AOC){
	int AV = 0;
	vector<bool> used(values.size(),false);
	int i = 0;
	int lastJumpIndex = 0;
	int accAfterJump = 0;
	while(!(used[i])){
		used[i] = 1;
		if(operations[i] == "acc")
			AV+= values[i];
		else if (operations[i] == "jmp"){
			i+= values[i];
			continue;	
		}
		
		if(i == operations.size() - 2) break;
		i++;

					
	}
	if(i == operations.size() - 2){
		AOC = AV;
		return true;	
	}
		
	return false;
	




}



void fixes(vector<string> operations, vi values){
	int AOC = 0;
	for(int i = 0; i < operations.size(); i++){
		if(operations[i] == "jmp"){
			operations[i] = "nop";
			if(works(operations,values,AOC)){
				cout << i << endl;	
				cout << AOC << endl;	
			} 
				
			operations[i] = "jmp";
		} 
		if(operations[i] == "nop"){
			operations[i] = "jmp";
			if(works(operations,values,AOC)) 
				cout << i << endl;
			operations[i] = "nop";
		}
	
	
	}		



}


int main(){
	ifstream INPUT("input");
	vector<string> operations;
	vi values;
	int AV = 0;
	do{
		string operation;
		int val;
		INPUT >> operation;
		INPUT >> val;
		if(operation != " "){
			operations.PB(operation);
			values.PB(val);
		}
	} while(!INPUT.eof());
	
	values.pop_back();
	operations.pop_back();
	vector<bool> used(values.size(),false);
	int i = 0;
	int lastJumpIndex = 0;
	int accAfterJump = 0;
	while(!(used[i])){
		used[i] = 1;
		if(operations[i] == "acc")
			AV+= values[i];
		else if (operations[i] == "jmp"){
			i+= values[i];
			continue;	
		}

		i++;
					
	}
	//cout << AV << endl;
	fixes(operations,values);	
}
