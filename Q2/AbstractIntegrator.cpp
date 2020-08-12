// Include appropriate libraries
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cassert>
// Include appropriate files
#include "AbstractIntegrator.hpp"
#include "SimpsonRule.hpp"
#include "IntegralInterface.hpp"
#include "Integral1.hpp"
#include "Integral2.hpp"
#include "Integral3.hpp"

void AbstractIntegrator::GetXLimits(double& Xmin, double& Xmax)
{
    // A get function to find the X max and min values, this passes the correct values to the variables Xmin and Xmax
    Xmin = mXmin;
    Xmax = mXmax;
}

// A void method to compute the approximate integral
void AbstractIntegrator::CompositeIntegration()
{
    // Declare the necessary variables, set the h value
    double h = (mXmax-mXmin)/double(mInitPanels);
    // Initialise the variable IntegralStep as 0 and X as X min
    double IntegralStep = 0;
    double X = mXmin;
    // Use a for loop to sum over all the panels
    for(int i=0;i<mInitPanels;i++)
    {
        // Add the integrated panel to IntegralStep
        IntegralStep = IntegralStep + IntegratePanel(X,h);
        // Increase the X min value to the next X point for the next loop
        X = X+h;
    }
    // Set mApproxIntegral as the approximate integral
    mApproxIntegral = IntegralStep;
}
