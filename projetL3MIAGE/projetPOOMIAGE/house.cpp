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
