#ifndef AGENCY_H
#define AGENCY_H

#include <iostream>
#include <list>

#include "customer.h"
#include "realestate.h"

class agency
{
private:
    std::list<Customer> customers;
    std::list<RealEstate> realEstates;
public:
    agency();
    void addCustomer(Customer &customer);
    void addRealEstate(RealEstate &RealEstate);
};

#endif // AGENCY_H
