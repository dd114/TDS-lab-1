#include "EulerMethod.h"
#include "AdamsMethod.h"

double newF2(double);


int main() {
	system("chcp 1251");
	//cout << "Тест русского языка" << endl;
	//double newX0 = 78, newV0 = 0, A = 1e-5, B = 1e+10;
	//double newX0 = 78, newV0 = 0, A = 1, B = 1;
	EulerMethod Euler;
	cout << "Start partial calculations" << endl;
	cout << Euler.ValuesOfX(1, 1e+4) << endl;

	double value = 1. / 2;
	cout << Euler.ValuesOfX(value, 1e+4) - 1.88807609975728 << endl;

	//1.4
	//do not work
	//have tested for x = 0.5
	cout << (Euler.ValuesOfX(value, 1e+4) + (Euler.ValuesOfX(value, 1e+3) - Euler.ValuesOfX(value, 1e+4))) - 1.88807609975728 << endl;
	cout << "End partial calculations" << endl;


	int numberOfValues = 1e+3;
	vector<int> stepOfPointTimeGrid(numberOfValues);
	vector<double> valuesFunction(numberOfValues);

	//1.3
	for (int i = 1; i < numberOfValues; i++){
		stepOfPointTimeGrid[i] = i;
		valuesFunction[i] = Euler.ValuesOfX(1, stepOfPointTimeGrid[i]);
	}

	Euler.makeFileForGraph(stepOfPointTimeGrid, valuesFunction, "1.2.txt");
	//Euler.drawGraph("1.2.txt", "Values");


	//1.3
	vector<double> exactSolution(numberOfValues);
	for (int i = 1; i < numberOfValues; i++)
		exactSolution[i] = valuesFunction[i] - (-3.68617024223302);
	
	Euler.makeFileForGraph(stepOfPointTimeGrid, exactSolution, "1.3.txt");
	//Euler.drawGraph("1.3.txt", "Accuracy solution");


	//2.1
	AdamsMethod Adams();
	cout << "Adams " << Euler.ValuesOfX(1, 1e+4) << endl;
	
}

double newF2(double x) {
	return (1 / (x * x) + 60 / (x * x * x * x)) / 1.9;
}

