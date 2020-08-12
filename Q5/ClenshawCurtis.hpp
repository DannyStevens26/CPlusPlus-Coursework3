#ifndef CLENSHAWCURTISHEADERDEF
#define CLENSHAWCURTISHEADERDEF
// Include appropriate libraries
#include <string>
// Include appropriate files
#include "AbstractIntegrator.hpp"
#include "IntegralInterface.hpp"

class ClenshawCurtis: public AbstractIntegrator
{
public:
    // Specialised constructor
    ClenshawCurtis(IntegralInterface& anIntegral,
                const double xmin, const double xmax,
                const int initPanels, const int maxPanels,
                const int nodes, const double tolerance,
                const std::string outputFileName = "output.dat");

    double IntegratePanel(const double xmin, const double h);
    // Deconstructor for ClenshawCurtis objects
    ~ClenshawCurtis();

    double EstimateError(const double onePanel, const double twoPanel);

};
#endif

