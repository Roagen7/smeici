#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


void binSrc(vi A, int val){
	int a = 0;
	int b = A.size();
	do{
		int piv = (b+a)/2;
		if(A[piv] == val){
			cout << piv; 
			return;
		} else if(A[piv] > val)
	       		b = piv;		
		else 
			a = (a+b+1)/2;
	}while(a!=b);
	cout << "-1" << endl;
	return;
}

int main(){
	binSrc({1,3,5,8,10},5);	
}
