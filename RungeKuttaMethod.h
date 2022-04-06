#pragma once
#include "Calculation.h"

class RungeKuttaMethod :
    public Calculation {

	RungeKuttaMethod(double x0, double v0, double A, double B, double (*f2)(double), int numberOfPoint) : Calculation(x0, v0, A, B, *f2, numberOfPoint) {
	}

	RungeKuttaMethod(double x0, double v0, double A, double B, double (*f2)(double)) : Calculation(x0, v0, A, B, *f2) {
	}

	RungeKuttaMethod() : Calculation() {
	}


private:
	void Calculate(double t) { //finish it in the future
		double step = t / (numberOfPoint - 1);
		//cout << "step = " << step << endl;
		x[0] = x0;
		v[0] = v0;



	}
};

