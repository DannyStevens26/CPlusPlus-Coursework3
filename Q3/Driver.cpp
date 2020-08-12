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
    std::cout << "Integral 1 : \n\n";
    // Declare an object of class Integral1
    Integral1 mIntegral1;
    // Declare a pointer to an object of type SimpsonRule
    SimpsonRule* mSimpsonRule1 = new SimpsonRule(mIntegral1,0.,1.,10,100,pow(10,-10));
    // Use the method GlobalRefinement
    mSimpsonRule1->GlobalRefinement();
    // Deconstruct mSimpsonRule1
    mSimpsonRule1->~SimpsonRule();

    // Reaches tolerance 10^-10 at M = 21
    // Lines 29-51 are repeats of the above code for integral 2 and 3
    // Integral 2
    std::cout << "\n\n\nIntegral 2 : \n\n";
    Integral2 mIntegral2;

    SimpsonRule* mSimpsonRule2 = new SimpsonRule(mIntegral2,0.,1.,10,100,pow(10,-10));

    mSimpsonRule2->GlobalRefinement();

    mSimpsonRule2->~SimpsonRule();

    // Reaches tolerance 10^-10 at M = 217566

    // Integral 3
    std::cout << "\n\n\nIntegral 3 : \n\n";
    Integral3 mIntegral3;

    SimpsonRule* mSimpsonRule3 = new SimpsonRule(mIntegral3,0.,1.,2291,100000,pow(10,-10));

    mSimpsonRule3->GlobalRefinement();

    mSimpsonRule3->~SimpsonRule();

    // Reaches tolerance 10^-10 at M = 2291
}
