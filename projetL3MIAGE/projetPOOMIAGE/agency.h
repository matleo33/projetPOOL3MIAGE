#ifndef AGENCY_H
#define AGENCY_H

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <fstream>

#include "customer.h"
#include "realestate.h"
#include "buyer.h"
#include "visit.h"
#include "flat.h"
#include "professionallocal.h"
#include "house.h"
#include "plot.h"

class Agency
{
private:
    std::vector<Customer> m_customers;
    std::vector<Seller*> m_sellers;
    std::vector<Buyer*> m_buyers;
    std::map<RealEstate*, Seller*> m_realEstates;

    //Open methods
    std::vector<std::string> split(std::string stringToSplit, char separator);
    void openSellers();
    void openBuyers();
    void openFlat(std::vector<std::string> infos);
    void openProfessionalLocal(std::vector<std::string> infos);
    void openHouse(std::vector<std::string> infos);
    void openPlot(std::vector<std::string> infos);
    void openRealEstates();
    void open();
public:
    //Constructors
    Agency();

    //Getters
    std::vector<Customer> getCustomers() const;
    std::map<RealEstate *, Seller*> getRealEstates() const;
    std::vector<Seller*> getSellers() const;
    std::vector<Buyer*> getBuyers() const;
    //Setters

    //Other Methods
    void addCustomer(Customer &customer);
    void addRealEstate(Seller *seller, RealEstate *RealEstate);
    void addBuyer(Buyer *b);
    void addSeller(Seller *s);
    void removeBuyer();
    void removeSeller();
    void removeRealEstate(RealEstate *re);
    void sell(RealEstate *re);

    //save methods
    void save();
    void saveSellers();
    void saveBuyers();
    void saveRealEstates();


    Seller* findSeller(std::string id);
    bool isNumber(std::string str);
};

#endif // AGENCY_H
