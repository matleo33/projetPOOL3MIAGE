#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include "realestate.h"

class House : public RealEstate
{
private:
    unsigned short m_nbRooms;
    bool m_swimmingPool;
    bool m_garage;
public:
    //Constructors
    House() = delete;
    House(std::string address, short surface, unsigned int price, Seller s, unsigned short nbRooms, bool swimmingPool, bool garage);

    //Getters
    unsigned short getNbRooms() const;
    bool hasSwimmingPool() const;
    bool hasGarage() const;
    virtual std::string getType() const;
    virtual char getSaveType() const;

    //Setters
    void setNbRooms(unsigned short nbRooms);
    void setSwimmingPool(bool has);
    void setGarage(bool has);

    //Other Methods
    void display() const;
};

#endif // HOUSE_H
