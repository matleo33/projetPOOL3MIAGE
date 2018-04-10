#include "professionallocal.h"

ProfessionalLocal::ProfessionalLocal()
{

}

ProfessionalLocal::ProfessionalLocal(unsigned short windowSizeSquareMeters, bool materialStorageRoom, unsigned int price, std::string address, short surface, Seller seller)
    :m_windowSizeSquareMeters(windowSizeSquareMeters),
      m_materialStorageRoom(materialStorageRoom)
{
    m_price = price;
    m_address = address;
    m_surface = surface;
    m_seller = seller;
}

bool ProfessionalLocal::getMaterialStorageRoom() const
{
    return m_materialStorageRoom;
}

std::string ProfessionalLocal::getType() const
{
    return "professional local";
}

void ProfessionalLocal::setMaterialStorageRoom(bool newMaterialStorageRoom)
{
    m_materialStorageRoom = newMaterialStorageRoom;
}
void ProfessionalLocal::setWindowSizeSquareMeters(int newWindowSizeSquareMeters)
{
    m_windowSizeSquareMeters = newWindowSizeSquareMeters;
}

char ProfessionalLocal::getSafeType() const
{
    return 'l';
}
