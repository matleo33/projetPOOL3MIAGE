#ifndef AGENCY_H
#define AGENCY_H

#include <iostream>
#include <list>

class agency
{
private:
    std::list<Customer> customers;
    std::list<RealEstate> realEstates;
public:
    agency();
    void addCustomer(Customer &customer);
    void addRealEstate(RealEstate &realEstate);
};

#endif // AGENCY_H
