#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 1000000+5;

double acc[MAX], fm[MAX], auc[MAX], nsv[MAX];

main(int argc, char* argv[]) {
	ifstream fin(argv[1]);
	int i;
	for (i = 0; i < 100; i++)
		fin >> acc[i];
	for (i = 0; i < 100; i++)
		fin >> fm[i];
	for (i = 0; i < 100; i++)
		fin >> auc[i];	
	for (i = 0; i < 100; i++)
		fin >> nsv[i];

	for (i = 0; i < 100; i++)
		cout << acc[i] / 10 << '\t';
	cout << endl;
	for (i = 0; i < 100; i++)
		cout << fm[i] / 10 << '\t';
	cout << endl;
	for (i = 0; i < 100; i++)
		cout << auc[i] / 10 << '\t';
	cout << endl;
	for (i = 0; i < 100; i++)
		cout << nsv[i] / 10 << '\t';
	cout << endl;
		
	return 0;	
}
