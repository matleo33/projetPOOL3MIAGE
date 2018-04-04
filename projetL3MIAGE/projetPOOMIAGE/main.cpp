#include <iostream>

#include "agency.h"
#include "buyer.h"
#include "seller.h"

using namespace std;

int main()
{
    Agency agency;
    Buyer buyer;
    Seller seller;
    RealEstate re(200000,"22 beauty street, London", 40);
    agency.addCustomer(seller);
    agency.addCustomer(buyer);
    agency.addRealEstate(seller, re);
    Visit visit(buyer, seller, re);
    buyer.getVisits().insert(visit); //TODO THAT IS UGLY
    buyer.displayVisits();
    visit.display();
    buyer.setPurchaseProposal(true);
    agency.sell(re);
    return 0;
}
