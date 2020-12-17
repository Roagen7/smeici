#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef unsigned int uint;




int main(){
	uint M, V = 0;
	vector<uint> rz;
	vector<vector<float>> dane;
	ifstream INPUT("plecak.txt");
	INPUT >> M;
	const uint begin_M = M;
	int k = 0;
	while(!INPUT.eof()){
		vector<float> obecny;
		float w, p;
		INPUT >> w;
		INPUT >> p;
		obecny.PB(p/w);
		obecny.PB(w);
		obecny.PB(p);
		obecny.PB(k);
		dane.PB(obecny);
		k++;
	}
	dane.pop_back();
	sort(dane.rbegin(), dane.rend());
	//0:stosunek 1: waga 2: wartosc p 

	int i = 0;
	//wariant ogólny problemu O(nlogn);
	while(i != dane.size()){
		int modM = M/dane[i][1];	
		M -= modM * dane[i][1];
		V += modM * dane[i][2];
		i++;
		for(int j = 0; j < modM; j++){
			rz.PB(dane[i][3]);
		}
	}
	// wariant decyzyjny problemu O(nlog)
	/*
	for(vector<float> rz : dane){
		if(M - rz[1] >= 0){
			V+= rz[2];
			M-= rz[1];
		} 
	}			
	cout << V << endl;
	*/




	/*		
	for(vector<float> o:dane){
		for(float x : o){
			cout << x << " ";
		}
		cout << endl;
	}

	*/

	cout << "wartosc: " << V << endl << "waga: " << begin_M - M << endl << "kolejnosc pakowania: ";
	for(int r : rz){
		cout << r << " ";
	}
	cout << endl;


	
}
