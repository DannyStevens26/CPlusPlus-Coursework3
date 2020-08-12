// Include appropriate libraries
#include <cmath>
// Include appropriate files
#include "Integral3.hpp"

// Default constructor
Integral3::Integral3()
{
    mXmax = 1;
    mXmin = 0;
    // p is the order of accuracy for the integral for Simpson rule
    p = 3.9;
}
// Specialised constructor
Integral3::Integral3(const double Xmin, const double Xmax)
{
    mXmin = Xmin;
    mXmax = Xmax;
}
// Compute integrand
double Integral3::ComputeIntegrand(const double x) const
{
    // Return the value of the integrand at x
    return (1/((x+.1)*(x+.1)))*sin(1/(x+.1));
}

double Integral3::ComputeAnalyticIntegral() const
{
     // Return the exact integral value
    return cos(1./(mXmax+0.1)) - cos(1./(mXmin+0.1));
}

double Integral3::Getp() const
{
    // Return the integrals order of accuracy for Simpson rule
    return p;
}
