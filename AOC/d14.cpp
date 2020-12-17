#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define A first
#define V second


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


vector<pair<long long, unsigned long long>> memory;


/*
void append_value(int addr,long long  mem,string mask){
	bool flag = false;
	int id = 0;
	for(int i = 0; i < memory.size(); i++){
		if(memory[i].A == addr){
			flag = true;
			id = i;
			break;
		}		
	}
	if(!flag){
		pair<int, unsigned long long> s;
		s.A = addr;
		s.V = 0;
		memory.PB(s);
		id = memory.size() - 1;

	}
	
	
	for(int i = 0; i < mask.length()/2; i++){
		swap(mask[i], mask[mask.length()-1-i]);
	}
	
	for(int i = 0; i < mask.length(); i++){
		if(mask[i] == '0'){
			mem &= ~(1UL << i);
		
		} else if(mask[i] == '1'){
			mem |= 1UL << i;	
		} else if(mask[i] == 'X'){
			continue;
		}
	}	
	memory[id].V = mem;

	
}*/

vector<string> combinations;


void generate_combinations(string mask, int current_index){
	
	for(int i = current_index; i < mask.size(); i++){
		if(mask[i] == 'X'){
			mask[i] = '0';
			generate_combinations(mask, i);	
			mask[i] = '1';
			generate_combinations(mask, i);	
		}
	}	
	
	bool flag = true;	
	for(string s: combinations){
		if(s == mask){
			flag = false;
		}
	}
	if(flag){
		combinations.PB(mask);
	}
}

void append_value_new(long long addr, long long mem, string mask){
	vector<bool> changing(mask.length(),false);
	for(int i = 0; i < mask.length(); i++){
		if(mask[i] == 'X')
			changing[i] = true;
	
	}

	for(int i = 0; i < changing.size()/2; i++){
		swap(changing[i],changing[changing.size()-i-1]);
	}

	
	generate_combinations(mask,0);
	const ll ADDRESS = addr;
	vector<ll> addresses;
	for(string s: combinations){
		for(int i = 0; i < s.length()/2; i++){
			swap(s[i],s[s.length()-i-1]);
		}
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '1'){
				addr |= (1UL<<i);
			} else if(s[i] == '0' && changing[i]){
				addr &= ~(1UL<<i);
			
			}
		}
	bool flag = false;
	int id = 0;
	for(int i = 0; i < memory.size(); i++){
		if(memory[i].A == addr){
			flag = true;
			id = i;
			break;
		}		
	}
	if(!flag){
		pair<unsigned long long, unsigned long long> s;
		s.A = addr;
		s.V = 0;
		memory.PB(s);
		id = memory.size() - 1;

	}
		memory[id].V = mem;
		addr = ADDRESS;
	}
	combinations.clear();
}



int main(){
	string current_mask = "";
	ifstream INPUT("input");
	while(!INPUT.eof()){
		string h, bin;
		INPUT >> h;
		if(h == "mask"){
			INPUT >> bin;
			INPUT >> current_mask;	
		} else {
			long long m_val;
			INPUT >> bin;
			INPUT >> m_val; 
			long long m_addr;
			m_addr = atoi(h.substr(h.find('[')+1,h.find(']')-h.find('[')-1).c_str());		
			if(m_addr != 0){
				append_value_new(m_addr,m_val,current_mask);	
	
			}
				
		}
	}
	int64_t SUM = 0;
	
	for(pair<unsigned long long, unsigned long long> m : memory){
		cout << m.A << "  " <<m.V<< endl;
		SUM += m.V;
	}

	
	cout << SUM << endl;


}
