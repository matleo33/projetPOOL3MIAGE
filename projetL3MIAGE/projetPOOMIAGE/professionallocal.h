#ifndef PROFESSIONALLOCAL_H
#define PROFESSIONALLOCAL_H

#include <iostream>
#include "realestate.h"

class ProfessionalLocal : public RealEstate
{
private:
    //TAILLE VITRINE
    unsigned short m_windowSizeSquareMeters;
    //PRESENCE D'UNE PIECE POUR LE STOCKAGE DES MATERIAUX
    bool m_materialStorageRoom;
public:
    //Constructors
    ProfessionalLocal();
    ProfessionalLocal(unsigned short windowSizeSquareMeters, bool materialStorageRoom, unsigned int price, std::string address, short surface, Seller seller);

    //Getters
    virtual std::string getType() const;
    bool getMaterialStorageRoom() const;

    //Setters
    void setMaterialStorageRoom(bool newMaterialStorageRoom);
    void setWindowSizeSquareMeters(int newWindowSizeSquareMeters);
};

#endif // PROFESSIONALLOCAL_H
