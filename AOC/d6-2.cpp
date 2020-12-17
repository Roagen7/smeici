#include <bits/stdc++.h>

using namespace std;
int count(vector<string> group){
	string found = " ";
	int counter = 0;
	if(group.size() == 1){
		return group[0].length();
	}
			
	for(int i = 0; i < group.size(); i++){
		for(char k : group[i]){
			bool flag = true;
			for(int j = 0; j < group.size(); j++){
				if(j != i && group[j].find(k) == -1){
					flag = false;	
				}	
			}	
			if(flag && found.find(k) == -1){
				counter++;
				found += k;	
			
			}		
		}
	}	


	return counter;

}




int main(){
	ifstream INPUT("input");

	vector<string> current;
	int SUM = 0;
	while(!INPUT.eof()){
		string line;
		getline(INPUT,line);
		current.push_back(line);
		if(line.empty()){
			current.pop_back();
			for(string s : current){
				cout << s << endl;
			}
		
			SUM += count(current);
			current.clear();		
		}
	}
	cout << SUM << endl;

	
	}



