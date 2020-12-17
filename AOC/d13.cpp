#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;





int main(){
	ifstream INPUT("input");
	int estimate;
	vi busses;
	vi mins;

	string datas;
	INPUT >> estimate;
	INPUT >> datas;
	string currentNumb;
	int min = 0;
	for(char c : datas){
		if(c == ','){
			if(currentNumb == "x"){
				currentNumb = "";
				min++;
				continue;
			}	
			busses.PB(atoi(currentNumb.c_str()));
			mins.PB(min);
			currentNumb = "";
			min++;
			continue;
		}

		currentNumb += c;	
	}

	int64_t n = 1;
	int64_t step = 1;

	for(int i = 0; i < busses.size(); i++){
		int id = busses[i];
		int index = mins[i];
		
		while((n + index) % id != 0){
			n += step;
		}
		step *= id;
	}
	cout << n << endl;

}
