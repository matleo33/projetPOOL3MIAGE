#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

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
    Agency *m_agency;

    std::vector<RealEstate*> getRealEstates();

    Seller * chooseSeller();
    Buyer * chooseBuyer();
    RealEstate chooseRealEstate(Seller *s);
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
    void displaySeller();
    void displayBuyer();
    //display a real estate
    //Modify buyer
    //Modify seller (?)
    //Modify real estate

    void addCustomer();
    void addRealEstate();
    void declareVisit();

    void removeBuyer();
    void removeSeller();
    void removeRealEstate();

    void searchRealEstate();
    void researchRealEstateWithSuperficy(int superficyMin, int superficyMax, std::vector<RealEstate*> result);
    void researchRealEstateWithType(char realEstateType, std::vector<RealEstate *> result);
    void researchRealEstateWithBudget(unsigned int budget, std::vector<RealEstate *> result);

    bool isNumber(std::string str);

};

#endif // USERINTERFACE_H
