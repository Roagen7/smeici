#include <iostream>
#include <cstdlib>

using namespace std;


long pow(int k, int n){
	int pw = 1;
	for(int i = 0; i < n; i++){
		pw*= k;
	}  
	return pw;
}



long DEC(int base, string num){
	if(num.length() == 1)
		return atoi(num.c_str());

	return (long) pow(base, num.length()-1) * atoi(num.substr(0,1).c_str()) + DEC(base, num.substr(1,num.length()));
}

double POINT(int base, string num){
	if(num.length() == 1)
		return (double) atoi(num.c_str()) /base;

	return (double) atoi(num.substr(num.length()-1,1).c_str())/pow(base,num.length()) + POINT(base,num.substr(0,num.length()-1));	  
}



int main(){
	string num,p1 = "",p2="";
	int n, m, base;
	double x = 0;
	
	cout << "podaj liczbe zapisana w systemie o podstawie nie wiekszej niz 9" << endl;
	cin >> num;
	cout << "podaj podstawe systemu" << endl;
	cin >> base;
	cout << "podaj liczbe cyfr calkowitych" << endl;
	cin >> n;
	cout << "podaj liczbe cyfr ulamkowych" << endl;
	cin >> m;
	
	
	if(n != 0){
		p1 = num.substr(0,n);	
	}
		
	if(m != 0){
		p2 = num.substr(n+1,m);	
	}
	if(p2.length()){
		x= (double)POINT(base,p2);
	}


	if(p1.length()){
		x+= (double)DEC(base, p1);
	}


	printf("%.8f", x);
	
	
	}
