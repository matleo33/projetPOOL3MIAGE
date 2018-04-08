#ifndef SELLER_H
#define SELLER_H

#include "customer.h"

class Seller : public Customer
{
public:
    Seller();
    virtual bool isSeller() const;
};

#endif // SELLER_H
