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

	void Calculate(double t) {
		double step = t / (numberOfPoint - 1);
		//cout << "step = " << step << endl;
		x[0] = x0;
		v[0] = v0;

		x[1] = x[0] + v[0] * step;
		v[1] = v[0] + f(x[0]) * step;

		for (int i = 2; i < numberOfPoint; i++) {
			x[i] = x[i - 1] + step / 2 * (3 * v[i - 1] - v[i - 2]);
			v[i] = v[i - 1] + step / 2 * (3 * f(x[i - 1]) - f(x[i - 2]));
		}

	}

};

