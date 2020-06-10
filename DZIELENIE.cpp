#include <iostream>
#include <vector>

using namespace std;



int main(){


	vector<float> W;
	vector<float> Q;
	vector<float> d;
	vector<float> q;
	vector<float> r;	
	int sW,sQ,sd,sq,sr;

	cout << "wprowadz stopien W(x)" << endl;
	cin >> sW;
	cout << "wprowadz stopien Q(x)" << endl;
	cin >> sQ;

	sq = sW - sQ;
	sr = sW - sQ;

	W.resize(sW + 1);
	cout << "wspolczynniki W(x): " << endl;

	for(int i = 0; i <= sW; i++){
		cout << "wspolczynnik " << i << endl;
		cin >> W[i];
	}

	Q.resize(sQ + 1);
	cout << "wspolczynniki Q(x): " << endl;

	for(int i = 0; i <= sQ; i++){
		cout << "wspolczynnik " << i << endl;
		cin >> Q[i];
	}

	d.resize(sW + 1);
	q.resize(sq + 1);
	r.resize(sr+1);

	while(sW >= sQ){
		d.assign(d.size(),0);
		
		for(int i = 0; i <= sQ; i++){
			d[i + sW - sQ] = Q[i];
		}	
		sd = sW;
		q[sW - sQ] = W[sW]/d[sd];
		
		for(int i = 0; i < sq + 1;i++){
			d[i] = d[i] * q[sW-sQ];
		}	

		for(int i = 0; i < sW + 1;i++){
			W[i] = W[i] - d[i];
		}
		sW --;
	}
	

	cout << "stopien wyniku: " << sq << endl;
	cout << "wspolczynniki wyniku: "<<endl;
	for(int i = q.size() - 1; i >= 0; i--){
		cout << "wspolczynnik " << i << " : "<<q[i] << endl;	
	}
	
	cout << "stopien reszty:" << sW<<endl;
	cout << "wspolczynniki reszty:" << endl;
	for(int i = sW; i>=0; i--){
		cout << "wspolczynnik " << i << " : "<<W[i] << endl;	
	}

}


