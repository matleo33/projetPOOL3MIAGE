#include "agency.h"

std::list<Customer> Agency::getCustomers() const
{
    return m_customers;
}

std::map<RealEstate, Customer> Agency::getRealEstates() const
{
    return m_realEstates;
}

void Agency::addCustomer(Customer &customer)
{
    m_customers.push_back(customer);
}

void Agency::addRealEstate(Customer &customer, RealEstate &RealEstate)
{
    m_realEstates.insert(std::make_pair(RealEstate, customer));
}

void Agency::sell(RealEstate re)
{
    m_realEstates.erase(m_realEstates.find(re));
    std::cout << "Real estate sold" << std::endl;
}
