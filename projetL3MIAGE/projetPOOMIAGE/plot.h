#ifndef PLOT_H
#define PLOT_H

#include <iostream>
#include "realestate.h"

class Plot : public RealEstate
{
private:
    bool m_constructible;

public:
    Plot();
    virtual std::string getType() const;
    virtual char getSafeType() const;

    //Getters
    bool getConstructible() const;

    //Setters
    void setConstructible(bool constructible);
};

#endif // PLOT_H
