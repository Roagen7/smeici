#include <bits/stdc++.h>

using namespace std;


string getValue(string valName, string data){
	if(data.find(valName) == -1){
		return " ";	
	
	}


	string temp = data.substr(data.find(valName),data.length());
	return temp.substr(temp.find(":")+1,temp.find(" ")-temp.find(":"));

}






int main(){

	ifstream INPUT("input");
	int i = 0;	
	string currentRecord;
	string names[7] = {"byr","eyr","pid","hgt","iyr","ecl","hcl"};
	int counter = 0;


	while(!INPUT.eof()){
		string currentLine;
		getline(INPUT,currentLine);
		
		if(currentLine.empty()){
			bool flag = true;
			for(int i = 0; i < 7; i++){
				if(getValue(names[i],currentRecord)==" "){
					flag = false;
				} 
			}
			if(flag){
				counter++;
			}

			currentRecord = ""; 
		} else {
			currentRecord += currentLine + " ";
		}
		
	}
	cout << counter << endl;

	
}
