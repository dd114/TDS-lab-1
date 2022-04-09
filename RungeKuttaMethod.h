#pragma once
#include "Calculation.h"

class RungeKuttaMethod :
    public Calculation {

public:
	RungeKuttaMethod(double x0, double v0, double A, double B, double (*f2)(double), int numberOfPoint) : Calculation(x0, v0, A, B, *f2, numberOfPoint) {
	}

	RungeKuttaMethod(double x0, double v0, double A, double B, double (*f2)(double)) : Calculation(x0, v0, A, B, *f2) {
	}

	RungeKuttaMethod() : Calculation() {
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

	~RungeKuttaMethod() {

	}

private:
	void Calculate(double t) { //finish it in the future
		double step = t / (numberOfPoint - 1);
		//cout << "step = " << step << endl;

		v[0] = v0;
		x[0] = x0;

		for (int i = 1; i < numberOfPoint; i++) {
			double kv0 = f(x[i - 1]);
			double kx0 = v[i - 1];

			double kv1 = f(x[i - 1] + step / 2 * kx0);
			double kx1 = v[i - 1] + step / 2 * kv0;

			double kv2 = f(x[i - 1] + step / 2 * kx1);
			double kx2 = v[i - 1] + step / 2 * kv1;

			double kv3 = f(x[i - 1] + step * kx2);
			double kx3 = v[i - 1] + step * kv2;

			v[i] = v[i - 1] + step / 6 * (kv0 + 2 * kv1 + 2 * kv2 + kv3);
			x[i] = x[i - 1] + step / 6 * (kx0 + 2 * kx1 + 2 * kx2 + kx3);

		}



	}
};

