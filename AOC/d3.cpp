#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream INPUT("input");	
	vector<string> path;

	while(!INPUT.eof()){
		string currentLine;
		INPUT >> currentLine;
		path.push_back(currentLine);
	}
	int RIGHT = 1;


	int multiply = path.size()*RIGHT/path[0].length();
	for(int i = 0; i < path.size(); i++){
		string cPart = path[i];
		for(int j = 0; j < multiply; j++){
			path[i]+= cPart;
		
		}		
	}	
	int x = 0;
	int treeCount = 0;
	for(int y = 0; y < path.size(); y+=2){
		if(path[y][x] == '#'){
			treeCount++;
		}	
		x+= RIGHT;
	} 
	cout << treeCount << endl;

	}
