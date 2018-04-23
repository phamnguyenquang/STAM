#ifndef Talor_H
#define Taylor_H
#include"General.h"

namespace solver {
	class taylor_sin {
	private:
		double input;
		int term;
	public:
		taylor_sin(double x, int i);
		double compute();
		double error_cal()
		{
			double r = sin(input*PI / 180);
		}
	};
	int factorial(int n);
	double power(double a, int b);
}
#endif