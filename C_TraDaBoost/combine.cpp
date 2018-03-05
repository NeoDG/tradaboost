#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 1000000+5;

int label0;
char line[MAX];

int n;
int label[MAX], used[MAX];
char* data[MAX];

int check(char* s) {
	int i;
	for (i = 0; s[i]; i++)
		if (isdigit(s[i]))
			return 1;
	return 0;
}

main(int argc, char* argv[]) {
	ifstream train(argv[1]);
	ifstream test(argv[2]);
	int num = atoi(argv[3]), seed = atoi(argv[4]);
	
	srand(seed);
	
	ofstream ftrain("train.txt");
	ofstream ftrain0("train0.txt");
	ofstream ftrain2("train2.txt");
	while (train >> label0) {
		train.getline(line, MAX);
		ftrain << label0 << line << endl;
		ftrain0 << label0 << line << endl;	
		//ftrain2 << label0 << line << endl;
	}

	for (n = 0; test >> label[n]; n++) {
		test.getline(line, MAX);
		data[n] = new char[strlen(line) + 5];
		strcpy(data[n], line);	
	}


	num = (n * num + 99) / 100;
		
	memset(used, 0, sizeof(used));
	while (num--) {
		int id = rand()%n;
		while (used[id] || !check(data[id])) id = rand()%n;
		used[id] = 1;
	}

/*
	num = (n * num + 99) / 100;
	int pos = num / 2 + 1, neg = pos;
	memset(used, 0, sizeof(used));
	while (pos--) {
		int id = rand()%n;
		while (used[id] || label[id] != 1) id = rand()%n;
		used[id] = 1;
	}
	while (neg--) {
		int id = rand()%n;
		while (used[id] || label[id] != -1) id = rand()%n;
		used[id] = 1;
	}
*/
	int i;
	for (i = 0; i < n; i++) 
		if (used[i]) {
			ftrain << label[i] * 2 << data[i] << endl;
			ftrain2 << label[i] << data[i] << endl;
		}
		
	ofstream ftrain1("train1.txt");
	for (i = 0; i < n; i++) 
		if (used[i]) 
			ftrain1 << label[i] << data[i] << endl;
		else
			ftrain2 << 0 << data[i] << endl;
	
	ofstream ftest("test.txt");
	for (i = 0; i < n; i++) 
		if (!used[i]) 
			ftest << label[i] << data[i] << endl;
			
	return 0;
}
