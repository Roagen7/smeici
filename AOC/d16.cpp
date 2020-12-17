#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

vector<vi> rules;

vector<string> names_in_given;

vi parseTicket(string str)
{
	vi ticket;
	stringstream ss(str);
	for (int num; ss >> num;)
	{
		ticket.PB(num);
		if (ss.peek() == ',')
		{
			ss.ignore();
		}
	}

	return ticket;
}

void parseRule(string str)
{
	int r1_1, r1_2, r2_1, r2_2;
	names_in_given.PB(str.substr(0, str.find(":") - 1));

	str = str.substr(str.find(" ") + 1, str.length());
	string range1 = str.substr(0, str.find(" ")), range2;
	str = str.substr(str.find(" ") + 1, str.length());
	range2 = str.substr(str.find(" ") + 1, str.length());
	r1_1 = atoi(range1.substr(0, range1.find("-")).c_str());
	r1_2 = atoi(range1.substr(range1.find("-") + 1, str.length()).c_str());
	r2_1 = atoi(range2.substr(0, range2.find("-")).c_str());
	r2_2 = atoi(range2.substr(range2.find("-") + 1, str.length()).c_str());

	rules.PB(vi{r1_1, r1_2, r2_1, r2_2});
}

long checkTicket(vi ticket)
{
	long SUM = 0;
	for (int v : ticket)
	{

		//cout << v << " ";
		bool flag = false;
		for (vi rule : rules)
		{
			if ((v >= rule[0] && v <= rule[1]) || (v >= rule[2] && v <= rule[3]))
			{
				flag = true;
			}
		}
		if (!flag)
		{
			SUM += v;
		}
	}
	//cout << endl;
	return SUM;
}

bool validate(vi ticket)
{
	for (int v : ticket)
	{
		bool flag = false;

		for (vi rule : rules)
		{
			if ((v >= rule[0] && v <= rule[1]) || (v >= rule[2] && v <= rule[3]))
			{
				flag = true;
			}
		}

		if (!flag)
		{
			return false;
		}
	}
	return true;
}

vector<vi> posibilities;

void lookForTheOne(vector<vi> tic)
{

	for (int j = 0; j < tic[0].size(); j++)
	{

		vi j_possible;
		for (int i = 0; i < rules.size(); i++)
		{
			vi rule = rules[i];
			bool flag = true;

			for (vi ticket : tic)
			{
				int v = ticket[j];
				if ((v >= rule[0] && v <= rule[1]) || (v >= rule[2] && v <= rule[3]))
				{
				}
				else
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				j_possible.PB(i);
			}
		}
		posibilities.PB(j_possible);
	}
}

void removeAllOfValue(int val){
	for(int j = 0; j < posibilities.size(); j++){
		for(int i = 0; i < posibilities[j].size(); i++){
			if(posibilities[j][i] == val){
				posibilities[j].erase(posibilities[j].begin()+i);
			}
		}
	}

}


int main()
{
	ifstream INPUT("input");
	ofstream OUTPUt("output");
	vi myTicket;
	vector<vi> tickets;
	vector<vi> valid_tickets;
	string line;

	while (!INPUT.eof())
	{
		getline(INPUT, line);
		if (line == "your ticket:")
		{
			break;
		}

		parseRule(line);
	}
	rules.pop_back();

	INPUT >> line;
	myTicket = parseTicket(line);
	getline(INPUT, line);
	getline(INPUT, line);
	getline(INPUT, line);
	while (!INPUT.eof())
	{
		vi ticket;
		getline(INPUT, line);
		ticket = parseTicket(line);
		tickets.PB(ticket);
	}
	/*
	long long count = 0;

	for(vi t : tickets){
		count += checkTicket(t);
	
	}
	cout << count << endl;
	*/
	for (vi t : tickets)
	{
		if (validate(t))
		{
			valid_tickets.PB(t);
		}
	}
	valid_tickets.pop_back();
	lookForTheOne(valid_tickets);
	
	int inOrder[20];
	/*	
	for(int i = 0; i < 20; i++){
		vi p = posibilities[i];
		for(int a: p){
			cout << a << " ";
		}	
		cout << endl;
	}
	*/


	for(int i = 0; i < 20; i++){
		for(int j = 0; j < posibilities.size(); j++){
			vi p = posibilities[j];
			if(p.size() == 1){
				inOrder[j] = p[0];
				removeAllOfValue(p[0]);	
				
			}		
		}			
	}

	
	
	int64_t multiple = 1;
	for(int i = 0; i < 20; i++){
		int o = inOrder[i];
		
		if(names_in_given[o].find("depar") != -1){
			cout << names_in_given[o] << endl;
			cout << myTicket[i] << endl;
			multiple *= myTicket[i];
		}	
	}
	OUTPUt << multiple;
}
