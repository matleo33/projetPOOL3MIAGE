#include "flat.h"

Flat::Flat(unsigned short nbRooms, unsigned int floor, bool garage, bool cellar, bool balcony, unsigned int nbFlatsInBuilding)
    :m_nbRooms(nbRooms), m_floor(floor), m_garage(garage), m_cellar(cellar), m_balcony(balcony), m_nbFlatsInBuilding(nbFlatsInBuilding)
{}
