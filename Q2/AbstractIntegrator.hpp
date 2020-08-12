#ifndef ABSTRACTINTEGRATORHEADERDEF
#define ABSTRACTINTEGRATORHEADERDEF

// Include appropriate file
#include "IntegralInterface.hpp"

// Base class called AbstractIntegrator
class AbstractIntegrator
{
protected:
    // Protected members of abstract integrator
    double mXmin;
    double mXmax;

    int mInitPanels;
    int mMaxPanels;

    int mNodes;

    double mTolerance;
    // Protected pointer to an object in IntegralInterface
    IntegralInterface* mpIntegral;

public:

    // Virtual method for each derived class of AbstractIntegrator to calculate a single panel
    virtual double IntegratePanel (const double xmin, const double h) = 0;

    // Virtual method to estimate the error from integral of one and two panels
    virtual double EstimateError(const double onePanel, const double twoPanels) = 0;

    // A method to approximate the whole integral
    void CompositeIntegration();

    // Get X limits
    void GetXLimits(double& Xmin, double& Xmax);

    // Variables to be accessed and set by the above methods
    double mApproxIntegral;

};

#endif
