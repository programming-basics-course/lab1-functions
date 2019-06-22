#include <iostream>
#include <cmath>

#define d double			// a lot of parameters of this type

// equations, root of which we can find
double f1(double x);		// the interval [0;1]
double f2(double x);		// the interval [0.5; 2.8]

// bisection method for finding fuctions roots
double bisection_method(d(*f)(d x), d a, d b, d eps, int max_iterations, int& count_iterations);

int main()
{

	// Greeting and prompting user input

	double a, b;
	double eps;
	int max_iterations;
	int count_iterations;


	std::cout << "In order to find a root of the equation, enter some information below:\n";

	std::cout << "a, b\t= ";
	std::cin >> a >> b;

	std::cout << "eps\t= ";
	std::cin >> eps;

	std::cout << "maximum amount of iterations\t= ";
	std::cin >> max_iterations;


	// Finding the root of the equation

	std::cout << "x = " << bisection_method(f1, a, b, eps, max_iterations, count_iterations) << std::endl;
	std::cout << "i = " << count_iterations << std::endl;

	system("pause");
	return 0;
}

//
//	FUNCTIONS
//


// f (x)
/*
	functions, roots of which we need to find
*/
double f1(double x)
{
	return sqrt(1 - x) - tan(x);
}
double f2(double x)
{
	return x * x * x - 2 * x * x + x - 3;
}

// Bisection method
/*

	Takes as an input:
	1. function poiter (root of which we need to find);
	2. interval, which contains the root (a and b)
	3. epsilon for the sufficient approximation
	4. maximum amount of iterations
	5. reference to a iterations counter

	Returns:
	Value of the double type of the approximated root of the function.
	In the case when amount of operations is insufficient returns -1
	and prints error message.

*/
double bisection_method(d(*f)(d x), d a, d b, d eps, int max_iterations, int& count_iterations)
{
	// error: bad domain of the function

	if (f(a) * f(b) > 0)
	{
		std::cout << "error: bad domain\n";
	}

	for (int i = 0; i < max_iterations; i++)
	{

		// cheking for approximate roots

		if (abs(f(a)) < eps)
		{
			count_iterations = i;
			return a;
		}

		if (abs(f(b)) < eps)
		{
			count_iterations = i;
			return b;
		}


		// finding middle point 

		double c = (a + b) / 2;


		// choosing new points

		if (f(a) * f(c) <= 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}

	}


	// error: in this case function hasn't retured the root

	std::cout << "error: insufficient number of iterations to perform calculation\n";

}


