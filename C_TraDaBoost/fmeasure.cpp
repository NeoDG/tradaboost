#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 1000000+5;

struct instance {
	int label;
	double value;
};

int dcmp(double a) {
	if (a > 0) return 1;
	if (a < 0) return -1;
	return 0;	
}

int cmp(const void* e1, const void* e2) {
	return dcmp(((const instance*) e2)->value - 	((const instance*) e1)->value);
}

int n;
instance list[MAX];

char line[MAX];


main(int argc, char* argv[]) {
	//ifstream predict("task_a_u00_ds1.predict");
	//ifstream test("task_a_u00_ds1.tfidf");
	//ofstream result("task_a_u00_ds1.fmeasure");
	
	ifstream predict(argv[1]);
	ifstream test(argv[2]);
	ofstream result(argv[3]);

	for (n = 0; predict >> list[n].value; n++) {
		test >> list[n].label;
		test.getline(line, MAX);	
	}
	qsort(list, n, sizeof(list[0]), cmp);
	
	result.precision(8);
	result.setf(ios::fixed);
	double max = 0;
	int i, tot = 0, now = 0;
	for (i = 0; i < n; i++)
		if (list[i].label * list[i].value > 0)
			tot++;
	for (i = 0; i < n; i++) {
		if (list[i].label * list[i].value > 0) now++;
		double P = now * 1.0 / (i + 1), R = now * 1.0 / tot, F = 2 * P * R / (P + R);
		result << R << '\t' << P << '\t' << F << endl;
		if (F > max) max = F;
	}
	result << max << endl;
	
	return 0;
}
