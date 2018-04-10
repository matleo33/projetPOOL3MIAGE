#include "realestate.h"

int RealEstate::nextId = 0;

RealEstate::RealEstate(unsigned int price, std::string address, unsigned short surface, Seller seller)
    :m_price(price), m_address(address), m_surface(surface), m_seller(seller)
{
    m_identifier = RealEstate::nextId++;
}

RealEstate::RealEstate(const RealEstate & re)
{
    this->m_identifier = re.getIdentifier();
    this->m_address = re.getAddress();
    this->m_price = re.getPrice();
    this->m_seller = re.getSeller();
    this->m_surface = re.getSurface();
}

//Getters
unsigned int RealEstate::getPrice() const
{
    return m_price;
}

std::string RealEstate::getAddress() const
{
    return m_address;
}

short RealEstate::getSurface() const
{
    return m_surface;
}

Seller RealEstate::getSeller() const
{
    return m_seller;
}

int RealEstate::getIdentifier() const
{
    return m_identifier;
}

std::string RealEstate::getType() const
{
    return "real estate";
}

char RealEstate::getSafeType() const
{
    return 'r';
}

bool RealEstate::operator<(const RealEstate & re) const
{
    return (this->getIdentifier() < re.getIdentifier());
}

bool RealEstate::operator==(const RealEstate & re) const
{
    return (this->getIdentifier() == re.getIdentifier());
}

void RealEstate::display() const
{
    std::cout << "BECAUSE THIS IS MY REAL ESTAAAAAAATE" << std::endl;
}
