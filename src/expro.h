#ifndef _EXPRO_H_
#define _EXPRO_H_

#include <string>

class Expro
{
public:
	Expro() = delete;
	explicit Expro(std::string source);
	~Expro();

private:
	te_expr expr;
};

#endif // !_EXPRO_H_
