#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream INPUT("input");
	int COUNTER = 0;
	while(!INPUT.eof()){
		string range;
		string ch;
		string passw;
		INPUT >> range;
		INPUT >> ch;
		INPUT >> passw;
		cout << range << " " << ch << " " << passw << endl;			
			char checkChar = ch[0];	
			int firstIndex = atoi(range.substr(0,range.find("-")).c_str());
			int secondIndex = atoi(range.substr(range.find("-") + 1, range.find(" ") - range.find("-")).c_str());
			int charCount = 0;
			bool A = passw[firstIndex-1] == checkChar;	
			bool B = passw[secondIndex-1] == checkChar;
			if((A || B) && (!A || !B)){
				COUNTER++;
			}
	
	}	
	cout << COUNTER - 1;	
}
