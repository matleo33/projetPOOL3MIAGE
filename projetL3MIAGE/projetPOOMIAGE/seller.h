#ifndef SELLER_H
#define SELLER_H

#include "customer.h"

class Seller : public Customer
{
private:
    //LISTE BIENS QU'ILS SOUHAIENT VENDRE
public:
    Seller();
    virtual std::string getType() const;
};

#endif // SELLER_H
