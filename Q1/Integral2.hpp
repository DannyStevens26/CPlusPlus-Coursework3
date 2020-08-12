#ifndef INTEGRAL2HEADERDEF
#define INTEGRAL2HEADERDEF
// Include appropriate files
#include "IntegralInterface.hpp"

class Integral2: public IntegralInterface
{
public:
    // Default constructor
    Integral2();
    // Specialised constructor
    Integral2(const double Xmin, const double Xmax);
    // Return integrand value at x
    double ComputeIntegrand(const double x) const;
    // Compute the exact integral
    double ComputeAnalyticIntegral() const;
    // Return the order of accuracy

    double mXmin, mXmax;
};



#endif
