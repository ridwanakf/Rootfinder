#include "newtonraphson.h"
#include "mainwindow.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

NewtonRaphson::NewtonRaphson()
{

}

double NewtonRaphson::calcIterasi()
{   double x0 = getx0();
    return (double)(x0 - (calcFunc() /(calcDerivative())));
}

void NewtonRaphson::outNewtonRaphson()
{
    double RAE = 1000.0, x1;
    double minRAE = getMinRAE();
    int maxIterasi = getMaxIterasi();
    int i = 1;
    while((RAE > minRAE) && (i < maxIterasi)){
            x1 = calcIterasi();
            setx1(x1);
            RAE = abs((getx1() - getx0())/(getx1()));
            cout << "Iterasi ke - " << i << endl;
            cout << "x" << i-1 << " = " << getx0() << "; x" << i
                    << " = " << getx1() << "; f(x" << i-1 << ") = "
                    << calcFunc() << "; f'(x"<< i-1 <<") = "
                    << calcDerivative() << "; RAE = " << RAE*100
                    << "%; " << endl << endl;
            //printNewton();
            //test->ui->outputNewton->append(QString("Test : \n"));
            i++;
            setx0(x1);
        }
}
