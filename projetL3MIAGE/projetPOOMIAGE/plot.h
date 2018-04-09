#ifndef PLOT_H
#define PLOT_H

#include <iostream>

class Plot
{
public:
    Plot();
    virtual std::string getType() const;
};

#endif // PLOT_H
