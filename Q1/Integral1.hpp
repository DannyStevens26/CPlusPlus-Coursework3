#ifndef INTEGRAL1HEADERDEF
#define INTEGRAL1HEADERDEF
// Include appropriate files
#include "IntegralInterface.hpp"

class Integral1 : public IntegralInterface

{
public:
    // Default constructor
    Integral1();
    // Specialised constructor
    Integral1(const double Xmin, const double Xmax);
    // Return integrand value at x
    double ComputeIntegrand(const double x) const;
    // Compute the exact integral
    double ComputeAnalyticIntegral() const;
    // Return the order of accuracy

    double mXmin, mXmax;

};



#endif
