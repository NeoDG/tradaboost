#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 1000000;

int label;
double weight;
char line[MAX];

main(int argc, char* argv[]) {
	ifstream fin(argv[1]);
	ifstream fin0(argv[2]);
	
	cout.precision(8);
	cout.setf(ios::fixed);
	while (fin >> label) {
		fin0 >> weight;
		fin.getline(line, MAX);
		//if (weight < 0.1) continue;
		//if (weight > 2) weight = 2;
		if (label > 0) label = 1;
		if (label < 0) label = -1;
		cout << label << " cost:" << weight << ' ' << line << endl;
	}
	
	return 0;
}
