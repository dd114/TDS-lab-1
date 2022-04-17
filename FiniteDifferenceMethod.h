#pragma once
#include "Calculation.h"
class FiniteDifferenceMethod :
    public Calculation {

public:
	FiniteDifferenceMethod() : Calculation() {
	}

	double ValuesOfXY(double x) {
		
		return Calculate(x);
	}

	double ValuesOfY(double x, int numberOfPoint) {
		this->numberOfPoint = numberOfPoint;
		
		return Calculate(x);
	}

	~FiniteDifferenceMethod() {

	}


private:

	vector<double> tridiagonalSolution(const vector<vector<double>>& matrix1, const vector<double>& matrix2) {
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

	double Calculate(double x) {
		assert(numberOfPoint > 3 && "Is too little size");

		double step = x / (numberOfPoint - 1);

		vector<vector<double>> matrix1(numberOfPoint - 2, vector<double>(numberOfPoint - 2));
		vector<double> matrix2(numberOfPoint - 2);

		double ai;
		//ai = 1 / (step * step) - p2(1 * step) / (2 * step);

		double bi = alfa0 - alfa1 / step;
		double ci = alfa1 / step;
		double di = A2;

		//double a1 = ai, b1 = bi, c1 = ci, d1 = di;

		matrix1[0][0] = bi;
		matrix1[0][1] = ci;

		matrix2[0] = di;

		for (int i = 2; i < numberOfPoint - 2; i++) {
			ai = 1 / (step * step) - p2(i * step) / (2 * step);
			bi = -2 / (step * step) + q2(i * step);
			ci = 1 / (step * step)+ p2(i * step) / (2 * step);
			di = f2(i * step);

			matrix1[i - 1][i - 2] = ai;
			matrix1[i - 1][i - 1] = bi;
			matrix1[i - 1][i] = ci;

			matrix2[i - 1] = di;
		}


		//ci = 1 / (step * step)+ p2((numberOfPoint - 2) * step) / (2 * step);

		ai = -beta1 / step;
		bi = beta0 + beta1 / step;
		di = B2;

		matrix1[numberOfPoint - 3][numberOfPoint -  4] = ai;
		matrix1[numberOfPoint - 3][numberOfPoint - 3] = bi;

		matrix2[numberOfPoint - 3] = di;


		//print2DArray(matrix1);
		//print1DArray(matrix2);


		vector<double> valuesY = tridiagonalSolution(matrix1, matrix2);

		//print1DArray(valuesY);
		//cout << valuesY.back() << endl;

		double lastValueY = (B2 + valuesY.back() * beta1 / step) / (beta0 + beta1 / step);
		//cout << "Yn = " << lastValueY << endl;

		//cout << "precision = " << abs((b1 * valuesY[0] + c1 * valuesY[1]) - d1) << endl;
		//cout << d1 << endl;
		//cout << b1 * valuesY[0] << endl;
		//cout << c1 * valuesY[1] << endl;
		//cout << b1 * -4.535559 << endl;
		//cout << c1 * -4.515309 << endl;
		//cout << "precision = " << abs((b1 * -4.535559 + c1 * -4.515309) - d1) << endl;
		
		return lastValueY;

	}

	template <typename T>
	void print2DArray(const vector<vector<T>>& matrix1) {

		for (int i = 0; i < matrix1.size(); i++) {
			for (int j = 0; j < matrix1[i].size(); j++) {
				cout << matrix1[i][j] << " ";
			}
			cout << endl;
		}

	}

	template <typename T>
	void print1DArray(const vector<T>& matrix1) {

		for (int i = 0; i < matrix1.size(); i++) {
				cout << matrix1[i] << endl;
		}

	}

};

