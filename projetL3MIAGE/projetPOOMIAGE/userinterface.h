#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <string>
#include "agency.h"
#include "buyer.h"
#include "seller.h"
#include "visit.h"

class UserInterface
{
private:
    bool m_quit;
    std::string m_request;
    Agency *m_agency;
public:
    UserInterface() = delete;
    UserInterface(Agency *agency);

    void listen();

    //Getters
    bool isGood() const;

    //Setters

    //Other Methods
    void displayMenu() const;
    void displayCustomers() const;
    void displayRealEstates() const;

    void addCustomer();
    void addRealEstate();

    void declareVisit();

    bool isNumber(std::string str);

    Seller chooseSeller();
};

#endif // USERINTERFACE_H
