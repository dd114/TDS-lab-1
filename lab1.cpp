#include "EulerMethod.h"
#include "AdamsMethod.h"
#include "RungeKuttaMethod.h"
#include "FiniteDifferenceMethod.h"

double newF2(double);


int main() {
	system("chcp 1251");
	cout.precision(10);

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
	vector<double> accuracySolution(numberOfValues);

	//1.2
	for (int i = 1; i < numberOfValues; i++){
		stepOfPointTimeGrid[i] = i;
		valuesFunction[i] = Euler.ValuesOfX(1, stepOfPointTimeGrid[i]);
	}

	Euler.makeFileForGraph(stepOfPointTimeGrid, valuesFunction, "1.2.txt");
	//Euler.drawGraph("1.2.txt", "Euler values");


	//1.3
	for (int i = 1; i < numberOfValues; i++)
		accuracySolution[i] = valuesFunction[i] - valueXwhenTequalTo1;
	
	Euler.makeFileForGraph(stepOfPointTimeGrid, accuracySolution, "1.3.txt");
	//Euler.drawGraph("1.3.txt", "Accuracy Euler solution");





	//2.1
	AdamsMethod Adams;
	cout << "Adams = " << Adams.ValuesOfX(1, 1e+4) << endl;
	
	//2.2
	for (int i = 1; i < numberOfValues; i++) 
		valuesFunction[i] = Euler.ValuesOfX(1, stepOfPointTimeGrid[i]);

	Adams.makeFileForGraph(stepOfPointTimeGrid, valuesFunction, "2.2.txt");
	//Adams.drawGraph("2.2.txt", "Adams values");

	//2.3
	for (int i = 1; i < numberOfValues; i++)
		accuracySolution[i] = valuesFunction[i] - valueXwhenTequalTo1;

	Adams.makeFileForGraph(stepOfPointTimeGrid, accuracySolution, "2.3.txt");
	//Adams.drawGraph("2.3.txt", "Accuracy Adams solution");




	
	//3.1
	RungeKuttaMethod RungeKutta;
	cout << "RungeKutta = " << RungeKutta.ValuesOfX(1, 1e+4) << endl;

	//3.2
	for (int i = 1; i < numberOfValues; i++)
		valuesFunction[i] = RungeKutta.ValuesOfX(1, stepOfPointTimeGrid[i]);

	RungeKutta.makeFileForGraph(stepOfPointTimeGrid, valuesFunction, "3.2.txt");
	//RungeKutta.drawGraph("3.2.txt", "RungeKutta values");

	//3.3
	for (int i = 1; i < numberOfValues; i++)
		accuracySolution[i] = valuesFunction[i] - valueXwhenTequalTo1;

	RungeKutta.makeFileForGraph(stepOfPointTimeGrid, accuracySolution, "3.3.txt");
	//RungeKutta.drawGraph("3.3.txt", "Accuracy RungeKutta solution");







	FiniteDifferenceMethod FiniteDifference;
	FiniteDifference.ValuesOfX(4, 1000);


}

double newF2(double x) {
	return (1 / (x * x) + 60 / (x * x * x * x)) / 1.9;
}

