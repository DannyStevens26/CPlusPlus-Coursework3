// Include appropriate libraries
#include <cmath>
#include <string>
// Include appropriate files
#include "ClenshawCurtis.hpp"
#include "IntegralInterface.hpp"
#include "Integral1.hpp"
#include "Integral2.hpp"
#include "Integral3.hpp"

// Specialised constructor
ClenshawCurtis::ClenshawCurtis(IntegralInterface& anIntegral,
                const double xmin, const double xmax,
                const int initPanels, const int maxPanels, const int nodes,
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
                    mNodes = nodes;
                }

// Deconstructor
ClenshawCurtis::~ClenshawCurtis()
{
    // Delete the pointer to the integral object
    delete mpIntegral;
}

// Method for integrating one panel of the Clenshaw Curtis method
double ClenshawCurtis::IntegratePanel(const double xmin, const double h)
{
    // Set N as the number of nodes
    int N = mNodes;
    // Declare variables and set the ApproxIntegral as 0 as it will be summed using a for loop
    double fx, wk, bj, ck, xk;
    double ApproxIntegral=0;
    // Use a for loop to go through each node and sum over for the approximate integral
    for (int i=0;i<=N;i++)
    {
        // Set ck to the appropriate value
        if(i==0 || i==N)
        {
            ck = 1;
        }
        else
        {
            ck = 2;
        }
        // Calculate the xk value
        xk = xmin+(h/2)*(1+cos((N-i)*M_PI/N));
        // Calculate the integrand value at xk
        fx = mpIntegral->ComputeIntegrand(xk);
        // Set wk to zero
        wk = 0;
        // Use a for loop to calculate the sum part of wk
        for (int j=1;j<=floor(N/2);j++)
        {
            // An if statement to get the appropriate bj
            if(j==N/2)
            {
                bj = 1;
            }
            else
            {
                bj = 2;
            }
            // Sum the wk values
            wk = wk + (bj/(4*j*j-1))*cos(2*i*j*M_PI/N);
        }
        // Calculate the final wk value
        wk = (ck*h/(2*N))*(1-wk);
        // Sum the approximate integral
        ApproxIntegral = ApproxIntegral + wk*fx;
    }
    return ApproxIntegral;
}

double ClenshawCurtis::EstimateError(const double onePanel, const double twoPanel)
{
    // Declare mp
    double mp;
    // An if statement to check if the number of nodes is even, if it is the order of accuracy is number of nodes plus one,
    // if odd the order of accuracy is just the number of nodes
    if(mNodes%2==0)
    {
        mp = mNodes+1;
    }
    else
    {
        mp = mNodes;
    }
    // Return the estimated error
    return (twoPanel-onePanel)/(pow(2,mp)-1);
}

