#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
using namespace std;
const double epsilon = 0.00001;
double *GaussianElimination(double **Matrix, double *y, int n){
	double *x, max;
	int k, index;
	x = new double[n];
	k = 0;
	while (k < n){
		max = abs(Matrix[k][k]);
		index = k;
		for (int i = (k + 1); i < n; i++){
			if (abs(Matrix[i][k]) > max){
				max = abs(Matrix[i][k]);
				index = i;
			}
		}
		if (max < epsilon){
			cout << "В матрице присутствует нулевой столбец, решение невозможно";
			return 0;
		}
		for (int j = 0; j < n; j++){
			swap(Matrix[k][j], Matrix[index][j]);
		}
		swap(y[k], y[index]);
		for (int i = k; i < n; i++){
			double dud = Matrix[i][k];
			if (abs(dud) < epsilon){
				continue;
			}
			for(int j = 0; j < n; j++){
				Matrix[i][j] = Matrix[i][j] - Matrix[k][j];
			}
			y[i] = y[i] - y[k];
		}
		k++;
	}
	for (k = n - 1; k >= 0; k--){
		x[k] = y[k];
		for (int i = 0; i < k; i++){
			y[i] = y[i] - Matrix[i][k] * x[k];
		}
	}
	return x;
}
int main(){
	double **Matrix, *y, *x;
	int n;
	setlocale(LC_ALL, "Russian");
	cout << "Введите ранг матрицы: ";
	cin >> n;
	Matrix = new double*[n];
	y = new double[n];
	for (int i = 0; i < n; i++){
		Matrix[i] = new double[n];
		for (int j = 0; j < n; j++){
			cout << "Matrix[" << i << "][" << j << "]= ";
			cin >> Matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		cout << "y[" << i << "]= ";
		cin >> y[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << Matrix[i][j] << "*x" << j;
			if (j < n - 1){
				cout << " + ";
			}
		}
		cout << " = " << y[i] << endl;
	}
	x = GaussianElimination (Matrix, y, n);
	for (int i = 0; i < n; i++){
		cout << "x[" << i << "]=" << x[i] << endl;
	}
	getch();
	return 0;
}