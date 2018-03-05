#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX = 1000000+5;

char line[MAX];

main(int argc, char* argv[]) {
	ifstream fin0(argv[1]);
	ifstream fin1(argv[2]);
	double c = atof(argv[3]);
	int i, n = 0, m = 0;
	while (fin0.getline(line, MAX)) n++;
	while (fin1.getline(line, MAX)) m++;

	for (i = 0; i < n; i++)
		cout << 1 << endl;
	for (i = 0; i < m; i++)
		cout << c << endl;

	return 0;
}
