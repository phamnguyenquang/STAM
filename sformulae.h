#ifndef sformulae_H
#define sformulae_H

#include "General.h"
namespace solver {
	class solver
	{
	private:
		double a = 0;
		double b = 0;
		double c = 0;
		double delta = 0;
		double x1 = 0;
		double x2 = 0;
		bool local_min = false, local_max = false;
		double binary_search(double lower, double upper);
	public:
		solver(double sa, double sb, double sc);
		void formular1();
		void formular2();
		void estimate();

	};
}
#endif