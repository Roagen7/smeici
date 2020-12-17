include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

int counter = 0;
vector<vector<string>> bags;
vector<vector<int>> amounts;
vector<string> bag;
vector<string> checked;
vi amount = {0};

void bagParse(string line ){
	if(line.find("bag") == -1 || line.length() == 0) {
		bags.push_back(bag);
		amounts.push_back(amount);
		bag.clear();
		amount.clear();
		amount.push_back(0);
		return; 		
	}
	if(line[0]==' '){
		bag.push_back(line.substr(1,line.find("bag")-1));	
	} else {
		bag.push_back(line.substr(0,line.find("bag")));	
	
	}
	for(int i = 0; i < 4; i++){
		line = line.substr(line.find(" ")+1, line.length());
	}
	if(line.length() == 0) {
		bags.push_back(bag);
		bag.clear();
		amounts.push_back(amount);
		amount.clear();
		amount.push_back(0);
		return;
	}
	int digit = atoi(line.substr(0,1).c_str());
	amount.push_back(digit);
	line = line.substr(1,line.length());
	bagParse(line);
}


bool inChecked(string name){
	for(string b : checked){
		if(b == name){
			return true;
		}
	
	}
	return false;
}


void checkBag(string name){
	for(vs bag : bags){
		bool bagFlag = false;
		for(int i = 0; i < bag.size(); i++){
			if(i != 0 && bag[i] == name){
				checkBag(bag[0]);

				bagFlag = !inChecked(bag[0]);
			}
		}	
		if(bagFlag){
			checked.push_back(bag[0]);
			counter++;
		}	
	}


}



int countBags(string name){
	if(name == "o other"){
		return 1;
	}
	
	int c = 0;
	for(int i = 0; i < bags.size(); i++){
		
		if(bags[i][0] == name){
			bool flag = false;
			for(int j = 0; j < bags[i].size(); j++){
				if(j != 0){
					c+=  amounts[i][j] * countBags(bags[i][j])+amounts[i][j];
				}
			}
				
		}	
	}
	return c;
}



int main(){
	ifstream INPUT("input");
	

	do{
		string line;
		getline(INPUT,line);
		if(line.length() == 0){
			break;
		}
		line[line.length()-1] = ' ';
		bagParse(line);
	}while(!INPUT.eof());
	cout << countBags("shiny gold ");
	/*
	for(int i = 0; i < amounts.size(); i++){
		for(int j = 0; j < amounts[i].size(); j++){
			cout << bags[i][j] << ":"<<amounts[i][j] <<",";
		}
		cout << endl;	
	}
	*/
	
	//checkBag("shiny gold ");
	//cout << counter << endl;
}

