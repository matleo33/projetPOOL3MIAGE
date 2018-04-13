#include "realestate.h"

int RealEstate::nextId = 0;

RealEstate::RealEstate(unsigned int price, std::string address, unsigned short surface, Seller *seller)
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

Seller* RealEstate::getSeller() const
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

char RealEstate::getSaveType() const
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
    std::cout << "This real estate is sold for " << m_price << std::endl;
    std::cout << m_address << std::endl;
}

void RealEstate::displayElem() const
{
    std::cout << "This real estate is sold for " << m_price << std::endl;
    std::cout << m_address << std::endl;
}

void RealEstate::setAddress(std::string newAddress)
{
    m_address = newAddress;
}

void RealEstate::setPrice(int newPrice)
{
    m_price = newPrice;
}

void RealEstate::setSeller(Seller *newSeller)
{
    m_seller = newSeller;
}

void RealEstate::setSurface(int newSurface)
{
    m_surface = newSurface;
}
