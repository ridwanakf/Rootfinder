#include <iostream>
#include <string>
#include "rootfinderbase.h"
#include "exprtk.hpp"

using namespace std;

/* Parsing */
template <typename T>
double trig_function(std::string input, double x0)
{
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;

    std::string expression_string = input;

    T x;

    symbol_table_t symbol_table;
    symbol_table.add_variable("x",x);
    symbol_table.add_constants();

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    parser.compile(expression_string,expression);

    x = T(x0);
    T y = expression.value();
    return y;
}

/* Definiton RootfinderBase methods */

RootfinderBase::RootfinderBase()
{

}

void RootfinderBase::setMaxRAE(double maxRAE)
{
    this->maxRAE = maxRAE/100.0;
}

void RootfinderBase::setx0(double x0)
{
    this->x0 = x0;
}

void RootfinderBase::setx1(double x1)
{
    this->x1 = x1;
}

void RootfinderBase::setx2(double x2)
{
    this->x2 = x2;
}

void RootfinderBase::setMaxIterasi(int maxIterasi)
{
    this->maxIterasi = maxIterasi;
}

void RootfinderBase::setPersamaan(std::string persamaan)
{
    this->persamaan = persamaan;
}

void RootfinderBase::setTurunan(std::string turunan)
{
    this->turunan = turunan;
}

double RootfinderBase::getx0()
{
    return this->x0;
}

double RootfinderBase::getx1()
{
    return this->x1;
}

double RootfinderBase::getx2()
{
    return this->x2;
}

double RootfinderBase::getMaxRAE()
{
    return this->maxRAE;
}

int RootfinderBase::getMaxIterasi()
{
    return this->maxIterasi;
}

double RootfinderBase::calcFunc(double x)
{
    return trig_function<double>(this->persamaan, x);
}

double RootfinderBase::calcDerivative(double x)
{
    return trig_function<double>(this->turunan, x);
}
