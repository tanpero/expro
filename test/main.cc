#include <expro.h>
#include <iostream>

int main(int argc, char* argv[])
{
	Expro expr1("1 + 2");
	std::cout << "1 + 2 = " << expr1.parse().value() << std::endl;
	return 0;
}
