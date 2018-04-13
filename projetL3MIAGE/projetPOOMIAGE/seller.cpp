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

void Seller::addRealEstateToSell(RealEstate *re)
{
    m_realEstatesToSell.push_back(re);
}

void Seller::sellRealEstate(RealEstate *re)
{
    m_realEstatesToSell.erase(std::remove(m_realEstatesToSell.begin(), m_realEstatesToSell.end(), re), m_realEstatesToSell.end());
}

std::vector<RealEstate *> Seller::getRealEstateToSell() const
{
    return m_realEstatesToSell;
}

void Seller::display() const
{
    std::cout << "Mr./Mrs. " << m_firstName << " " << m_name << " is living at " << m_address << std::endl;
    if (!m_realEstatesToSell.empty())
    {
        std::cout << "He/She is selling those real estates : " << std::endl;
        for (RealEstate* re : m_realEstatesToSell)
        {
            re->displayElem();
        }
    } else {
        std::cout << "He/She is not selling any real estate for now." << std::endl;
    }
}
