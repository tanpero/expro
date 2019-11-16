#ifndef _EXPRO_H_
#define _EXPRO_H_

#include <tinyexpr.h>
#include <string>
#include <vector>
#include <tuple>
#include <exception>
#include <functional>

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

    Expro parse(varList variables = { {} });

    using function0 = double(*)(void);
    using function1 = double(*)(double);
    using function2 = double(*)(double, double);
    using function3 = double(*)(double, double, double);
    using function4 = double(*)(double, double, double, double);
    using function5 = double(*)(double, double, double, double, double);
    using function6 = double(*)(double, double, double, double, double, double);
    using function7 = double(*)(double, double, double, double, double, double, double);

    Expro bind(std::string name, function0 function);
    Expro bind(std::string name, function1 function);
    Expro bind(std::string name, function2 function);
    Expro bind(std::string name, function3 function);
    Expro bind(std::string name, function4 function);
    Expro bind(std::string name, function5 function);
    Expro bind(std::string name, function6 function);
    Expro bind(std::string name, function7 function);

private:
    std::string source;
    te_expr* expr;
    varList variables;
    double result;
};

#endif // !_EXPRO_H_
