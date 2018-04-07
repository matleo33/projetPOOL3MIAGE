#include <iostream>

#include "agency.h"
#include "buyer.h"
#include "seller.h"
#include "visit.h"

using namespace std;

/*
 * Elea : Implémenter flat.h, flat.cpp, plot.h et plot.cpp
 * Marine : Faire un main qui permette de tester TOUTES LES FONCTIONNALITES du programme en testant TOUTES LES METHODES !
 * Yonnel : Ajouter une classe mère pour Buyer et Seller : La classe Person, faire la fonction de recherche des biens immobilier (question 2.2 du sujet)
 * Amaury : Faire en sorte que les professionallocal, plot, house, flat soient des RealEstates, faire la lecture et l'écriture dans les fichiers biens.txt, vendeurs.txt, acheteurs.txt
 * Edward : Implémenter professionallocal.h, professionallocal.cpp, seller.h et seller.cpp et vérifier les termes anglais
 * */

int main()
{
    //Exemple de main pour Marine
    Agency agency;
    Buyer buyer;
    Seller seller;
    RealEstate re(200000,"22 beauty street, London", 40, seller);
    agency.addCustomer(seller);
    agency.addCustomer(buyer);
    agency.addRealEstate(seller, re);
    Visit visit(buyer, seller, re);
    buyer.addVisit(visit);
    buyer.displayVisits();
    buyer.setPurchaseProposal(true);
    agency.sell(re);
    return 0;
}
