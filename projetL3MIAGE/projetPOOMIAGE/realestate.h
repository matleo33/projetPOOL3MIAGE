#ifndef REALESTATE_H
#define REALESTATE_H

#include "Seller.h"

class RealEstate
{
protected:
    unsigned int m_price;
    std::string m_address;
    short m_surface;
    Seller m_seller;
    static const int m_identifier;
public:
    RealEstate() = delete;
    RealEstate(unsigned int price, std::string address, short surface);
};

#endif // REALESTATE_H
