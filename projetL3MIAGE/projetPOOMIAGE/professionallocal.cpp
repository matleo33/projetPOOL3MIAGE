#include "professionallocal.h"

ProfessionalLocal::ProfessionalLocal()
{

}

ProfessionalLocal::ProfessionalLocal(unsigned short windowSizeSquareMeters, bool materialStorageRoom, unsigned int price, std::string address, short surface, Seller seller)
    :RealEstate(price, address, surface, seller), m_windowSizeSquareMeters(windowSizeSquareMeters), m_materialStorageRoom(materialStorageRoom)
{
}

bool ProfessionalLocal::getMaterialStorageRoom() const
{
    return m_materialStorageRoom;
}

std::string ProfessionalLocal::getType() const
{
    return "professional local";
}

char ProfessionalLocal::getSaveType() const
{
    return 'l';
}

unsigned short ProfessionalLocal::getWindowSizeSquareMeters() const
{
    return m_windowSizeSquareMeters;
}

void ProfessionalLocal::setMaterialStorageRoom(bool newMaterialStorageRoom)
{
    m_materialStorageRoom = newMaterialStorageRoom;
}
void ProfessionalLocal::setWindowSizeSquareMeters(int newWindowSizeSquareMeters)
{
    m_windowSizeSquareMeters = newWindowSizeSquareMeters;
}


