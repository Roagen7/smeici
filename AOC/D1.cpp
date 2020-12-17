#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream INPUT("input");	
	
	vector<int> records;

	while(!INPUT.eof()){
		int var;
		INPUT >> var;
		records.push_back(var);		
	}
	
	for(int i = 0; i < records.size(); i++){
		for(int j = 0; j < records.size(); j++){
			for(int k = 0; k < records.size(); k++){
				if(records[i] + records[j] + records[k] == 2020){
					cout << records[i] * records[j] * records[k] << endl;
					return 0;	
			}	
			
			
			}

				


		}	
	}

	
	}
