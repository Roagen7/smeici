#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;



string format_duration(int seconds){
	if(seconds == 0){
		return "now";
	}


	string output = "";
	vector<int> time = {24*3600*365, 24*3600, 3600, 60, 1};
	vector<string> names = {"years", "days", "hours", "minutes", "seconds"};
	vector<string> names_singular = {"year","day","hour","minute","second"};	

	for(int i = 0; i<  time.size(); i++){
		int t = time[i];
		int modSec = seconds/t;
		seconds -= modSec *t;
		
		string separator = seconds ==  0 ? " and " : ", ";


		if(modSec > 1){
			output+= separator + to_string(modSec) + " " + names[i];	
		}
		if(modSec == 1){
			output+= separator+to_string(modSec) + " " + names_singular[i]; 	
		}	
	}	
	
	
	if(output.find("and") == 1)
		return output.substr(5,output.length());
	else 
		return output.substr(2,output.length());

}



int main(){
	
	cout << format_duration(62);



	
	
	}
