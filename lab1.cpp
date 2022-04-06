#include "EulerMethod.h"

double newF2(double);


int main() {
	system("chcp 1251");
	//cout << "Тест русского языка" << endl;
	//double newX0 = 78, newV0 = 0, A = 1e-5, B = 1e+10;
	//double newX0 = 78, newV0 = 0, A = 1, B = 1;
	EulerMethod Euler;
	cout << Euler.ValuesOfX(3) << endl;

	int numberOfValues = 1e+4;
	vector<int> stepOfPointTimeGrid(numberOfValues);
	vector<double> valuesFunction(numberOfValues);

	for (int i = 1; i < numberOfValues; i++){
		stepOfPointTimeGrid[i] = i;
		valuesFunction[i] = Euler.ValuesOfX(1, stepOfPointTimeGrid[i]);
	}

	Euler.makeFileForGraph(stepOfPointTimeGrid, valuesFunction, "1.2.txt");
	Euler.drawGraph("1.2.txt", "Values");


	
}

double newF2(double x) {
	return (1 / (x * x) + 60 / (x * x * x * x)) / 1.9;
}

