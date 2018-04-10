#ifndef FLAT_H
#define FLAT_H

#include <iostream>

class Flat
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

    Flat(unsigned short nbRooms, unsigned int floor, bool garage, bool cellar, bool balcony, unsigned int nbFlatsInBuilding);
    //Getters
    virtual std::string getType() const;
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
};

#endif // FLAT_H
