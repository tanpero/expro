#include <expro.h>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	Expro expr1("1 + 2");
	std::cout << "1 + 2 = " << expr1.parse().value() << "\n";
	std::cout << "2 * 8 + 3 = " << Expro("2 * 8 + 3").parse().value() << "\n"
		<< "7 * (4 - 5 * (6 + 2)) / (2 + 3) = "
		<< Expro("7 * (4 - 5 * (6 + 2)) / (2 + 3)").parse().value() << "\n";
	double x = 10, y = 20;
	std::cout << "x = 10, y = 20,\n  x + y * 2 = "
		<< Expro("x + y * 2").parse({ { "x", &x },{ "y", &y } }).value() << "\n";
	std::cout << "my_func :: a -> a * 2 + 1,\n  my_func(10) = "
		<< Expro("my_func(10)").bind("my_func", [](double a) { return a * 2 + 1; }).value() << "\n";
	return 0;
}
