#ifndef VISIT_H
#define VISIT_H

#include <iostream>
#include "buyer.h"
#include "customer.h"
#include "seller.h"
#include "realestate.h"

class Visit
{
private:
    Buyer m_buyer;
    Seller m_seller;
    RealEstate m_re;
public:
    //Constructors
    Visit() = delete;
    Visit(Buyer b, Seller s, RealEstate re);

    //Getters
    Buyer getBuyer() const;
    Seller getSeller() const;
    RealEstate getRealEstate() const;

    //Setters
    void setBuyer(Buyer newBuyer);
    void setSeller(Seller newSeller);
    void setRealEstate(RealEstate newRealEstate);

    //Operators
    bool operator<(Visit const& v) const;

    //Other Methods
    void display() const;
};

#endif // VISIT_H
