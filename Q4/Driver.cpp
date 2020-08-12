#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>

#include "AbstractIntegrator.hpp"
#include "IntegralInterface.hpp"
#include "SimpsonRule.hpp"
#include "Integral1.hpp"
#include "Integral2.hpp"
#include "Integral3.hpp"

int main(int argc, char* argv[])
{
    // Declare an object of type Integral1
    Integral1 mIntegral1;
    // Declare a pointer to an object of type SimpsonRule
    SimpsonRule* mSimpsonRule1 = new SimpsonRule(mIntegral1,0.,1.,10,1000,pow(10,-10), "Integral1Output.dat");
    // Use method LocalRefinement
    mSimpsonRule1->LocalRefinement();
    // Repeat the above for integral 2 and 3
    Integral2 mIntegral2;
    SimpsonRule* mSimpsonRule2 = new SimpsonRule(mIntegral2,0.,1.,10,1000,pow(10,-10), "Integral2Output.dat");
    mSimpsonRule2->LocalRefinement();

    Integral3 mIntegral3;
    SimpsonRule* mSimpsonRule3 = new SimpsonRule(mIntegral3,0.,1.,10,1000,pow(10,-10), "Integral3Output.dat");
    mSimpsonRule3->LocalRefinement();
}
