#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 1000000+5;

double acc[MAX], fm[MAX], auc[MAX];

main() {
	ofstream fout("results.txt");
	
	int i;
	for (i = 0; i < 10; i++) {
		char name[100] = "fmeasure0_x.txt";
		name[10] = i + '0';
		ifstream fin(name);
		
		char a[100], b[100], c[100];
		while (fin >> a >> b >> c)
			acc[i] = atof(b);
		fm[i] = atof(a);
		
		strcpy(name, "auc0_x.txt");
		name[5] = i + '0';
		ifstream fin0(name);
		fin0 >> a >> auc[i];
	}
	
	for (i = 0; i < 10; i++)
		fout << acc[i] << '\t';
	fout << endl;
	for (i = 0; i < 10; i++)
		fout << fm[i] << '\t';
	fout << endl;
	for (i = 0; i < 10; i++)
		fout << auc[i] << '\t';
	fout << endl;
	
	for (i = 0; i < 10; i++) {
		char name[100] = "fmeasure1_x.txt";
		name[10] = i + '0';
		ifstream fin(name);
		
		char a[100], b[100], c[100];
		while (fin >> a >> b >> c)
			acc[i] = atof(b);
		fm[i] = atof(a);
		
		strcpy(name, "auc1_x.txt");
		name[5] = i + '0';
		ifstream fin0(name);
		fin0 >> a >> auc[i];
	}
	
	for (i = 0; i < 10; i++)
		fout << acc[i] << '\t';
	fout << endl;
	for (i = 0; i < 10; i++)
		fout << fm[i] << '\t';
	fout << endl;
	for (i = 0; i < 10; i++)
		fout << auc[i] << '\t';
	fout << endl;	
	
	for (i = 0; i < 10; i++) {
		char name[100] = "fmeasure2_x.txt";
		name[10] = i + '0';
		ifstream fin(name);
		
		char a[100], b[100], c[100];
		while (fin >> a >> b >> c)
			acc[i] = atof(b);
		fm[i] = atof(a);
		
		strcpy(name, "auc2_x.txt");
		name[5] = i + '0';
		ifstream fin0(name);
		fin0 >> a >> auc[i];
	}
	
	for (i = 0; i < 10; i++)
		fout << acc[i] << '\t';
	fout << endl;
	for (i = 0; i < 10; i++)
		fout << fm[i] << '\t';
	fout << endl;
	for (i = 0; i < 10; i++)
		fout << auc[i] << '\t';
	fout << endl;
	
	return 0;	
}


