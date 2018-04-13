#include "plot.h"


Plot::Plot(bool constructible, unsigned int price, std::string address, short surface, Seller *seller)
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

void Plot::display() const{
    std::cout << "This is a local sold by " << m_seller->getFirstName() << " " << m_seller->getName() << std::endl;
    std::cout << "This local is located at " << m_address << std::endl;
    std::cout << "It is sold for $" << m_price << std::endl;
    if (m_constructible)
    {
        std::cout << "The plot is constructible" << std::endl;
    }
}

void Plot::displayElem() const{
    std::cout << "This real estate is a local located at " << m_address << "." << std::endl;
    std::cout << "It is sold for $" << m_price << "." << std::endl;
    if (m_constructible)
    {
        std::cout << "The plot is constructible." << std::endl;
    }
}
