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
    Integral1 mIntegral1;

    double exact1 = mIntegral1.ComputeAnalyticIntegral();

    double I1, I2, ApproxError, TotalApproxError=0,ExtrapApproxIntegral=0;

    for(int i=0;i<10;i++)
    {
        SimpsonRule* m1simpsonRule1 = new SimpsonRule(mIntegral1,0+i*0.1,0.1+i*0.1,1,100,pow(10,-100));
        SimpsonRule* m2simpsonRule1 = new SimpsonRule(mIntegral1,0+i*0.1,0.1+i*0.1,2,100,pow(10,-100));
        m1simpsonRule1->CompositeIntegration();
        I1 = m1simpsonRule1->mApproxIntegral;
        m2simpsonRule1->CompositeIntegration();
        I2 = m2simpsonRule1->mApproxIntegral;
        ApproxError = m2simpsonRule1->EstimateError(I1,I2);
        TotalApproxError = TotalApproxError + ApproxError;
        ExtrapApproxIntegral = ExtrapApproxIntegral + I2 + ApproxError;
        m1simpsonRule1->~SimpsonRule();
        m2simpsonRule1->~SimpsonRule();
        std::cout << " ";
    }

    std::cout << "Integral 1 : Extrapolated Approximate Integral = " << ExtrapApproxIntegral << "\n";
    std::cout << "             Error estimate = " << TotalApproxError << "\n";
    std::cout << "             Actual Error = " << ExtrapApproxIntegral-exact1 << "\n\n";

    // Integral 2
    Integral2 mIntegral2;

    double exact2 = mIntegral2.ComputeAnalyticIntegral();

    TotalApproxError=0;
    ExtrapApproxIntegral=0;

    for(int i=0;i<10;i++)
    {
        SimpsonRule* m1simpsonRule2 = new SimpsonRule(mIntegral2,0+i*0.1,0.1+i*0.1,1,100,pow(10,-100));
        SimpsonRule* m2simpsonRule2 = new SimpsonRule(mIntegral2,0+i*0.1,0.1+i*0.1,2,100,pow(10,-100));
        m1simpsonRule2->CompositeIntegration();
        I1 = m1simpsonRule2->mApproxIntegral;
        m2simpsonRule2->CompositeIntegration();
        I2 = m2simpsonRule2->mApproxIntegral;
        ApproxError = m2simpsonRule2->EstimateError(I1,I2);
        TotalApproxError = TotalApproxError + ApproxError;
        ExtrapApproxIntegral = ExtrapApproxIntegral + I2 + ApproxError;
        m1simpsonRule2->~SimpsonRule();
        m2simpsonRule2->~SimpsonRule();
    }

    std::cout << "Integral 2 : Extrapolated Approximate Integral = " << ExtrapApproxIntegral << "\n";
    std::cout << "             Error estimate = " << TotalApproxError << "\n";
    std::cout << "             Actual Error = " << ExtrapApproxIntegral-exact2 << "\n\n";

    // Integral 3
    Integral3 mIntegral3;

    double exact3 = mIntegral3.ComputeAnalyticIntegral();

    TotalApproxError=0;
    ExtrapApproxIntegral=0;

    for(int i=0;i<10;i++)
    {
        SimpsonRule* m1simpsonRule3 = new SimpsonRule(mIntegral3,0+i*0.1,0.1+i*0.1,1,100,pow(10,-100));
        SimpsonRule* m2simpsonRule3 = new SimpsonRule(mIntegral3,0+i*0.1,0.1+i*0.1,2,100,pow(10,-100));

        m1simpsonRule3->CompositeIntegration();
        I1 = m1simpsonRule3->mApproxIntegral;
        m2simpsonRule3->CompositeIntegration();
        I2 = m2simpsonRule3->mApproxIntegral;

        ApproxError = m2simpsonRule3->EstimateError(I1,I2);
        TotalApproxError = TotalApproxError + ApproxError;
        ExtrapApproxIntegral = ExtrapApproxIntegral + I2 + ApproxError;
        m1simpsonRule3->~SimpsonRule();
        m2simpsonRule3->~SimpsonRule();
    }

    std::cout << "Integral 3 : Extrapolated Approximate Integral = " << ExtrapApproxIntegral << "\n";
    std::cout << "             Error estimate = " << TotalApproxError << "\n";
    std::cout << "             Actual Error = " << ExtrapApproxIntegral-exact3 << "\n\n";

    // Part ii
    // Integral 1
    SimpsonRule* mSimpsonRule1 = new SimpsonRule(mIntegral1,0.,1.,10,1000,pow(10,-1000),"FirstIntegralErrors.dat");
    std::ofstream myfile1;
    myfile1.open(mSimpsonRule1->mFileName.c_str());
    assert(myfile1.is_open());
    int n = 10;
    int M = 5;
    double h, mxmax, mxmin;
    mSimpsonRule1->GetXLimits(mxmin,mxmax);
    mSimpsonRule1->~SimpsonRule();
    for (int j=0;j<n;j++)
    {
        M = M+1;
        h = (mxmax-mxmin)/double(M);
        TotalApproxError=0;
        ExtrapApproxIntegral=0;
        for(int i=0;i<M;i++)
        {
            SimpsonRule* m1simpsonRule1 = new SimpsonRule(mIntegral1,0+i*h,(i+1)*h,1,100,pow(10,-100));
            SimpsonRule* m2simpsonRule1 = new SimpsonRule(mIntegral1,0+i*h,(i+1)*h,2,100,pow(10,-100));

            m1simpsonRule1->CompositeIntegration();
            I1 = m1simpsonRule1->mApproxIntegral;
            m2simpsonRule1->CompositeIntegration();
            I2 = m2simpsonRule1->mApproxIntegral;

            ApproxError = m2simpsonRule1->EstimateError(I1,I2);
            TotalApproxError = TotalApproxError + ApproxError;

            ExtrapApproxIntegral = ExtrapApproxIntegral + I2 + ApproxError;
            m1simpsonRule1->~SimpsonRule();
            m2simpsonRule1->~SimpsonRule();
        }
        myfile1 << M << " " << ExtrapApproxIntegral-exact1 << "\n";
    }


    // Integral 2
    SimpsonRule* mSimpsonRule2 = new SimpsonRule(mIntegral2,0.,1.,10,1000,pow(10,-1000),"SecondIntegralErrors.dat");
    std::ofstream myfile2;
    myfile2.open(mSimpsonRule2->mFileName.c_str());
    assert(myfile2.is_open());
    n = 10;
    M = 5;

    mSimpsonRule2->GetXLimits(mxmin,mxmax);
    mSimpsonRule2->~SimpsonRule();
    for (int j=0;j<n;j++)
    {
        M = M+1;
        h = (mxmax-mxmin)/double(M);
        TotalApproxError=0;
        ExtrapApproxIntegral=0;
        for(int i=0;i<M;i++)
        {
            SimpsonRule* m1simpsonRule2 = new SimpsonRule(mIntegral2,0+i*h,(i+1)*h,1,100,pow(10,-100));
            SimpsonRule* m2simpsonRule2 = new SimpsonRule(mIntegral2,0+i*h,(i+1)*h,2,100,pow(10,-100));

            m1simpsonRule2->CompositeIntegration();
            I1 = m1simpsonRule2->mApproxIntegral;
            m2simpsonRule2->CompositeIntegration();
            I2 = m2simpsonRule2->mApproxIntegral;

            ApproxError = m2simpsonRule2->EstimateError(I1,I2);
            TotalApproxError = TotalApproxError + ApproxError;

            ExtrapApproxIntegral = ExtrapApproxIntegral + I2 + ApproxError;
            m1simpsonRule2->~SimpsonRule();
            m2simpsonRule2->~SimpsonRule();
        }
        myfile2 << M << " " << ExtrapApproxIntegral-exact2 << "\n";
    }


    // Integral 3
    SimpsonRule* mSimpsonRule3 = new SimpsonRule(mIntegral3,0.,1.,10,1000,pow(10,-1000),"ThirdIntegralErrors.dat");
    std::ofstream myfile3;
    myfile3.open(mSimpsonRule3->mFileName.c_str());
    assert(myfile3.is_open());
    n = 40;
    M = 1;

    mSimpsonRule3->GetXLimits(mxmin,mxmax);
    mSimpsonRule3->~SimpsonRule();
    for (int j=0;j<n;j++)
    {
        M = M+1;
        h = (mxmax-mxmin)/double(M);
        TotalApproxError=0;
        ExtrapApproxIntegral=0;
        for(int i=0;i<M;i++)
        {
            SimpsonRule* m1simpsonRule3 = new SimpsonRule(mIntegral3,0+i*h,(i+1)*h,1,100,pow(10,-100));
            SimpsonRule* m2simpsonRule3 = new SimpsonRule(mIntegral3,0+i*h,(i+1)*h,2,100,pow(10,-100));

            m1simpsonRule3->CompositeIntegration();
            I1 = m1simpsonRule3->mApproxIntegral;
            m2simpsonRule3->CompositeIntegration();
            I2 = m2simpsonRule3->mApproxIntegral;

            ApproxError = m2simpsonRule3->EstimateError(I1,I2);
            TotalApproxError = TotalApproxError + ApproxError;

            ExtrapApproxIntegral = ExtrapApproxIntegral + I2 + ApproxError;
            m1simpsonRule3->~SimpsonRule();
            m2simpsonRule3->~SimpsonRule();
        }
        myfile3 << M << " " << ExtrapApproxIntegral-exact3 << "\n";
    }

}
