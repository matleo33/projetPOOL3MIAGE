#ifndef REALESTATE_H
#define REALESTATE_H

#include "seller.h"

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
    RealEstate(unsigned int price, std::string address, unsigned short surface);
};

#endif // REALESTATE_H
