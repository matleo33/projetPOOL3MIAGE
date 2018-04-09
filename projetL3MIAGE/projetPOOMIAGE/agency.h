#ifndef AGENCY_H
#define AGENCY_H

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <fstream>

#include "customer.h"
#include "realestate.h"
#include "buyer.h"
#include "visit.h"

class Agency
{
private:
    std::vector<Customer> m_customers;
    std::vector<Seller> m_sellers;
    std::vector<Buyer> m_buyers;
    std::map<RealEstate, Seller> m_realEstates;
public:
    //Constructors
    Agency() = default;

    //Getters
    std::vector<Customer> getCustomers() const;
    std::map<RealEstate, Seller> getRealEstates() const;
    std::vector<Seller> getSellers() const;
    std::vector<Buyer> getBuyers() const;
    //Setters

    //Other Methods
    void addCustomer(Customer &customer);
    void addRealEstate(Seller &seller, RealEstate &RealEstate);
    void addBuyer(Buyer &b);
    void addSeller(Seller &s);
    void removeSeller();
    void removeRealEstate(RealEstate re);
    void sell(RealEstate re);
    void save();
    void open();
    std::vector<std::string> split(std::string stringToSplit, char separator);

    bool isNumber(std::string str);
};

#endif // AGENCY_H
