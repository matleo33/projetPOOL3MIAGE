#ifndef AGENCY_H
#define AGENCY_H

#include <iostream>
#include <list>
#include <map>

#include "customer.h"
#include "realestate.h"

class Agency
{
private:
    std::list<Customer> m_customers;
    std::map<RealEstate, Customer> m_realEstates;
public:
    //Constructors
    Agency() = default;

    //Getters
    std::list<Customer> getCustomers() const;
    std::map<RealEstate, Customer> getRealEstates() const;

    //Setters

    //Other Methods
    void addCustomer(Customer &customer);
    void addRealEstate(Customer &customer, RealEstate &RealEstate);
    void sell(RealEstate re);
    void save();
};

#endif // AGENCY_H
