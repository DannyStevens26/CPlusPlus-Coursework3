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

void AbstractIntegrator::GlobalRefinement()
{
    // Use composite integration to get find initial Im
    CompositeIntegration();
    // Declare variables, and set the appropriate ones
    double m1ApproxIntegral = mApproxIntegral;
    int M = mInitPanels;
    // Set E2M to be more than the tolerance so the while loop runs at least once
    double E2M = fabs(mTolerance)+1;
    double estError, totalI2Approx, I2M, ExtrapI2M, h, m2ApproxIntegral, FineApprox;
    // "Original" variables are used to store the original X max/min and initial panels as these are changed in the algorithm
    double OriginalXmin = mXmin;
    double OriginalXmax = mXmax;
    int OriginalM = mInitPanels;
    // Calculate the exact integral value for finding the exact error later on
    double exact = mpIntegral->ComputeAnalyticIntegral();
    // A while loop to check the tolerance isn't met yet and that the maximum amount of panels hasn't been reached
    while(fabs(E2M)>mTolerance && M<=mMaxPanels)
    {
        // Pre set the estimated error and total I2 as 0 as these will be summed using a for loop later
        estError = 0;
        totalI2Approx = 0;
        // Set the initial panels as the M value
        mInitPanels = M;
        // Calculate the fine approximate integral
        CompositeIntegration();
        FineApprox = mApproxIntegral;
        // Find the correct h value as M doubles after each iteration of the while loop
        h = (mXmax-mXmin)/double(M);
        for(int i=0;i<M;i++)
        {
            // Set the X max, min and initial panels appropriately to use CompositeIntegration
            mXmin = i*h;
            mXmax = (i+1)*h;
            mInitPanels = 1;
            // Use CompositeIntegration and save the approximate integral for 1 panel, do the same for 2 panels
            CompositeIntegration();
            m1ApproxIntegral = mApproxIntegral;
            mInitPanels = 2;
            CompositeIntegration();
            m2ApproxIntegral = mApproxIntegral;
            // Add the estimated error for the panel onto the previous estimated error sum
            estError = estError + EstimateError(m1ApproxIntegral,m2ApproxIntegral);
            // Add the approximate integration of the panel on to the previous panels sum
            totalI2Approx = totalI2Approx + m2ApproxIntegral;
        }
        // Set X max/min back to the original values to calculate h correctly on the next loop
        mXmax = OriginalXmax;
        mXmin = OriginalXmin;
        // Set the total error and the total approximate integration
        I2M = totalI2Approx;
        E2M = estError;
        // Double the amount of panels
        M = M*2;
        // Set the extrapolated integral value
        ExtrapI2M = I2M+E2M;
        // Output all the necessary data
        std::cout << "With M = " << M/2 << ", we have : \n";
        std::cout << "The fine approximation = " << FineApprox << ", with error = " << FineApprox-exact << "\n";
        std::cout << "I2M = " << I2M << ", E2M = " << E2M << ", Extrapolated I2M = " << ExtrapI2M << ", with error = " << ExtrapI2M-exact << ".\n\n";
    }
    // Set members of the class as the extrapolate integration approximation and the error estimate so they can be accessed after the method has run
    mExtrapApproxIntegral = I2M+E2M;
    mErrorEstimate = E2M;
    mInitPanels = OriginalM;
}
