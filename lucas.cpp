#include <iostream>
#include <math.h>

using namespace std;



long double fibonacci(int n, int w1, int w2){
	if(n == 1){
		return w1;
	}
	if(n == 2){
		return w2;
	}
	int pocz_a = w1;
	int pocz_b = w2;
	int c;
	while(n > 2){
		c = pocz_a + pocz_b;
		pocz_a = pocz_b;
		pocz_b = c;
		n--;
	}

	return c;

}


int main(){
	int n;
	int wybOOr;
	int wyro1;
	int wyro2;
	bool APP_ON = true;
	const long double PHI = 1.6180339887;
	cout << "liczby lucasa to taki ciag liczb ze: 2,1,3,4,7,11,18 ..." << endl;
	cout <<"jedyna roznica miedzy ciagiem fibonacciego to pierwsze wyrazy 2 i 1" << endl;
	while(APP_ON){
	cout << "1)n-ty wyraz ciagu lucasa 2)n wyrazow ciagu lucasa i zlota proporcja 3)fraktalne tworzenie kolejnych wyrazow lucasa z ciagu fibonacciego ";
	cout << "4) stworz wlasny ciag z rodziny zlotych ciagow 5) wyjscie" << endl;
	cin >> wybOOr;

	switch(wybOOr){
		case 1:
			cout << "podaj n" << endl;
			cin >> n;
			cout << fibonacci(n, 2, 1) << endl;
			break;
		case 2:
			cout << "podaj n" << endl;
			cin >> n;
			for(int i = 1; i <= n; i++){
				cout << fibonacci(i, 2, 1);

				if(i != 1){
					cout << "      "<<fibonacci(i, 2, 1)/fibonacci(i-1, 2, 1);
				}
				cout << endl;
			}

			cout << "jak mozna zauwazyc, wyrazy ciagu lucasa zbiegaja sie do zlotej proporcji" << endl;
			cout << "a co z kolejnymi potegami fi?" << endl;

			for(int i = 1; i < n; i++){
				cout << pow(PHI, i) << "  po zaokragleniu:  " << round(pow(PHI, i)) << endl;
			}
			cout << "po zaokragleniu potega fi daje liczby lucasa, niesamowite !" << endl;
			break;
		case 3:
			cout << "n-ty wyraz ciagu lucasa mozna stworzyc sumujac n wyraz ciagu fibonacciego z n - 2  wyrazem ciagu fibonacciego" << endl;
			cout << "wprowadz n, gdzie n- numer wyrazu ciagu lucasa, po czym zostanie on rozbity na sume wyrazow ciagu fibonacciego" << endl;
			cin >> n;
			cout << fibonacci(n, 2, 1) << " = " << fibonacci(n - 2, 1, 1) << " + " << fibonacci(n, 1, 1) << endl;
			cout << n << "-ty wyraz ciagu lucasa powstaje w wyniku dodania " << n <<"-ego i " << n - 2 << "-ego wyrazu ciagu fibonacciego" << endl;
			break;
		case 4:
			cout << "wprowadz dwa pierwsze wyrazy twojego ciagu z rodziny zlotych ciagow" << endl;
			cin >> wyro1;
			cin >> wyro2;
			cout << "ile pierwszych wyrazow swojego ciagu chcesz wygenerowac" << endl;
			cin >> n;
			for(int i = 1; i <= n; i++){
				cout << fibonacci(i, wyro1, wyro2);
				if(i != 1){
					cout << "      "<<fibonacci(i, wyro1, wyro2)/fibonacci(i-1, wyro1, wyro2);
				}
				cout << endl;
			}
			cout << "kazdy ciag ze zlotej rodziny zbiega sie do fi" << endl;

			break;

		case 5: 
			APP_ON = false;
	}

	}
}


