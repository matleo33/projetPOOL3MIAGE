#ifndef REALESTATE_H
#define REALESTATE_H

#include "seller.h"

class RealEstate
{
protected:
    static int nextId;
    unsigned int m_price;
    std::string m_address;
    short m_surface;
    Seller m_seller;
    int m_identifier;
public:
    //Constructors
    RealEstate();
    RealEstate(const RealEstate & re);
    RealEstate(unsigned int price, std::string address, unsigned short surface, Seller seller);

    //Getters
    unsigned int getPrice() const;
    std::string getAddress() const;
    short getSurface() const;
    Seller getSeller() const;
    int getIdentifier() const;

    //Setters

    //Operator
    bool operator<(const RealEstate & re) const;
};

#endif // REALESTATE_H
