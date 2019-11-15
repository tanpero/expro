#include "expro.h"
#include "../deps/tinyexpr.h"

Expro::Expro()
{
}

Expro::Expro(std::string source)
{
}

Expro::~Expro()
{
	te_free(&expr);
}
