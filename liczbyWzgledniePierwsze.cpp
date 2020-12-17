#include <iostream>
#include <vector>

using namespace std;

int numOfFactors(int num){
	int counter = 0;
	int i = 2;
	
	while(num != 1){
		if(num % i == 0){
			num /= i;
		       	counter++;	
		} else {
			i ++;
		}
	}


	return counter;
}



void splitToEl(int num, int *arr){
	int i = 2;
	
	while(num != 1){
		if(num % i == 0){
			num /= i;
			*arr = i;
			arr++;
		} else {
			i ++;
		}
	}
	




};

bool common(int *arr1, int *arr2,int n1, int n2){
	for(int i = 0; i < n1; i++){
		for(int j = 0; j < n2; j++){
			if(*arr1 == *arr2){
				return true;
			}
			arr2++;
		}
		arr1++;
	}

	return false;
}

int NWD(int a,int b){
	if(a == b){
		return a;
	}

	if(a > b){
		a = a - b;
	} else {
		b = b - a;
	}
	return NWD(a,b);

}



int main(){
	int a,b,n;


	cout << "liczby wzglednie pierwsze to taka para liczb, ze NWD(a,b) = 1" << endl;
	cout<< "nie jest to jedyna definicja, poniewaz po rozkladzie na czynniki pierwsze";
	cout << " liczby a i liczby b nie maja wspolnych czynnikow" << endl;
	
	cout << "podaj ciag liczb do sprawdzenia, czy sa wzglednie pierwsze" << endl;
	cout << "ile elementow podasz" << endl;
	cin >> n;
	int numbers[n];

	cout<<endl << "podaj liczby do sprawdzenia" << endl;
	for(int i = 0; i < n; i++){
		cout << endl << i + 1 << ": ";
		cin >> numbers[i];		
	}
	int maxFacs = 0;
	for(int i = 0; i < n; i++){
		if(numOfFactors(numbers[i]) > maxFacs){
			maxFacs = numOfFactors(numbers[i]);
		}	
	}
	int factors[n][maxFacs];

	
	for(int i = 0; i <n; i++){
		splitToEl(numbers[i],factors[i]);			
		cout << "liczba: "<<numbers[i] << "  ";
		cout << "jej czynniki pierwsze {" ;

		for(int j = 0; j < numOfFactors(numbers[i]);j++){
			cout << factors[i][j] << ",";
		}
		cout << "}"<<endl;

	}
	
	vector <int> paramiPierwsze1;
	vector <int> paramiPierwsze2;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(NWD(numbers[i],numbers[j]) == 1 && numbers[i] != numbers[j]){
				
				if(numbers[i] > numbers[j]){
					paramiPierwsze1.push_back(numbers[i]);
					paramiPierwsze2.push_back(numbers[j]);
				} else {
					paramiPierwsze1.push_back(numbers[j]);
					paramiPierwsze2.push_back(numbers[i]);
				}
			}
		}	
	}
	
	vector <int> paryL;
	vector <int> paryP;

	for(int i = 0; i < paramiPierwsze1.size(); i++){
		bool flag = true;
		for(int j = 0; j < paryL.size(); j++){
			if((paramiPierwsze1[i] == paryL[j] && paramiPierwsze2[i] == paryP[j]) || (paramiPierwsze2[i] == paryL[j] && paramiPierwsze1[i] == paryP[j])){
				flag = false;
			}
		}
		if(flag){
			paryL.push_back(paramiPierwsze1[i]);
			paryP.push_back(paramiPierwsze2[i]);
		}

	}


	
	cout << "pary liczb wzglednie pierwszych: " << endl;
	if(paramiPierwsze1.size() == 0){
		cout << "brak" << endl;
	
	} else {
		for(int i = 0; i < paryL.size();i++){
			cout << "{" << paryL[i] <<":"<<paryP[i]<<"}" << endl;
	
		}
	}


	int ciaguNWD = numbers[0];

	for(int i = 0; i < n; i++){
		ciaguNWD = NWD(ciaguNWD, numbers[i]);			
	}

	cout << "czy caly ciag jest wzglednie pierwszy(uwaga nie chodzi o pierwszosc parami)? :"; 
	if(ciaguNWD == 1){
		cout << " TAK";
	
	} else {
		cout << " NIE";
	
	}
	cout << endl;


	/*
	cout << "pierwsza: ";
	cin >> a;
	cout <<endl << "druga: ";
	cin >> b;
	

	int n1 = numOfFactors(a);
	int n2 = numOfFactors(b);

	int aArr[n1];
	int bArr[n2];	


	splitToEl(a, aArr);
	splitToEl(b, bArr);
	
	cout << NWD(a,b);
	cout << common(aArr,bArr,n1,n2);

	*/






}


