#include "agency.h"

std::vector<Customer> Agency::getCustomers() const
{
    return m_customers;
}

std::map<RealEstate, Seller> Agency::getRealEstates() const
{
    return m_realEstates;
}

void Agency::addCustomer(Customer &customer)
{
    m_customers.push_back(customer);
}

void Agency::addRealEstate(Seller &seller, RealEstate &RealEstate)
{
    m_realEstates.insert(std::make_pair(RealEstate, seller));
}

void Agency::sell(RealEstate re)
{
    m_realEstates.erase(m_realEstates.find(re));
    std::cout << "Real estate sold" << std::endl;
}

void Agency::save()
{
    std::cout << "Saved" << std::endl;
    //Write everything in files

}

std::vector<Seller> Agency::getSellers() const
{
    return m_sellers;
}

std::vector<Buyer> Agency::getBuyers() const
{
    return m_buyers;
}

void Agency::addBuyer(Buyer &b)
{
    m_buyers.push_back(b);
}

void Agency::addSeller(Seller &s)
{
    m_sellers.push_back(s);
}
