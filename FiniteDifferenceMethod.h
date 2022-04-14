#pragma once
#include "Calculation.h"
class FiniteDifferenceMethod :
    public Calculation {

public:
	FiniteDifferenceMethod(double x0, double v0, double A, double B, double (*f)(double), int numberOfPoint) : Calculation(x0, v0, A, B, *f, numberOfPoint) {
	}

	FiniteDifferenceMethod(double x0, double v0, double A, double B, double (*f)(double)) : Calculation(x0, v0, A, B, *f) {
	}

	FiniteDifferenceMethod() : Calculation() {
	}

	double ValuesOfX(double t) {
		double newT = A * t;
		Calculate(newT);
		return B * x[this->numberOfPoint - 1];
	}

	double ValuesOfX(double t, int numberOfPoint) {
		this->numberOfPoint = numberOfPoint;
		this->x.resize(numberOfPoint);
		this->v.resize(numberOfPoint);

		double newT = A * t;
		Calculate(newT);
		return B * x[this->numberOfPoint - 1];
	}

	~FiniteDifferenceMethod() {

	}


private:

	vector<double> tridiagonalSolution(vector<vector<double>> matrix1, vector<double> matrix2) {
		assert(matrix1.size() == matrix2.size() && "Sizes match");

		double y;
		int N = matrix2.size();
		int N1 = N - 1;
		vector<double> a(N), B(N), matRes(N);

		y = matrix1[0][0];
		a[0] = -matrix1[0][1] / y;
		B[0] = matrix2[0] / y;
		for (int i = 1; i < N1; i++) {
			y = matrix1[i][i] + matrix1[i][i - 1] * a[i - 1];
			a[i] = -matrix1[i][i + 1] / y;
			B[i] = (matrix2[i] - matrix1[i][i - 1] * B[i - 1]) / y;
		}

		matRes[N1] = (matrix2[N1] - matrix1[N1][N1 - 1] * B[N1 - 1]) / (matrix1[N1][N1] + matrix1[N1][N1 - 1] * a[N1 - 1]);
		for (int i = N1 - 1; i >= 0; i--) {
			matRes[i] = a[i] * matRes[i + 1] + B[i];
		}

		return matRes;

	}

	void Calculate(double t) {
		vector<vector<double>> matrix1 = { {1,2,0,0,0}, {3,4,5,0,0}, {0,6,7,8,0}, {0,0,9,10,11}, {0,0,0,12,13} };
		vector<double> matrix2 = { {1,2,3,4,5} };
		vector<double> answer = tridiagonalSolution(matrix1, matrix2);

		cout << "Solution of SLAE:" << endl;
		for (int i = 0; i < matrix2.size(); i++) {
			cout << answer[i] << endl;
		}
	}

};

