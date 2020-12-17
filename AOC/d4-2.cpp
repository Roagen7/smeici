#include <bits/stdc++.h>

using namespace std;


bool checkValue(string valName, string data){
	if(data.find(valName) == -1){
		return false;	
	
	}


	string temp = data.substr(data.find(valName),data.length());
	string val = temp.substr(temp.find(":")+1,temp.find(" ")-temp.find(":")-1);

	
	if(valName == "byr"){
		if(val.length() != 4){
			return false;
		}
		int y = atoi(val.c_str());

		if(y < 1920 || y > 2002){
			return false;
		}

	}
	if(valName == "iyr"){
		if(val.length() != 4){
			return false;
		}
		int y = atoi(val.c_str());

		if(y < 2010 || y > 2020){
			return false;
		}		
	}
	if(valName == "eyr"){
		if(val.length() != 4){
			return false;
		}
		int y = atoi(val.c_str());

		if(y < 2020 || y > 2030){
			return false;
		}		
	}
	if(valName == "hcl"){
		if(val.length() != 7){
			return false;
		}
		if(val.find("#") == -1){
			return false;
		}
	}
	if(valName == "ecl"){
		if(val == "amb" || val == "blu" || val == "brn" || val == "gry" || val == "grn" || val == "hzl" || val == "oth"){
			return true;
		}
		return false;
	}
	if(valName =="pid"){
		if(val.length() != 9){
			return false;
		}
	}
	if(valName == "hgt"){
		if(val.find("cm")!= -1){
			int dat = atoi(val.substr(0,val.find("cm")).c_str());	
			if(dat < 150 || dat > 193){
				return false;
			}
		} else if(val.find("in")!= -1){
			int dat = atoi(val.substr(0,val.find("in")).c_str());	
			if(dat < 59 || dat > 76){
				return false;
			}
		} else {
			return false;
		}


	
	}

	return true;
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
				if(!checkValue(names[i],currentRecord)){
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
