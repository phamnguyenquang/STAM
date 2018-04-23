#include "sformulae.h"
namespace solver {
	solver::solver(double sa, double sb, double sc) {
		a = sa;
		b = sb;
		c = sc;
		if (sa > 0)
		{
			local_min = true;
		}
		else if (sa < 0)
		{
			local_max = true;
		}
	}
	double solver::binary_search(double lower, double upper)
	{
		double mid = (lower + upper) / 2;
		double test = (a*mid*mid) + b * mid + c;
		if (test == 0)
		{
			return mid;
		}
		if (test > 0) {
			if (local_min) {
				return binary_search(lower, mid);
			}
			else if (local_max)
			{
				return binary_search(mid, upper);
			}
		}
		else {
			if (local_min) {
				return binary_search(mid, upper);
			}
			else if (local_max)
			{
				return binary_search(lower, mid);
			}
		}

	}
	void solver::formular1()
	{
		std::cout << "x1,2 delta up" << std::endl;
		delta = (b*b) - (4 * a*c);
		if (a == 0)
		{
			std::cout << "solution: " << -c / b << std::endl;
		}
		else if (delta >= 0)
		{

			x1 = (-b + sqrt(delta)) / (2 * a);
			x2 = (-b - sqrt(delta)) / (2 * a);
			std::cout << x1 << std::endl << x2 << std::endl;
			std::cout << "---------------" << std::endl;
		}
		else
		{
			std::cout << "no solution" << std::endl;
			std::cout << "---------------" << std::endl;
		}
	}
	void solver::formular2()
	{
		std::cout << "x1,2 delta down" << std::endl;
		delta = (b*b) - (4 * a*c);
		if (a == 0)
		{
			std::cout << "solution: " << -c / b << std::endl;
			std::cout << "---------------" << std::endl;
		}
		else if (delta >= 0)
		{

			x1 = (-2 * c) / (b + sqrt(delta));
			x2 = (-2 * c) / (b - sqrt(delta));
			std::cout << x1 << std::endl << x2 << std::endl;
			std::cout << "---------------" << std::endl;
		}
		else
		{
			std::cout << "no solution" << std::endl;
			std::cout << "---------------" << std::endl;
		}
	}
	void solver::estimate()
	{
		std::cout << "estimate solution: " << std::endl;
		double x_minmax = -b / (2 * a);
		double y_minmax = (a*(x_minmax*x_minmax)) + (b* x_minmax) + c;
		if ((local_max && y_minmax < 0) || (local_min && y_minmax > 0))
		{
			std::cout << "no real solution" << std::endl;
			std::cout << "---------------" << std::endl;
		}
		else if (y_minmax == 0)
		{
			std::cout << "unique solution: " << x_minmax << std::endl;
			std::cout << "---------------" << std::endl;
		}
		else
		{
			x1 = binary_search(x_minmax, (abs(a) + abs(b) + abs(c)));
			x2 = x_minmax - (x1 - x_minmax);

			std::cout << x1 << std::endl;
			std::cout << x2 << std::endl;
			std::cout << "---------------" << std::endl;

		}

	}
}