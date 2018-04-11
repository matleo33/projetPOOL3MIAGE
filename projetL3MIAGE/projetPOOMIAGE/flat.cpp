#include "flat.h"

Flat::Flat(std::string address, short surface, unsigned int price, Seller seller, unsigned short nbRooms, unsigned int floor, bool garage, bool cellar, bool balcony, unsigned int nbFlatsInBuilding)
    :RealEstate(price, address, surface, seller), m_nbRooms(nbRooms), m_floor(floor), m_garage(garage), m_cellar(cellar), m_balcony(balcony), m_nbFlatsInBuilding(nbFlatsInBuilding)
{

}

std::string Flat::getType() const
{
    return "flat";
}

char Flat::getSaveType() const
{
    return 'a';
}

unsigned short Flat::getNbRooms() const
{
    return m_nbRooms;
}

unsigned int Flat::getFloor() const
{
    return m_floor;
}

bool Flat::getGarage() const
{
    return m_garage;
}

bool Flat::getCellar() const
{
    return m_cellar;
}

bool Flat::getBalcony() const
{
    return  m_balcony;
}

unsigned int Flat::getNbFlatsInBuilding() const
{
    return m_nbFlatsInBuilding;
}

void Flat::setNbRooms(unsigned short newNbRooms)
{
    this->m_nbRooms = newNbRooms;
}

void Flat::setFloor(unsigned int newFloor)
{
    this->m_floor = newFloor;
}

void Flat::setGarage(bool newGarage)
{
    this->m_garage = newGarage;
}

void Flat::setCellar(bool newCellar)
{
    this->m_cellar = newCellar;
}

void Flat::setBalcony(bool newBalcony)
{
    this->m_balcony = newBalcony;
}

void Flat::setNbFlatsInBuilding(unsigned int newNbFlatsInBuilding)
{
    this->m_nbFlatsInBuilding = newNbFlatsInBuilding;
}

void Flat::display() const
{
    std::cout << "This is a flat sold by " << m_seller.m_firstName << " " << m_seller.m_name << std::endl;
    std::cout << "This flat is located at " << m_address << std::endl;
    std::cout << "It is sold for $" << m_price << std::endl;
    std::cout << "Its surface is " << m_surface << " divided in " << m_nbRooms << " rooms." << std::endl;
    std::cout << "It is at the floor n° " << m_floor << std::endl;
    if (m_garage)
    {
        std::cout << "It has a garage." << std::endl;
    }
    if (m_cellar)
    {
        std::cout << "It has a cellar." << std::endl;
    }
    if (m_balcony)
    {
        std::cout << "It also has a balcony." << std::endl;
    }
    std::cout << "In the building, we can count " << m_nbFlatsInBuilding << " flats" << std::endl;
}
