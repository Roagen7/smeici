#include <bits/stdc++.h>

using namespace std;

void reverseString(string &str){
	for(int i = 0; i < str.length()/2; i++){
		swap(str[i],str[str.length()-1-i]);	
	}
}

int longestUniq(string str){
	int count = 0;
	int maxCount = 0;
	vector<char> last;
	
	for(int i = 0; i < str.length(); i++){
		for(int j = i; j < str.length(); j++){
			for(int k = 0; k < last.size(); k++){
				if(last[k] == str[j]){
					if(count > maxCount){
						maxCount = count;
					}
					count = 0;
					last = {};
				}
			}
			last.push_back(str[j]);
			count++;
		}
		if(count > maxCount){
			maxCount = count;
		}

		last = {};
		count = 0;
			
	}
	if(count > maxCount){
		maxCount = count;
	
	}




	return maxCount;
}

int longestSubstrReverse(string str){
	int count = 0;
	int maxCount = 0;

	for(int i = 0; i < str.length(); i++){
		for(int j = i; j < str.length(); j++){
			string original = str;
			reverse(str.begin() + i, str.begin() + j + 1);
					
			count = longestUniq(str);
			str = original;
			if(count > maxCount){
				maxCount = count;
			}
		}		
	}
	return maxCount;

}


int main(){
	string str1;
	cin >> str1;
	cout << longestSubstrReverse(str1);
	
	
	}
