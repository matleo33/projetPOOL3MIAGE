#ifndef FLAT_H
#define FLAT_H

#include <iostream>
#include "realestate.h"

class Flat : public RealEstate
{
private:
    unsigned short m_nbRooms;
    unsigned int m_floor;
    bool m_garage;
    bool m_cellar;
    bool m_balcony;
    unsigned int m_nbFlatsInBuilding;
public:
    Flat() = delete;
    Flat(std::string address, short surface, unsigned int price, Seller s, unsigned short nbRooms, unsigned int floor, bool garage, bool cellar, bool balcony, unsigned int nbFlatsInBuilding);

    //Getters
    virtual std::string getType() const;
    virtual char getSafeType() const;
    unsigned short getNbRooms() const;
    unsigned int getFloor() const;
    bool getGarage() const;
    bool getCellar() const;
    bool getBalcony() const;
    unsigned int getNbFlatsInBuilding() const;

    //Setters
    void setNbRooms(unsigned short newNbRooms);
    void setFloor(unsigned int floor);
    void setGarage(bool garage);
    void setCellar(bool cellar);
    void setBalcony(bool balcony);
    void setNbFlatsInBuilding(unsigned int nbFlatsInBuilding);

    //Other Methods
    void display() const;
};

#endif // FLAT_H
