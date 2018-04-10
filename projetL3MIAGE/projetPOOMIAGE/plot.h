#ifndef PLOT_H
#define PLOT_H

#include <iostream>

class Plot
{
private:
    //CONSTRUCTIBLE OU PAS?
    bool m_constructible;

public:
    Plot();
    virtual std::string getType() const;

    //Getters
    bool getConstructible() const;

    //Setters
    void setConstructible(bool constructible);
};

#endif // PLOT_H
