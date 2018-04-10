#include "plot.h"


Plot::Plot(bool constructible, unsigned int price, std::string address, short surface, Seller seller)
    :m_constructible(constructible)
{
    m_price = price;
    m_address = address;
    m_surface = surface;
    m_seller = seller;
}

std::string Plot::getType() const
{
    return "plot";
}

char Plot::getSafeType() const
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
