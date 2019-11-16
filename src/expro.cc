#include "expro.h"
#include <tinyexpr.h>

inline te_variable pair2tevar(Expro::var pair)
{
	te_variable var = { pair.first.c_str(), pair.second };
	return var;
}

inline te_variable* translate(Expro::varList vector)
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

Expro Expro::parse(varList variables)
{
	int error;
	expr = te_compile(source.c_str(), translate(variables), variables.size(), &error);
	return *this;
}

Expro Expro::bind(std::string name, function0 function)
{
	int error;
	te_variable func{ name.c_str(), function, TE_FUNCTION0 };
	expr = te_compile(source.c_str(), const_cast<const te_variable*>(&func), 1, &error);
	return *this;
}


Expro Expro::bind(std::string name, function1 function)
{
	int error;
	te_variable func{ name.c_str(), function, TE_FUNCTION1 };
	expr = te_compile(source.c_str(), const_cast<const te_variable*>(&func), 1, &error);
	return *this;
}


Expro Expro::bind(std::string name, function2 function)
{
	int error;
	te_variable func{ name.c_str(), function, TE_FUNCTION2 };
	expr = te_compile(source.c_str(), const_cast<const te_variable*>(&func), 1, &error);
	return *this;
}


Expro Expro::bind(std::string name, function3 function)
{
	int error;
	te_variable func{ name.c_str(), function, TE_FUNCTION3 };
	expr = te_compile(source.c_str(), const_cast<const te_variable*>(&func), 1, &error);
	return *this;
}


Expro Expro::bind(std::string name, function4 function)
{
	int error;
	te_variable func{ name.c_str(), function, TE_FUNCTION4 };
	expr = te_compile(source.c_str(), const_cast<const te_variable*>(&func), 1, &error);
	return *this;
}


Expro Expro::bind(std::string name, function5 function)
{
	int error;
	te_variable func{ name.c_str(), function, TE_FUNCTION5 };
	expr = te_compile(source.c_str(), const_cast<const te_variable*>(&func), 1, &error);
	return *this;
}


Expro Expro::bind(std::string name, function6 function)
{
	int error;
	te_variable func{ name.c_str(), function, TE_FUNCTION6 };
	expr = te_compile(source.c_str(), const_cast<const te_variable*>(&func), 1, &error);
	return *this;
}


Expro Expro::bind(std::string name, function7 function)
{
	int error;
	te_variable func{ name.c_str(), function, TE_FUNCTION7 };
	expr = te_compile(source.c_str(), const_cast<const te_variable*>(&func), 1, &error);
	return *this;
}

