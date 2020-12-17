#include <bits/stdc++.h>

using namespace std;


int countGroup(string ans){
	
	
	int counter = 0;
	for(int i = 0; i < ans.length(); i++){
		if(ans.substr(0,i).find(ans[i]) == -1){
			counter++;	
		}	
	}



	return counter;
}

int main(){
	ifstream INPUT("input");
	string current = "";
	int SUM = 0;
	while(!INPUT.eof()){
		string line; 
		getline(INPUT,line);
		current += line;
		if(line.empty()){
			SUM += countGroup(current);
			
			current = "";	
		}	
	}
	cout << SUM << endl;	
}
