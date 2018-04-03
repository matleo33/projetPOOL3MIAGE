#ifndef REALESTATE_H
#define REALESTATE_H

#include "Seller.h"

class realEstate
{
protected:
    unsigned int m_price;
    std::string m_address;
    short m_surface;
    Seller m_seller;
    static const int m_identifier;
public:
    realEstate() = delete;
    realEstate(unsigned int price, std::string address, short surface);
};

#endif // REALESTATE_H
