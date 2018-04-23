// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "sformulae.h"
#include"Taylor.h"
#include<memory>

int main()
{
	bool cont = true;
	//ax2 + bx + c
	double a = 0, b = 0, c = 0;
	int term_no = 0;
	char ch;
	while (cont) {
		std::cout.precision(20);
		std::cout << "choose type: (1): quad eqn (2):taylor for sin:" << std::endl;
		std::cin >> ch;
		switch (ch) {
		case '1':{
			std::cout << "input parameter" << std::endl;
			std::cout << "a: ";
			std::cin >> a;
			std::cout << std::endl;
			std::cout << "b:";
			std::cin >> b;
			std::cout << std::endl;
			std::cout << "c:";
			std::cin >> c;
			std::cout << std::endl;
			std::cout << "method: 1 = delta above, 2 = delta below, 3 for some estimate (using binary search)" << std::endl;

			auto ptr = std::make_shared<solver::solver>(a, b, c);
			ptr->formular1();
			ptr->formular2();
			ptr->estimate();
			break;
		}
		case'2':
		{
			std::cout << "input parameter" << std::endl;
			std::cout << "sin(a) what is a(degree plz):";
			std::cin >> a;
			std::cout << std::endl;
			std::cout << "no.of term:";
			std::cin >> term_no;
			auto ptr = std::make_shared<solver::taylor_sin>(a, term_no);
			std::cout << "----------------------------" << std::endl;
			std::cout << "estimated: " << ptr->compute() << std::endl;
			break;
		}
		default:
		{
			std::cout << "wrong input" << std::endl;
			break;
		}
		}
	

		std::cout << "cont? (y) or(n)" << std::endl;
		char c;
		std::cin >> c;
		switch (c)
		{
		case 'y':case 'Y': {
			cont = true;
			break;
		}
		case'n':case'N': {
			cont = false;
			break;
		}
		default:
		{
			std::cout << "let just cont" << std::endl;
			cont = true;
			break;
		}
		}
	}
	return 0;
}

