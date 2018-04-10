#include "flat.h"

Flat::Flat(unsigned short nbRooms, unsigned int floor, bool garage, bool cellar, bool balcony, unsigned int nbFlatsInBuilding)
    :m_nbRooms(nbRooms), m_floor(floor), m_garage(garage), m_cellar(cellar), m_balcony(balcony), m_nbFlatsInBuilding(nbFlatsInBuilding)
{}

std::string Flat::getType() const
{
    return "flat";
}

char Flat::getSafeType() const
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
