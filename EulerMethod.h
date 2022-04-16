#pragma once
#include "Calculation.h"
class EulerMethod :
    public Calculation {

public:
	EulerMethod(double x0, double v0, double A, double B, double (*f1)(double), int numberOfPoint) : Calculation(x0, v0, A, B, *f1, numberOfPoint) {
	}

	EulerMethod(double x0, double v0, double A, double B, double (*f1)(double)) : Calculation(x0, v0, A, B, *f1) {
	}

	EulerMethod() : Calculation() {
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

	~EulerMethod() {

	}

private:
	void Calculate(double t) {
		double step = t / (numberOfPoint - 1);
		//cout << "step = " << step << endl;
		x[0] = x0;
		v[0] = v0;
		for (int i = 1; i < numberOfPoint; i++) {
			x[i] = x[i - 1] + v[i - 1] * step;
			v[i] = v[i - 1] + f1(x[i - 1]) * step;
		}

	}

};

