#include "house.h"

House::House(std::string address, short surface, unsigned int price, Seller seller, unsigned short nbRooms, bool swimmingPool, bool garage)
    :RealEstate(price, address, surface, seller), m_nbRooms(nbRooms), m_swimmingPool(swimmingPool), m_garage(garage)
{

}

unsigned short House::getNbRooms() const
{
    return m_nbRooms;
}

bool House::hasSwimmingPool() const
{
    return m_swimmingPool;
}

bool House::hasGarage() const
{
    return m_garage;
}

void House::setNbRooms(unsigned short nbRooms)
{
    m_nbRooms = nbRooms;
}

void House::setSwimmingPool(bool has)
{
    m_swimmingPool = has;
}

void House::setGarage(bool has)
{
    m_garage = has;
}

std::string House::getType() const
{
    return "house";
}

char House::getSaveType() const
{
    return 'm';
}

void House::display() const
{
    std::cout << "This is a house sold by " << m_seller.getFirstName() << " " << m_seller.getName() << std::endl;
    std::cout << "This house is located at " << m_address << std::endl;
    std::cout << "It is sold for $" << m_price << std::endl;
    std::cout << "Its surface is " << m_surface << " divided in " << m_nbRooms << " rooms." << std::endl;
    if (m_swimmingPool)
    {
        std::cout << "This house has a swimming pool." << std::endl;
    }
    if(m_garage)
    {
        std::cout << "This house has also a garage." << std::endl;
    }
}
