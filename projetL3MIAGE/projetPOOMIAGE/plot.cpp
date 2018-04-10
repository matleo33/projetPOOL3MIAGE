#include "plot.h"


Plot::Plot(bool constructible, unsigned int price, std::string address, short surface, Seller seller)
    :RealEstate(price, address, surface, seller), m_constructible(constructible)
{

}

std::string Plot::getType() const
{
    return "plot";
}

char Plot::getSaveType() const
{
    return 't';
}

bool Plot::getConstructible() const
{
    return m_constructible;
}

void Plot::setConstructible(bool newConstructible)
{
    this->m_constructible = newConstructible;
}
