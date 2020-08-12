#ifndef SIMPSONRULEHEADERDEF
#define SIMPSONRULEHEADERDEF
// // Include appropriate libraries
#include <string>
// Include appropriate files
#include "AbstractIntegrator.hpp"
#include "IntegralInterface.hpp"

class SimpsonRule: public AbstractIntegrator
{
public:
    // Specialised constructor
    SimpsonRule(IntegralInterface& anIntegral,
                const double xmin, const double xmax,
                const int initPanels, const int maxPanels,
                const double tolerance, const std::string outputFileName = "output.dat");

    double IntegratePanel(const double xmin, const double h);

    double EstimateError(const double onePanel, const double twoPanels);

    // Deconstructor
    ~SimpsonRule();

    void SetFileName(const std::string mfileName);

};

#endif
