#ifndef _EXPRO_H_
#define _EXPRO_H_

#include <tinyexpr.h>
#include <string>
#include <vector>
#include <tuple>
#include <exception>

class ExproException : public std::exception
{
public:
	ExproException(std::string info)
	{
		_info = info.c_str();
	}
	const char* what()
	{
		return _info;
	}
private:
	const char* _info;
};

class Expro
{
public:
	Expro() = delete;
	explicit Expro(std::string source);
	~Expro();

public:
	using var = std::pair<std::string, double*>;
	using varList = std::vector<var>;

	double value();

private:
	void parse();
	void parse(varList variables);

private:
	std::string source;
	te_expr* expr;
	varList variables;
	double result;
};

#endif // !_EXPRO_H_
