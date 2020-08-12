#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cassert>

#include "AbstractIntegrator.hpp"
#include "IntegralInterface.hpp"
#include "SimpsonRule.hpp"
#include "Integral1.hpp"
#include "Integral2.hpp"
#include "Integral3.hpp"

int main(int argc, char* argv[])
{
// Integral 1
// Create an object of class Integral1
Integral1 mIntegral1;
// Calculate the exact integral value
double exact1 = mIntegral1.ComputeAnalyticIntegral();
// Create a pointer to an object of type SimpsonRule using the object mIntegral1, the file name will be used later in the driver
SimpsonRule* mSimpsonRule1 = new SimpsonRule(mIntegral1,0.,1.,10,10,pow(10,-10),"FirstIntegralOutput.dat");
// Use composite integration to find the approximate integration
mSimpsonRule1->CompositeIntegration();
// Output the required
std::cout << "Approximate solution of integral 1 : " << mSimpsonRule1->mApproxIntegral << "\n";

std::cout << "The error is : " << fabs(mSimpsonRule1->mApproxIntegral-exact1) << "\n\n";

// Lines 31-55 are a repeat of the above for integral 2 and 3
// Integral 2
Integral2 mIntegral2;

double exact2 = mIntegral2.ComputeAnalyticIntegral();

SimpsonRule* mSimpsonRule2 = new SimpsonRule(mIntegral2,0.,1.,10,10,pow(10,-10), "SecondIntegralOutput.dat");

mSimpsonRule2->CompositeIntegration();

std::cout << "Approximate solution of integral 2 : " << mSimpsonRule2->mApproxIntegral << "\n";

std::cout << "The error is : " << fabs(mSimpsonRule2->mApproxIntegral-exact2) << "\n\n";

// Integral 2
Integral3 mIntegral3;

double exact3 = mIntegral3.ComputeAnalyticIntegral();

SimpsonRule* mSimpsonRule3 = new SimpsonRule(mIntegral3,0.,1.,10,10,pow(10,-10),"ThirdIntegralOutput.dat");

mSimpsonRule3->CompositeIntegration();

std::cout << "Approximate solution of integral 3 : " << mSimpsonRule3->mApproxIntegral << "\n";

std::cout << "The error is : " << fabs(mSimpsonRule3->mApproxIntegral-exact3) << "\n\n";

// Declare the variables, err is for error, n is the amount of iterations of the for loop, M is the number of panels
double Err;
int n = 10;
int M = 5;
// Define an output stream
std::ofstream myfile1;
// Open the file with the name given above on line 22
myfile1.open(mSimpsonRule1->mFileName.c_str());
// Assert the file is open
assert(myfile1.is_open());

// A for loop to test Simpson rule with different amounts of panels
for (int i=0;i<n;i++)
{
    // Increase the number of panels by one
    M = M+1;
    // Declare a pointer to an object of type SimpsonRule with M number of panels
    SimpsonRule* msimpsonRule1 = new SimpsonRule(mIntegral1,0.,1.,M,1000,pow(10,-1000));
    // Use CompositeIntegration to get the approximate integration
    msimpsonRule1->CompositeIntegration();
    // Calculate the error
    Err = fabs(msimpsonRule1->mApproxIntegral-exact1);
    // Write the required to the file
    myfile1 << M << " " << Err << "\n";
    // Use the deconstructor so there is no problem when a new pointer of the same name is created
    msimpsonRule1->~SimpsonRule();
}

//Lines 86-115 are repeats of lines 58-83 for integral 2 and 3
M = 5;
std::ofstream myfile2;
myfile2.open(mSimpsonRule2->mFileName.c_str());
assert(myfile2.is_open());

for (int i=0;i<n;i++)
{
    M = M+1;
    SimpsonRule* msimpsonRule2 = new SimpsonRule(mIntegral2,0.,1.,M,1000,pow(10,-1000));
    msimpsonRule2->CompositeIntegration();
    Err = fabs(msimpsonRule2->mApproxIntegral-exact2);
    myfile2 << M << " " << Err << "\n";
    msimpsonRule2->~SimpsonRule();
}

M = 10;
int n1 = 30;
std::ofstream myfile3;
myfile3.open(mSimpsonRule3->mFileName.c_str());
assert(myfile3.is_open());

for (int i=0;i<n1;i++)
{
    M = M+1;
    SimpsonRule* msimpsonRule3 = new SimpsonRule(mIntegral3,0.,1.,M,1000,pow(10,-1000));
    msimpsonRule3->CompositeIntegration();
    Err = fabs(msimpsonRule3->mApproxIntegral-exact3);
    myfile3 << M << " " << Err << "\n";
    msimpsonRule3->~SimpsonRule();
}

}
