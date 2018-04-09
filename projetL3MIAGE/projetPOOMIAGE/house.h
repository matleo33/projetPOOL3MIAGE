#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>

class House
{
private:
    unsigned short m_nbRooms;
    bool m_swimmingPool;
    bool m_garage;
public:
    //Constructors
    House() = delete;
    House(unsigned short nbRooms, bool swimmingPool, bool garage);

    //Getters
    unsigned short getNbRooms() const;
    bool hasSwimmingPool() const;
    bool hasGarage() const;
    virtual std::string getType() const;

    //Setters
    void setNbRooms(unsigned short nbRooms);
    void setSwimmingPool(bool has);
    void setGarage(bool has);
};

#endif // HOUSE_H
