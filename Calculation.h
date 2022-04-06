#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include <math.h>


using namespace std;

class Calculation{
private:
string pointSchedule = "with points pointtype 5";
string lineSchedule = "with lines lw 3";
string path = "\"D:/MEGA/ÎÍÔ/6 סולוסענ/ÒÐÑ/labs/lab1/";

//double example(double x) {
//	return (1 / (x * x) + 60 / (x * x * x * x)) / 1.9;
//}

protected:
	double x0, v0, A, B;
	int numberOfPoint;
	//float a, b;
	//double (*f1)(double);
	double (*f2)(double);
	//double (*answer)(double);

	vector<double> x;
	vector<double> v;

public:
	Calculation(double x0, double v0, double A, double B, double (*f2)(double), int numberOfPoint) {
		this->x0 = x0;
		this->v0 = v0;
		this->A = A;
		this->B = B;
		this->numberOfPoint = numberOfPoint;
		this->f2 = f2;
		this->x.resize(numberOfPoint);
		this->v.resize(numberOfPoint);
	}

	Calculation(double x0, double v0, double A, double B, double (*f2)(double)) {
		this->x0 = x0;
		this->v0 = v0;
		this->A = A;
		this->B = B;
		this->numberOfPoint = 1e+3;
		this->f2 = f2;
		this->x.resize(numberOfPoint);
		this->v.resize(numberOfPoint);
	}
	
	Calculation() { // individual option
		this->x0 = 0;
		this->v0 = 10;
		this->A = 1;
		this->B = 1;
		this->numberOfPoint = 1e+3;
		this->f2 = [](double x) {
			return -6 / 6.65 * (2 * x * sinh(x) + x * x * cosh(x)) ;
		};
		this->x.resize(numberOfPoint);
		this->v.resize(numberOfPoint);
	}


	void drawGraph(string name, string text) {
		string str;
		str = path + name + "\" using 1:2 title \"" + text + "\" " + pointSchedule + ";";
		std::ofstream graphic("file");
		cout << str << endl;
		//graphic << "plot " << str << "; pause mouse keypress" << "\n";
		graphic << "set border 3" << endl;
		graphic << "plot " << str << endl;
		graphic.close();
		system("gnuplot -persist file");

		graphic.close();
	}

	template <typename T, typename K>
	void makeFileForGraph(const vector<T>& first, const vector<K>& second, const string fileName) {
		//cout << "file" << endl;

		ofstream file(fileName);

		assert(first.size() == second.size() && "Sizes match");

		for (int i = 0; i < first.size(); i++) {
			//cout << "file = " << i << endl;

			file << first[i] << " " << second[i] << endl;
		}


	}

	void setNumberOfPoint(int numberOfPoint) {
		this->numberOfPoint = numberOfPoint;
	}

};

