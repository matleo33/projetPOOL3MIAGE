#ifndef SELLER_H
#define SELLER_H

#include "customer.h"
#include <vector>

class RealEstate;

class Seller : public Customer
{
private:
    std::vector<RealEstate> m_realEstatesToSell;
public:
    Seller();

    virtual std::string getType() const;
    void addRealEstateToSell(RealEstate re);
    void sellRealEstate(RealEstate re);

    //Getter
    std::vector<RealEstate> getRealEstateToSell() const;

};

#endif // SELLER_H
