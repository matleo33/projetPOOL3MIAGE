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
    bool m_backToMenu;
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
    std::vector<RealEstate> researchRealEstateWithSuperficy(int superficyMin, int superficyMax);
    std::vector<RealEstate> researchRealEstateWithType(char realEstateType);
    std::vector<RealEstate> researchRealEstateWithBudget(unsigned int budget);

    bool isNumber(std::string str);

    Seller chooseSeller();
    Buyer chooseBuyer();
    RealEstate chooseRealEstate(Seller s);
};

#endif // USERINTERFACE_H
