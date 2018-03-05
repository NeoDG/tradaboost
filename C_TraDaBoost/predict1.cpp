#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 1000000+5;

char line[MAX];

int n;
double predict[MAX], temp[MAX];

int dcmp(double a) {
	if (a > 0) return 1;
	if (a < 0) return -1;
	return 0;	
}

int cmp(const void* e1, const void* e2) {
	return dcmp(*(const double*) e1 - *(const double*) e2);	
}

main(int argc, char* argv[]) {
	ifstream train(argv[1]);
	ifstream pred(argv[2]);
	ifstream pred0(argv[3]);
	int theta = atoi(argv[4]);
	
	int pos = 0, neg = 0, label;
	while (train >> label) {
		train.getline(line, MAX);
		if (label >= theta) pos++;
		if (label <= -theta) neg++;	
	}
	double b = (pos - neg) * 1.0 / (pos + neg);
	
	double sum = 0;
	for (n = 0; pred >> predict[n]; n++)
		sum += predict[n];
	sum /= n;	

	int i;
	for (i = 0; i < n; i++)
		pred0 >> temp[i];
	qsort(temp, n, sizeof(temp[0]), cmp);
	int id = n * neg / (pos + neg);
	double x = (temp[id - 1] + temp[id]) / 2;
	
	for (i = 0; i < n; i++)
		cout << predict[i] - x << endl;	
	return 0;	
}
