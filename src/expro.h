#ifndef _EXPRO_H_
#define _EXPRO_H_

#include <tinyexpr.h>
#include <string>
#include <vector>
#include <tuple>

class Expro
{
public:
	Expro() = delete;
	explicit Expro(std::string source);
	~Expro();

public:
	using var = std::vector<std::pair<std::string, double*>>;

	double value();
	void setVariables(var _variables);

private:
	std::string source;
	te_expr expr;
	var variables;
};

#endif // !_EXPRO_H_
