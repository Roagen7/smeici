#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair



using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef deque<deque<deque<bool>>> ms;


void read_space(ms space){
	for(deque<deque<bool>> z : space){
		for(deque<bool> y: z){
			for(bool x : y){
				cout << x << " ";
			}
			cout << endl;
		}
		cout << "------" << endl;
	}
}


// SPACE[z][y][x];
// z
// /\   -,y
// |    /
// |   / 
// |  / 
// | / 
// |/ 
//  ------------->x


ms SPACE;
int shift = 0;


void add_rows_begin(){
	deque<deque<bool>> y;
	
		
	SPACE.push_front(y);	
	

	for(int i = 0; i < SPACE[0].size(); i++){
		deque<bool> x;
		for(int j = 0; j < SPACE[0][0].size(); j++){
			x.PB(0);
		}
		y.PB(x);
	}
//	for(int i = 0; i < SPACE.size(); i++){
//		SPACE[i].push_front(deque<bool> (SPACE[0].size(),0));
//	}	
	


	shift++;
}


bool get_cube(int z, int y, int x){
	
	z += shift;
	y += shift;
	//x+= shift;
	if(z < 0 || x < 0 || y < 0){
		return 0;
	} 
	if(z >= SPACE.size() || y >= SPACE[0].size() || x >= SPACE[0][0].size()){
		return 0;
	}
	
	return SPACE[z][y][x];
	
}




int count_neighbors(int z, int y, int x){
	cout << SPACE[z][y][x] << endl;	



	return 1;


}


ms modify_space(){
	ms mod_SPACE;


	return mod_SPACE;
}





int main(){
	ms templateSpace = {{{0,1,1,0},
			    {0,0,0,0},
			    {0,1,1,0}},

	   		   {{0,1,1,0},
			   {0,1,1,0},
			   {0,1,1,1}},
	
	};
	SPACE = templateSpace;
	add_rows_begin();
	cout << get_cube(0,0,1);
}
