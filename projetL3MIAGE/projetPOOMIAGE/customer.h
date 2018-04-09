#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

class Customer
{
protected:
    static int m_id;
    int m_identifier;
    std::string m_name;
    std::string m_firstName;
    std::string m_address;
public:
    //Constructor
    Customer();
    Customer(std::string name, std::string firstName, std::string address);

    //Getters
    std::string getName() const;
    std::string getFirstName() const;
    std::string getAddress() const;
    int getId() const;

    //Setters
    void setName(std::string newName);
    void setFirstName(std::string newFirstName);
    void setAddress(std::string newAddress);
};

#endif // CUSTOMER_H
