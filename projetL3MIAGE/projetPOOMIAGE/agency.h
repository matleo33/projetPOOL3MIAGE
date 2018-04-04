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
    std::map<Customer, RealEstate> m_realEstate;
public:
    Agency() = default;
    void addCustomer(Customer &customer);
    void addRealEstate(Customer &customer, RealEstate &RealEstate);
};

#endif // AGENCY_H
