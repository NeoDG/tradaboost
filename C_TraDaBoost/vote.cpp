#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 100000+5;

double predict[100][MAX];

main() {
	memset(predict, 0, sizeof(predict));
	
	int i, j, n;
	for (i = 0; i < 100; i++) {
		char name[100] = "result_svm_predict_00.txt";
		name[19] = i / 10 + '0', name[20] = i % 10 + '0';
		ifstream fin(name);
		
		double max = -1e30, min = 1e30;
		for (n = 0; fin >> predict[i][n]; n++) {
			if (predict[i][n] > max) max = predict[i][n];
			if (predict[i][n] < min) min = predict[i][n];	
		}
		
		for (j = 0; j < n; j++) {
			if (predict[i][j] > 0) predict[i][j] /= max;
			else predict[i][j] /= -min;
			if (i) predict[i][j] += predict[i - 1][j];
		}
	}

	for (i = 0; i < 100; i++) {
		char name[100] = "result_vote_predict_00.txt";
		name[20] = i / 10 + '0', name[21] = i % 10 + '0';
		ofstream fout(name);
		
		int last = i / 2 - 1, m = i - last;
		for (j = 0; j < n; j++)
			if (last >= 0)
				fout << (predict[i][j] - predict[last][j]) / m << endl;
			else
				fout << predict[i][j] / m << endl;
	}	
	
	return 0;	
}
