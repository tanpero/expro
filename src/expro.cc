#include "expro.h"
#include "../deps/tinyexpr.h"

Expro::Expro(std::string _source)
{
	source = _source;
}

Expro::~Expro()
{
	te_free(&expr);
}

double Expro::value()
{
	int error;
	double result = te_interp(source.c_str(), &error);
	if (result == NAN)
	{
		return std::nan((std::string("expro error: ") + std::to_string(error)).c_str());
	}
	return result;
}
