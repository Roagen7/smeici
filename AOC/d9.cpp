#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


vector<unsigned long long> amble;

bool validate(int n){
	
	for(int v : amble){
		for(int c : amble){
			if(v != c && v + c == n){
				return true;	
			}
		}
	}

	return false;
}


long long sumNM(int n, int m){
	unsigned long long sum = 0;
	for(int i = n; i <=m; i++){
		cout << sum << endl;
		sum += amble[i];	
	}

	return sum;

}


void findSmallBig(int n, int m){
	unsigned long long max = amble[n];
	unsigned long long min = amble[n];
	
	for(int i = n+1; i <= m; i++){
		if(amble[i] > max){
			max = amble[i];
		}
		if(amble[i] < min){
			min = amble[i];
		}
	}
	cout << max + min << endl;

}


int main(){
	ifstream INPUT("input");

	int preamble_size = 25;
	long long sum = 0;
	vector<long long> currentSeq;

	while(!INPUT.eof()){
		long long current;
		INPUT >> current;
		amble.PB(current);
		if(INPUT.fail()){
			break;
		}
	}

	findSmallBig(479,495);
	/*
	for(int i = 0; i < amble.size(); i++){
		for(int j = i+1; j < amble.size(); j++){
			if(sumNM(i,j) == 258585477){
				cout << i <<"  " << j << endl;
				return 0;
			}
		
		} 
	}
	*/
}
