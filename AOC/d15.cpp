#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
//                      1  2 3 4  5 6 
vector<int64_t> nums = {20,0,1,11,6,3};


int64_t look_back(int pos){
	for(int i = pos - 1; i >= 0; i--){
		if(nums[pos] == nums[i]){
			return pos - i;
		}
	}

	return 0;

}


int nthIndex(int64_t n){
	map<int64_t,int64_t> indexes;	
	map<int64_t,int64_t>::iterator itr;
	for(int i = 0; i < nums.size(); i++){
		indexes.insert(pair<int64_t,int64_t>(nums[i],i+1));
	}	
	
	int64_t lastValue = nums.back();
	int64_t k = nums.size();
	while(k != n){
		itr = indexes.find(lastValue);
		if(itr == indexes.end()){
			indexes.insert(pair<int64_t,int64_t> (lastValue,k));
			lastValue = 0;
		} else {
			lastValue = k-itr->second;
			itr->second = k;
		}
		k++;
	}	


	return lastValue;
}







int main(){
	 cout << nthIndex(30000000);	
	
	}
