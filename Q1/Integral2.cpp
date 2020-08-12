// Include appropriate libraries
#include <cmath>
// Include appropriate files
#include "Integral2.hpp"
// Default constructor
Integral2::Integral2()
{
    mXmax = 1;
    mXmin = 0;
}
// Specialised constructor
Integral2::Integral2(const double Xmin, const double Xmax)
{
    mXmin = Xmin;
    mXmax = Xmax;
}
// Compute integrand
double Integral2::ComputeIntegrand(const double x) const
{
    // Return the value of the integrand at x
    return pow(x,1./2.);
}

double Integral2::ComputeAnalyticIntegral() const
{
    // Return the exact integral value
    return (2./3.)*pow(mXmax,3./2.) - (2./3.)*pow(mXmin,3./2.);
}
