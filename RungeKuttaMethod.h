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



};

