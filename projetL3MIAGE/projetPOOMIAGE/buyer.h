#ifndef BUYER_H
#define BUYER_H

#include "customer.h"
#include "visit.h"

#include <set>

class Buyer : public Customer
{
private:
    bool m_purchaseProposal;
    std::set<Visit> m_visits;
public:
    Buyer();
};

#endif // BUYER_H