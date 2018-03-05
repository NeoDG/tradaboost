#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 1000000+5;

double acc[MAX], fm[MAX], auc[MAX], nsv[MAX];
double nacc[MAX], nfm[MAX], nauc[MAX];
char line[MAX];

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

	for (i = 0; i < 100; i++) {
		char name[100] = "result_vote_fmeasure_xx.txt";
		name[21] = i / 10 + '0', name[22] = i % 10 + '0';
		ifstream fin(name);
		
		double value;
		char a[100], b[100], c[100];
		while (fin >> a >> b >> c)
			value = atof(b);
		acc[i] += value;
		fm[i] += atof(a);
		nacc[i] = value, nfm[i] = atof(a);

		strcpy(name, "result_vote_auc_xx.txt");
		name[16] = i / 10 + '0', name[17] = i % 10 + '0';
		ifstream fin0(name);
		fin0 >> a >> value;
		auc[i] += value;
		nauc[i] = value;
		
		strcpy(name, "result_vote_accuracy_xx.txt");
		name[21] = i / 10 + '0', name[22] = i % 10 + '0';
		ifstream fin1(name);
		fin1.getline(line, MAX, '(');
		fin1 >> value;
		nsv[i] += value;
	}

	for (i = 0; i < 100; i++)
		cout << acc[i] << '\t';
	cout << endl;
	for (i = 0; i < 100; i++)
		cout << fm[i] << '\t';
	cout << endl;
	for (i = 0; i < 100; i++)
		cout << auc[i] << '\t';
	cout << endl;
	for (i = 0; i < 100; i++)
		cout << nsv[i] << '\t';
	cout << endl;
	
	ofstream fout(argv[2]);
	for (i = 0; i < 100; i++)
		fout << nacc[i] << '\t';
	fout << endl;
	for (i = 0; i < 100; i++)
		fout << nfm[i] << '\t';
	fout << endl;
	for (i = 0; i < 100; i++)
		fout << nauc[i] << '\t';
	fout << endl;	
	
	return 0;	
}
