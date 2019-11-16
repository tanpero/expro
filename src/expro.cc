#include "expro.h"
#include "arity.h"
#include <tinyexpr.h>

static inline te_variable pair2tevar(Expro::var pair)
{
	te_variable var = { pair.first.c_str(), pair.second };
	return var;
}

static inline te_variable* translate(Expro::varList vector)
{
	te_variable* buffer = new te_variable[vector.size()];
	if (!vector.empty())
	{
		memcpy(buffer, &pair2tevar(vector[0]), vector.size() * sizeof(Expro::var));
	}	
	return buffer;
}

Expro::Expro(std::string _source)
{
	source = _source;
}

Expro::~Expro()
{
	te_free(expr);
}

double Expro::value()
{
	return te_eval(expr);
}

void Expro::parse()
{
}

void Expro::parse(varList variables)
{
	int error;
	expr = te_compile(source.c_str(), translate(variables), variables.size(), &error);
	if (!expr)
	{
		throw ExproException("Invalid expression: " + source);
	}
}
