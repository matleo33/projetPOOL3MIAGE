#include <iostream>

#include "agency.h"
#include "buyer.h"
#include "seller.h"
#include "userinterface.h"
#include "visit.h"

using namespace std;

/*
 * Elea : Implémenter flat.h, flat.cpp, plot.h et plot.cpp
 * Marine : Faire un main qui permette de tester TOUTES LES FONCTIONNALITES du programme en testant TOUTES LES METHODES !
 * Yonnel : Faire la fonction de recherche des biens immobilier (question 2.2 du sujet)
 * Amaury : Faire en sorte que les professionallocal, plot, house, flat soient des RealEstates, faire la lecture et l'écriture dans les fichiers biens.txt, vendeurs.txt, acheteurs.txt
 * Edward : Implémenter professionallocal.h, professionallocal.cpp, seller.h et seller.cpp et vérifier les termes anglais
 * Mathieu(qui ne fait pas rien) : Implémentation d'une classe interface qui va gérer les demandes de l'utilisateur en ligne de commande
 * */

int main(int argc, char ** argv)
{
    //Exemple de main pour Marine
    Agency agency;
    Buyer buyer;
    Seller seller;
    RealEstate re(200000,"22 beauty street, London", 40, seller);
    UserInterface ui(&agency);
    std::cout << "Welcome in your new Agency Handling software" << std::endl;
    while (ui.isGood())
    {
        ui.listen();
    }
    std::cout << "Thank you for using our software, see you !" << std::endl;
    /*agency.addCustomer(seller);
    agency.addCustomer(buyer);
    agency.addRealEstate(seller, re);
    Visit visit(buyer, seller, re);
    buyer.addVisit(visit);
    buyer.displayVisits();
    buyer.setPurchaseProposal(true);
    agency.sell(re);*/
    return 0;
}
