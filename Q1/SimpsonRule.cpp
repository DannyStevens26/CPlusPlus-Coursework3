// Include appropriate libraries
#include <cmath>
#include <string>
// Include appropriate files
#include "SimpsonRule.hpp"
#include "IntegralInterface.hpp"
#include "Integral1.hpp"
#include "Integral2.hpp"
#include "Integral3.hpp"

// Specialised constructor
SimpsonRule::SimpsonRule(IntegralInterface& anIntegral,
                const double xmin, const double xmax,
                const int initPanels, const int maxPanels,
                const double tolerance, const std::string outputFileName)
                {
                    // Set all the relevant members of AbstractIntegrator from the input of the specialised constructor
                    mXmin = xmin;
                    mXmax = xmax;
                    mInitPanels = initPanels;
                    mMaxPanels = maxPanels;
                    mTolerance = tolerance;
                    mpIntegral = &anIntegral;
                    mFileName = outputFileName;
                }

double SimpsonRule::IntegratePanel(const double xmin, const double h)
{
    // Return the value of a single panel integration for the given X min and h using Simpson rule
    return (h/6.)*(mpIntegral->ComputeIntegrand(xmin)+4*mpIntegral->ComputeIntegrand(xmin+h/2.)+mpIntegral->ComputeIntegrand(xmin+h));
}

// Deconstructor
SimpsonRule::~SimpsonRule()
{
    // Delete the pointer mpIntegral
    delete mpIntegral;
}

// Set file name function
void SimpsonRule::SetFileName(const std::string mfileName)
{
    mFileName = mfileName;
}
