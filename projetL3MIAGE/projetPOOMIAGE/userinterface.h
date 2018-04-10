#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <string>
#include "agency.h"
#include "buyer.h"
#include "seller.h"
#include "visit.h"
#include "flat.h"
#include "house.h"
#include "plot.h"
#include "professionallocal.h"

class UserInterface
{
private:
    bool m_quit;
    std::string m_request;
    std::string m_research;
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

    void removeBuyer();
    void removeSeller();
    void removeRealEstate();

    void searchRealEstate();
    std::vector<RealEstate> researchRealEstateSuperficy(int superficyMin, int superficyMax);

    bool isNumber(std::string str);

    Seller chooseSeller();
    Buyer chooseBuyer();
    RealEstate chooseRealEstate(Seller s);
};

#endif // USERINTERFACE_H
