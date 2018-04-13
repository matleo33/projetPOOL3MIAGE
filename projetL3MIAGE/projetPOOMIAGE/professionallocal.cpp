#include "professionallocal.h"

ProfessionalLocal::ProfessionalLocal()
{

}

ProfessionalLocal::ProfessionalLocal(unsigned short windowSizeSquareMeters, bool materialStorageRoom, unsigned int price, std::string address, short surface, Seller* seller)
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

void ProfessionalLocal::display() const{
    std::cout << "This is a local sold by " << m_seller->getFirstName() << " " << m_seller->getName() << std::endl;
    std::cout << "This local is located at " << m_address << std::endl;
    std::cout << "It is sold for $" << m_price << std::endl;
    if (m_materialStorageRoom)
    {
        std::cout << "It has a storage room." << std::endl;
    }
    std::cout << "The square meter size for the window is " << m_windowSizeSquareMeters << std::endl;
}

void ProfessionalLocal::displayElem() const{
    std::cout << "This real estate is a local located at " << m_address << "." << std::endl;
    std::cout << "It is sold for $" << m_price << "." << std::endl;
    if (m_materialStorageRoom)
    {
        std::cout << "It has a storage room." << std::endl;
    }
    std::cout << "The square meter size for the window is " << m_windowSizeSquareMeters << "." << std::endl;
}
