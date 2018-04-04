#include "visit.h"

Visit::Visit(Buyer b, Seller s, RealEstate re)
    :m_buyer(b), m_seller(s), m_re(re)
{
}

Buyer Visit::getBuyer() const
{
    return m_buyer;
}

Seller Visit::getSeller() const
{
    return m_seller;
}

RealEstate Visit::getRealEstate() const
{
    return m_re;
}

void Visit::setBuyer(Buyer newBayer)
{
    m_buyer = newBayer;
}

void Visit::setSeller(Seller newSeller)
{
    m_seller = newSeller;
}

void Visit::setRealEstate(RealEstate newRealEstate)
{
    m_re = newRealEstate;
}

void Visit::display() const
{
    std::cout << "The visit has been made by " << m_buyer.getName() << std::endl;
    std::cout << "It concerns the real estate of " << m_seller.getName() << std::endl;
    std::cout << "This real estate is located at " << m_re.getAddress() << std::endl;
    std::cout << "It covers a superficy of " << m_re.getSurface() << " square meters " << std::endl;
    std::cout << "It is sold for the price : " << m_re.getPrice() << std::endl;
}

bool Visit::operator<(const Visit & v)
{
    return (m_seller.getName() < v.getSeller().getName())
}
