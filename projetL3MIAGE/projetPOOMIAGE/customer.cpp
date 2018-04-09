#include "customer.h"

int Customer::m_id = 0;

Customer::Customer()
    :m_identifier(++m_id), m_name("Unknown"), m_firstName("Unknown"), m_address("Unknown")
{
}

Customer::Customer(std::string name, std::string firstName, std::string address)
    :m_identifier(++m_id), m_name(name), m_firstName(firstName), m_address(address)
{}

std::string Customer::getName() const
{
    return m_name;
}

std::string Customer::getFirstName() const
{
    return m_firstName;
}

std::string Customer::getAddress() const
{
    return m_address;
}

int Customer::getId() const
{
    return m_id;
}

void Customer::setName(std::string newName)
{
    this->m_name = newName;
}

void Customer::setFirstName(std::string newFirstName)
{
    this->m_firstName = newFirstName;
}

void Customer::setAddress(std::string newAddress)
{
    this->m_address = newAddress;
}

