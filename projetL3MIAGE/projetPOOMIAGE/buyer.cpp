#include "buyer.h"
#include "visit.h"

Buyer::Buyer()
    : m_purchaseProposal(false)
{

}

bool Buyer::getPurchaseProposal() const
{
    return m_purchaseProposal;
}

std::set<Visit> Buyer::getVisits()
{
    return m_visits;
}

void Buyer::setPurchaseProposal(bool newValue)
{
    m_purchaseProposal = newValue;
}

void Buyer::addVisit(Visit v)
{
    this->m_visits.insert(v);
}

void Buyer::displayVisits() const
{
    if (!m_visits.empty()){
        std::cout << this->m_firstName << " " << this->m_name << " visited those real estates :" << std::endl;
        for(Visit v : m_visits)
        {
            v.display();
        }
    } else {
        std::cout << this->m_firstName << " " << this->m_name << " didn't visit any real estate." << std::endl;
    }
}

void Buyer::display()
{
    std::cout << "Mr./Mrs. " << m_firstName << " " << m_name << " is living at " << m_address << std::endl;
    if (m_purchaseProposal)
    {
        std::cout << "Mr./Mrs." << m_firstName << " " << m_name << " has already made a purchase purposal." << std::endl;
    }
    displayVisits();
}
