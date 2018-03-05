#include <fstream>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

const int MAX = 1000000;
const double eps = 1e-8, rate = 2;

int label[MAX];
double predict[MAX], weight[MAX];
char line[MAX];

double calc(double predict, double label) {
	//double x = (1 - fabs(predict - label)) * 10;
	//return 1 / (1 + exp(x));
	return fabs(predict - label) / 2;
}

main(int argc, char* argv[]) {
	ifstream fpredict(argv[1]);
	ifstream flabel(argv[2]);
	ifstream fweight(argv[3]);

	int n, i;
	for (n = 0; fpredict >> predict[n]; n++) {
		flabel >> label[n];
		flabel.getline(line, MAX);
		fweight >> weight[n];
	}

	double max = 0, min = 0;
	for (i = 0; i < n; i++) {
		if (predict[i] > max) max = predict[i];
		if (predict[i] < min) min = predict[i];
	}

	for (i = 0; i < n; i++)
		if (predict[i] > 0) predict[i] /= max;
		else predict[i] /= -min;

	double sum = 0, e = 0, tot1 = 0;
	for (i = 0; i < n; i++) {
		if (label[i] == 1 || label[i] == -1) tot1++;
		if (label[i] == 2 || label[i] == -2) {
			sum += weight[i];
			if (predict[i] * label[i] < 0)
				e += weight[i];
			//e += weight[i] * calc(predict[i], label[i] / 2);
		}
	}
	e /= sum;
	double e0 = e;
	if (e > 0.5) e = 0.5;
	double alpha = e / (1 - e), beta = 1 / (1 + sqrt(2.0 * log(tot1) / 100));


	for (i = 0; i < n; i++) {
		if (label[i] == 1 || label[i] == -1) weight[i] *= pow(beta, calc(predict[i], label[i]));
		//if (label[i] == 2 || label[i] == -2) weight[i] /= pow(alpha, calc(predict[i], label[i] / 2));

		if (label[i] * predict[i] < 0) {
			//if (label[i] == 1 || label[i] == -1) weight[i] *= beta;
			if (label[i] == 2 || label[i] == -2) weight[i] /= alpha;
		}
	}

/*
	for (i = 0; i < n; i++)
		if (label[i] == 1 || label[i] == -1)
			weight[i] *= 0.8;
*/
/*
	double c = atof(argv[4]);
	int tot;
	for (sum = tot = i = 0; i < n; i++)
		if (label[i] == 1 || label[i] == -1)
			sum += weight[i], tot++;
	for (i = 0; i < n; i++)
		if (label[i] == 1 || label[i] == -1) {
			weight[i] = weight[i] / sum * tot;
			if (weight[i] > 1) weight[i] = 1;
		}
			
	for (sum = tot = i = 0; i < n; i++)
		if (label[i] == 2 || label[i] == -2)
			sum += weight[i], tot++;
	for (i = 0; i < n; i++)
		if (label[i] == 2 || label[i] == -2)
			weight[i] = weight[i] / sum * tot * c;
*/	

	double pweight = 0, nweight = 0, ptot = 0, ntot = 0;
	for (i = 0; i < n; i++) {
		if (label[i] > 0) pweight += weight[i], ptot++;
		if (label[i] < 0) nweight += weight[i], ntot++;
	}
	
	for (i = 0; i < n; i++) {
		if (label[i] > 0) weight[i] *= (pweight + nweight) / pweight / 2;
		if (label[i] < 0) weight[i] *= (pweight + nweight) / nweight / 2;
	}		

	for (i = 0; i < n; i++) {
		//weight[i] = weight[i] / sum * n;
		cout << weight[i] << endl;
	}

	double loss = 0, lsum = 0;
	for (i = 0; i < n; i++)
		if (label[i] == 1 || label[i] == -1) {
			loss += fabs(predict[i] - label[i]) / 2 * weight[i];
			lsum += weight[i];
		}
	cout << loss / lsum << ' ' << e << ' ' << e0 << endl;

	return 0;
}
