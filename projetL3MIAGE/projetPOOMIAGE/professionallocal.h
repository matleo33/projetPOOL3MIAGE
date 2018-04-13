#ifndef PROFESSIONALLOCAL_H
#define PROFESSIONALLOCAL_H

#include <iostream>
#include "realestate.h"

class ProfessionalLocal : public RealEstate
{
private:
    unsigned short m_windowSizeSquareMeters;
    bool m_materialStorageRoom;
public:
    //Constructors
    ProfessionalLocal();
    ProfessionalLocal(unsigned short windowSizeSquareMeters, bool materialStorageRoom,
                      unsigned int price, std::string address, short surface, Seller *seller);

    //Getters
    virtual std::string getType() const;
    virtual char getSaveType() const;
    bool getMaterialStorageRoom() const;
    unsigned short getWindowSizeSquareMeters() const;

    //Setters
    void setMaterialStorageRoom(bool newMaterialStorageRoom);
    void setWindowSizeSquareMeters(int newWindowSizeSquareMeters);

    //Other method
    void display() const;
    void displayElem() const;
};

#endif // PROFESSIONALLOCAL_H
