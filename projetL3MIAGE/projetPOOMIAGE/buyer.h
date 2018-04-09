#ifndef BUYER_H
#define BUYER_H

#include <set>
#include "customer.h"

class Visit;

class Buyer : public Customer
{
protected:
    bool m_purchaseProposal;
    std::set<Visit> m_visits;
public:
    Buyer();

    //Getters
    bool getPurchaseProposal() const;
    std::set<Visit> getVisits();

    //Setters
    void setPurchaseProposal(bool newValue);

    //Other Methods
    void addVisit(Visit v);
    void displayVisits() const;
};

#endif // BUYER_H
