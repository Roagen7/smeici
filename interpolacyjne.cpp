
#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


void interpolacyjne(vi ciag, int k){
	int ip = 0;
	int ik = ciag.size() - 1;
	int piv;
	
	while(ip <= ik){
		piv = ip + (k-ciag[ip])*(ik-ip)/(ciag[ik]-ciag[ip]);
		if(ciag[piv] == k){
			cout << piv << endl;
			return;
		} else if(k < ciag[piv])
			 ik = piv - 1;
		else 
			ip = piv + 1;

	}
	cout << "-1" << endl;
	return;
}








int main(){
	interpolacyjne({2,4,6,8,10},10);	


	
	
	}
