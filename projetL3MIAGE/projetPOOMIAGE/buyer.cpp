#include "buyer.h"

Buyer::Buyer()
    : m_purchaseProposal(false)
{

}

bool Buyer::getPurchaseProposal() const
{
    return m_purchaseProposal;
}

std::set<Visits> Buyer::getVisits()
{
    return m_visits;
}

void Buyer::setPurchaseProposal(bool newValue)
{
    m_purchaseProposal = newValue;
}

void Buyer::displayVisits() const
{
    for(Visit v : m_visits)
    {
        v.display();
    }
}
