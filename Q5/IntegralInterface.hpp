#ifndef INTEGRALINTERFACEHEADERDEF
#define INTEGRALINTERFACEHEADERDEF

// Interface class for integrating a 1D function

class IntegralInterface
{

  public:

    // Compute integrand (pure virtual)
    virtual double ComputeIntegrand( const double x ) const = 0;

    // Compute analytical integral (pure virtual)
    virtual double ComputeAnalyticIntegral() const = 0;
    // Find the p value for Simpson rule for each integral (pure virtual)
    virtual double Getp() const = 0;

};

#endif
