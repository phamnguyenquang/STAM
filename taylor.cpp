#include"Taylor.h"
namespace solver {
	int solver::factorial(int n)
	{
		if (n == 0)return 1;
		else {
			int result = 1;
			for (int i = 1; i <= n; ++i)
			{
				result *= i;
			}
			return result;
		}
	}
	double::solver::power(double a, int b)
	{
		double result = 1;
		for (int i = 1; i <= b; ++i)
		{
			result *= a;
		}
		return result;
	}
	taylor_sin::taylor_sin(double x, int i) :
		input(x), term(i) {};
	double taylor_sin::compute()
	{
		double result = 0;
		for (int i = 1; i <= term; ++i)
		{
			if (i % 2 == 0)
			{
				result -= power((input*PI/180), (2 * i - 1))/(double)(factorial(2*i-1));
			}
			if (i % 2 != 0)
			{
				result += power((input * PI / 180), (2 * i - 1)) / (double)(factorial(2 * i - 1));
			}
		}
		return result;
	}
}
