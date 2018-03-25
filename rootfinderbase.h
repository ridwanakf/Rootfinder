/* ******************************************************************************************
 * This Program was created by Ridwan Afwan Karim Fauzi (www.github.com/ridwanakf)
 * You can use this program for free, but you can't delete this watermark and/or the license.
 * ******************************************************************************************
 */

#ifndef ROOTFINDERBASE_H
#define ROOTFINDERBASE_H

#include <string>

class RootfinderBase
{
private:
        std::string persamaan;
        std::string turunan;
        double maxRAE;
        int maxIterasi;
        double x0;
        double x1;
        double x2;

public:
        RootfinderBase();
        //double calcRAE();
        void setMaxRAE(double maxRAE);
        void setx0(double x0);
        void setx1(double x1);
        void setx2(double x2);
        void setMaxIterasi(int maxIterasi);
        void setPersamaan(std::string persamaan);
        void setTurunan(std::string turunan);
        double getx0();
        double getx1();
        double getx2();
        double getMaxRAE();
        int getMaxIterasi();
        double calcFunc(double x);
        double calcDerivative(double x);
};

#endif // ROOTFINDERBASE_H
