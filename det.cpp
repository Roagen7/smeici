#include <bits/stdc++.h>

using namespace std;

long long det(vector<vector<long long>> m){
	long long determinant = 0;
	if(m.size() == 1){
		return m[0][0];
	}
	
	if(m.size() == 2){
		return m[0][0] * m[1][1] - m[0][1] * m[1][0];
	
	}
	
	for(long i = 0; i < m.size(); i++){
		vector<vector<long long>> mprim;
		mprim.resize(m.size() - 1);
		for(long j = 1; j < m.size(); j++){
			for(long k = 0; k < m[0].size(); k++){
				if(k != i){
					mprim[j-1].push_back(m[j][k]);	
				}
			}	
		}

		determinant += det(mprim)* pow(-1,i) * m[0][i];

	}
	return determinant;


}



int main(){
	vector<vector<long long>> h  = {
		vector<long long> {2,5,3},
		vector <long long> {1,-2,-1},
		vector <long long> {1,3,4}
	};
	

	cout << det(h);	



	
	
	}
