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
				
			char checkChar = ch[0];	
			int min = atoi(range.substr(0,range.find("-")).c_str());
			int max = atoi(range.substr(range.find("-") + 1, range.find(" ") - range.find("-")).c_str());
			int charCount = 0;
			for(int i = 0; i < passw.length(); i++){
				if(passw[i] == checkChar){
					charCount ++;
				}
			}

			if(charCount >= min && charCount <= max){
				COUNTER++;
			}
	
	}	
	cout << COUNTER - 1;	
}
