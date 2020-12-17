#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;



vi nom = {500,200,100,50,20,10,5,2};
vi wydane;

int main(){
	int V;
	cin >> V;
	int i = 0;
	
	for(int i = 0; i < nom.size(); i++){
		int modV = V/nom[i];
		V -= nom[i] * modV;
		for(int j = 0; j < modV; j++){
			wydane.PB(nom[i]);
		}
	}
	if(V != 0){
		cout << "nie da sie wydac" << endl;
	} else {
		for(int w : wydane){
			cout << w << endl;
		}	
	}
			
	

	
	
}



