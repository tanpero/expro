#include <expro.h>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	Expro expr1("1 + 2");
	double x = 10, y = 16;
	std::cout << "1 + 2 = " << expr1.parse().value() << "\n"
		<< "x = 10, y = 16, x + y * (x + y) = "
		<< Expro("x + y * (x + y)").parse({ Expro::var({ "x", &x }),{ "y", &y } }).value() << "\n"
		<< "sin(60) = " << Expro("sin(60)").parse().value() << "\n"
		<< "func :: a -> a * 2 + 3, func(20) = "
		<< Expro("func(20)").bind("func", [](double a) { return a * 2 + 3; }).value() << std::endl;

	return 0;
}
