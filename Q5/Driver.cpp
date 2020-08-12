// Include appropriate libraries
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>
// Include appropriate files
#include "AbstractIntegrator.hpp"
#include "IntegralInterface.hpp"
#include "SimpsonRule.hpp"
#include "ClenshawCurtis.hpp"
#include "Integral1.hpp"
#include "Integral2.hpp"
#include "Integral3.hpp"


int main(int argc, char* argv[])
{
    // Create an object of class Integral1
    Integral1 mIntegral1;
    // Create a pointer to an object using the Clenshaw Curtis specialised constructor, the string defining the file name is used later on in the driver
    ClenshawCurtis* mClenshawCurtis1 = new ClenshawCurtis(mIntegral1,0.,1.,10,100,3,pow(10,-10), "FirstClenshawOutput.dat");
    // Use the method CompositeIntegration to calculate the approximate integral
    mClenshawCurtis1->CompositeIntegration();
    std::cout << "Clenshaw-Curtis gives integral 1 as = " << mClenshawCurtis1->mApproxIntegral << "\n";
    // Compute the exact integral and take it off the approximate to get the error
    std::cout << "The error is = " << mClenshawCurtis1->mApproxIntegral - mIntegral1.ComputeAnalyticIntegral() << "\n\n";

    // Lines 28-39 are a repeat of the above for integral 2 and 3
    Integral2 mIntegral2;
    ClenshawCurtis* mClenshawCurtis2 = new ClenshawCurtis(mIntegral2,0.,1.,10,100,3,pow(10,-10), "SecondClenshawOutput.dat");
    mClenshawCurtis2->CompositeIntegration();
    std::cout << "Clenshaw-Curtis gives integral 2 as = " << mClenshawCurtis2->mApproxIntegral << "\n";
    std::cout << "The error is = " << mClenshawCurtis2->mApproxIntegral - mIntegral2.ComputeAnalyticIntegral() << "\n\n";


    Integral3 mIntegral3;
    ClenshawCurtis* mClenshawCurtis3 = new ClenshawCurtis(mIntegral3,0.,1.,10,100,3,pow(10,-10),"ThirdClenshawOutput.dat");
    mClenshawCurtis3->CompositeIntegration();
    std::cout << "Clenshaw-Curtis gives integral 3 as = " << mClenshawCurtis3->mApproxIntegral << "\n";
    std::cout << "The error is = " << mClenshawCurtis3->mApproxIntegral - mIntegral3.ComputeAnalyticIntegral() << "\n\n";

    // Define the output stream
    std::ofstream myfile1;
    // Open the file with the name set earlier in the driver, this saves creating another object just to set the file name
    myfile1.open(mClenshawCurtis1->mFileName.c_str());
    // Assert the file is open
    assert(myfile1.is_open());
    // Declare and initialise the required variables, N: initial no. of nodes, n: no. of iterations
    int N = 2;
    int n = 10;
    double Err;
    double exact1 = mIntegral1.ComputeAnalyticIntegral();
    // A for loop to write to calculate the error for each N and write it to a file
    for (int i=0;i<n;i++)
    {
        // Increase the number of nodes by 1
        N = N+1;
        // Create a pointer to an object of class ClenshawCurtis
        ClenshawCurtis* mclenshawCurtis1 = new ClenshawCurtis(mIntegral1,0.,1.,10,100,N,pow(10,-10));
        // Use composite integration to find the approximate integration
        mclenshawCurtis1->CompositeIntegration();
        // Calculate the error
        Err = fabs(mclenshawCurtis1->mApproxIntegral-exact1);
        // Write to the file
        myfile1 << N << " " << Err << "\n";
        // Use the specialised deconstructor for the next loop
        mclenshawCurtis1->~ClenshawCurtis();

    }

    // Tolerance 10^-10 met at N = 4

    // Lines 74-114 are a repeat of lines 42-69 for integral 2 and 3
    std::ofstream myfile2;
    myfile2.open(mClenshawCurtis2->mFileName.c_str());
    assert(myfile2.is_open());
    N = 2;
    n = 10;
    double exact2 = mIntegral2.ComputeAnalyticIntegral();

    for (int i=0;i<n;i++)
    {
        N = N+1;
        ClenshawCurtis* mclenshawCurtis2 = new ClenshawCurtis(mIntegral2,0.,1.,10,100,N,pow(10,-10));
        mclenshawCurtis2->CompositeIntegration();

        Err = fabs(mclenshawCurtis2->mApproxIntegral-exact2);

        myfile2 << N << " " << Err << "\n";
        mclenshawCurtis2->~ClenshawCurtis();

    }

    // Tolerance 10^-10 met at N = 326

    std::ofstream myfile3;
    myfile3.open(mClenshawCurtis3->mFileName.c_str());
    assert(myfile3.is_open());
    N = 2;
    n = 10;
    double exact3 = mIntegral3.ComputeAnalyticIntegral();

    for (int i=0;i<n;i++)
    {
        N = N+1;
        ClenshawCurtis* mclenshawCurtis3 = new ClenshawCurtis(mIntegral3,0.,1.,10,100,N,pow(10,-10));
        mclenshawCurtis3->CompositeIntegration();

        Err = fabs(mclenshawCurtis3->mApproxIntegral-exact3);

        myfile3 << N << " " << Err << "\n";
        mclenshawCurtis3->~ClenshawCurtis();

    }

    // Tolerance 10^-10 met at N = 18
}
