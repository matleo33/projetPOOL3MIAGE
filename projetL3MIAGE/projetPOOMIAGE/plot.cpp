#include "plot.h"

Plot::Plot()
{

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
