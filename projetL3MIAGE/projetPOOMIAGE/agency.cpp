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
    std::ofstream file_sellers("../save/sellers.txt", std::ios::out | std::ios::trunc);
    if(file_sellers) {
        for(Seller it : m_sellers) {
            file_sellers << it.getFirstName() << " : " << it.getName() << " : "
                    << it.getAddress() << ";";
        }
    } else {
        std::cerr << "Can not open sellers.txt" << std::endl;
    }

    std::ofstream file_buyers("../save/buyers.txt", std::ios::out | std::ios::trunc);
    if(file_buyers) {
        for(Buyer it : m_buyers) {
            file_buyers << it.getFirstName() << " : " << it.getName() << " : "
                    << it.getAddress() << ";";
        }
    } else {
        std::cerr << "Can not open buyers.txt" << std::endl;
    }

    std::ofstream file_realEstates("../save/realEstates.txt", std::ios::out | std::ios::trunc);
    if(file_realEstates) {
        for (std::pair<RealEstate,Customer> it : m_realEstates) {
            file_realEstates << it.first.getIdentifier() << " : " << it.first.getSeller().getId() << std::endl;
        }
    }


    std::cout << "Saved" << std::endl;
    //Write everything in files

}

void Agency::open()
{


    std::cout << "Read" << std::endl;
    //Read everything from files

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
