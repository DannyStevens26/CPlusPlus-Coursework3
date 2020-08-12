// Include appropriate libraries
#include <cmath>
// Include appropriate files
#include "Integral1.hpp"

// Default constructor
Integral1::Integral1()
{
    mXmax = 1;
    mXmin = 0;
    // p is the order of accuracy for the integral for Simpson rule
    p = 4;
}

// Specialised constructor
Integral1::Integral1(const double Xmin, const double Xmax)
{
    mXmin = Xmin;
    mXmax = Xmax;
}

// Compute integrand
double Integral1::ComputeIntegrand(const double x) const
{
    // Return the value of the integrand at x
    return cos(x);
}

double Integral1::ComputeAnalyticIntegral() const
{
    // Return the exact integral value
    return sin(mXmax) - sin(mXmin);
}

double Integral1::Getp() const
{
    // Return the integrals order of accuracy for Simpson rule
    return p;
}
