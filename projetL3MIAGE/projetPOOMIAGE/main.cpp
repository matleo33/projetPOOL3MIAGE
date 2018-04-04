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
    RealEstate re;
    agency.addCustomer(seller);
    agency.addCustomer(buyer);
    agency.addRealEstate(seller, re);
    Visit visit(buyer, seller, re);
    buyer.getVisits().insert(visit);
    buyer.displayVisits();
    visit.display();
    buyer.setPurchaseProposal(true);
    agency.sell(re);
    return 0;
}
