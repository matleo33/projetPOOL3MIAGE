#include "seller.h"
#include "realestate.h"
#include <algorithm>
Seller::Seller()
{

}


std::string Seller::getType() const
{
    return "real estate";
}

void Seller::addRealEstateToSell(RealEstate re)
{
    m_realEstatesToSell.push_back(re);
}

void Seller::sellRealEstate(RealEstate re)
{
    m_realEstatesToSell.erase(std::remove(m_realEstatesToSell.begin(), m_realEstatesToSell.end(), re), m_realEstatesToSell.end());
}

std::vector<RealEstate> Seller::getRealEstateToSell() const
{
    return m_realEstatesToSell;
}
