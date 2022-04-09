#include "EulerMethod.h"
#include "AdamsMethod.h"

double newF2(double);


int main() {
	system("chcp 1251");
	//cout << "Тест русского языка" << endl;
	//double newX0 = 78, newV0 = 0, A = 1e-5, B = 1e+10;
	//double newX0 = 78, newV0 = 0, A = 1, B = 1;
	
	cout << "Start partial calculations" << endl;

	//1.1
	EulerMethod Euler;
	cout << "Euler = " << Euler.ValuesOfX(1, 1e+4) << endl;

	//double value = 1. / 2;
	//cout << Euler.ValuesOfX(value, 1e+4) - 1.88807609975728 << endl;

	////1.4
	////do not work
	////have tested for x = 0.5
	//cout << (Euler.ValuesOfX(value, 1e+4) + (Euler.ValuesOfX(value, 1e+3) - Euler.ValuesOfX(value, 1e+4))) - 1.88807609975728 << endl;
	cout << "End partial calculations" << endl;


	int numberOfValues = 1e+3;
	double valueXwhenTequalTo1 = -3.68617024223302;
	vector<int> stepOfPointTimeGrid(numberOfValues);
	vector<double> valuesFunction(numberOfValues);
	vector<double> exactSolution(numberOfValues);

	//1.2
	for (int i = 1; i < numberOfValues; i++){
		stepOfPointTimeGrid[i] = i;
		valuesFunction[i] = Euler.ValuesOfX(1, stepOfPointTimeGrid[i]);
	}

	Euler.makeFileForGraph(stepOfPointTimeGrid, valuesFunction, "1.2.txt");
	//Euler.drawGraph("1.2.txt", "Euler values");


	//1.3
	for (int i = 1; i < numberOfValues; i++)
		exactSolution[i] = valuesFunction[i] - valueXwhenTequalTo1;
	
	Euler.makeFileForGraph(stepOfPointTimeGrid, exactSolution, "1.3.txt");
	//Euler.drawGraph("1.3.txt", "Accuracy Euler solution");


	//2.1
	AdamsMethod Adams;
	cout << "Adams = " << Adams.ValuesOfX(1, 1e+4) << endl;
	
	//2.2
	for (int i = 1; i < numberOfValues; i++) 
		valuesFunction[i] = Euler.ValuesOfX(1, stepOfPointTimeGrid[i]);

	Adams.makeFileForGraph(stepOfPointTimeGrid, valuesFunction, "2.2.txt");
	Adams.drawGraph("2.2.txt", "Adams values");

	
}

double newF2(double x) {
	return (1 / (x * x) + 60 / (x * x * x * x)) / 1.9;
}

