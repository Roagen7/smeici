#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;



vi adapters(1,0);
vi sub;
int COUNTER = 0;
vector<vi> difArray;

/*
void diffs(int k){
	vi d(3,-1);
	for(int i = k +1; i < adapters.size() && adapters[i] <= adapters[k]+3; i++){
		d[adapters[i]-adapters[k]-1] = i;		
	}

	difArray.PB(d);
	


}
*/





void ac(int k){
	vi d = difArray[k];

	if(k == adapters.size()-1){
		/*
		for(int v : d ){
			cout << v << " ";
		}
		*/
		cout << COUNTER << endl;
		COUNTER++;
		return;
	}
	
	for(int i : d){
		if(i != -1){
			ac(i);
		} 
	}
		

	/*

	if(sub[sub.size()-1] == adapters[adapters.size()-1]){
		for(int s : sub){
			cout << s << " ";
		}
		cout << endl;
		COUNTER++;
	}
	*/	
	return;
}


int main(){
	ifstream INPUT("input");	
		do{
		int current;
		INPUT >> current;
		adapters.PB(current);
	}while(!INPUT.eof());
	adapters.pop_back();	
	sort(adapters.begin(),adapters.end());
	adapters.PB(adapters.back()+3);
	vi diffs;
	vector<int64_t> arrangements(adapters.size(), 0);	
	arrangements.back() = 1;

	for(int i = adapters.size() - 1; i >= 0; i--){
		int c_val = adapters[i];
		int64_t c_arrangement = arrangements[i];
		for(int j = i - 1; j >= 0 && adapters[j]+3 >= c_val; j--){
			arrangements[j]+= c_arrangement;	
		}
	}

	cout << arrangements[0] << endl;

}
