#include <bits/stdc++.h>

using namespace std;


string encode_rail_fence_cipher(string str, int k){	
	
	string finalStr = "";
	vector<int> levels;
	bool growing = false;
	
	int spiral = 0;
	for(int i = 0; i < str.length(); i++){
		if(i == 0){
			levels.push_back(0);
		} else {
			if(growing){
				spiral--;
			} else {
				spiral++;
			}
			levels.push_back(spiral);
			if(spiral == 0){
				growing = false;
			}
			if(spiral == k - 1){
				growing = true;
			}

		}
	}
	for(int rows = 0; rows < k; rows++){
		for(int i = 0; i < str.length(); i++){
			if(levels[i] == rows){
				finalStr += str[i];	
			}
		}
	
	}


	return finalStr;
}


int main(){
	cout << encode_rail_fence_cipher("ZIEMNIAK",3);
		
	
	
	}
