#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int N, E;
int TypeMoney[50];

int HasTypeMoney(int v){
	int i;
	for (i = 0; i < E; i++){
		if (TypeMoney[i] == v)return 1;
	}
	return 0;
}
void Swap(int i, int j){
	int temp = TypeMoney[i];
	TypeMoney[i] = TypeMoney[j];
	TypeMoney[j] = temp;
}
void Sort(){
	int i, j;
	for (i = 0; i < N; i++){
		for (j = i; j < N; j++){
			if (TypeMoney[i]>TypeMoney[j])Swap(i, j);
		}
	}
}

void createTestcase(int NT){
	ofstream myfile;
	myfile.open("input.txt");
	int testcase;

	myfile << NT << endl;
	for (testcase = 1; testcase <= NT; testcase++){
		myfile << testcase << endl;

		N = rand() % 50 + 1;
		myfile << N << endl;
		int i, j, a;
		E = 0;
		for (i = 0; i < N; i++){
			do{
				a = rand() % (N * 10) + 1;
			} while (HasTypeMoney(a));
			TypeMoney[i] = a;
			E++;
		}
		Sort();
		for (i = 0; i < N; i++){
			myfile << TypeMoney[i] << " ";
		}
		myfile << endl;
		long Withdraw1;
		Withdraw1 = rand() % (N * 100);
		myfile << Withdraw1 << endl;
	}

	myfile.close();
}