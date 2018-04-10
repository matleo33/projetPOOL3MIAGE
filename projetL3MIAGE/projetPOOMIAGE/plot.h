#ifndef PLOT_H
#define PLOT_H

#include <iostream>
#include "realestate.h"

class Plot : public RealEstate
{
private:
    //CONSTRUCTIBLE OU PAS?
public:
    Plot();
    virtual std::string getType() const;
};

#endif // PLOT_H
