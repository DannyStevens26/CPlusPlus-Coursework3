#ifndef INTEGRAL3HEADERDEF
#define INTEGRAL3HEADERDEF
// Include appropriate files
#include "IntegralInterface.hpp"

class Integral3: public IntegralInterface
{
public:
    // Default constructor
    Integral3();
    // Specialised constructor
    Integral3(const double Xmin, const double Xmax);
    // Return integrand value at x
    double ComputeIntegrand(const double x) const;
    // Compute the exact integral
    double ComputeAnalyticIntegral() const;
    // Return the order of accuracy
    double Getp() const;

    double p;

    double mXmin, mXmax;
};



#endif

