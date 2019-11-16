#include "expro.h"
#include "../deps/tinyexpr.h"

static inline te_variable pair2tevar(Expro::var pair)
{
	te_variable var = { pair.first.c_str(), pair.second }
}

static inline te_variable* translate(Expro::varList vector)
{
	te_variable* buffer = new te_variable[vector.size()];
	if (!vector.empty())
	{
		memcpy(buffer, &vector[0], vector.size() * sizeof(te_variable));
	}	
	return buffer;
}

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

void Expro::parse()
{
}

void Expro::parse(varList variables)
{
	expr = te_compile(source.c_str(), translate(variables), 
}
