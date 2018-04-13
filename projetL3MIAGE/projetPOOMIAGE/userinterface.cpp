#include "userinterface.h"

UserInterface::UserInterface(Agency *agency)
    :m_quit(false), m_agency(agency)
{

}

bool UserInterface::isGood() const
{
    return !m_quit;
}

void UserInterface::addCustomer()
{
    std::string name;
    std::string firstName;
    std::string address;
    std::string type;

    std::cout << "What is the name of the new customer?" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "What is the first name of the new customer?" << std::endl;
    std::getline(std::cin, firstName);
    std::cout << "What is the address of the new customer?" << std::endl;
    std::getline(std::cin, address);

    std::cout << "Does the new customer want to buy a real estate ? (press 1 and validate), does he want to sell ? (press 2 and validate)" << std::endl;
    do {
        std::cin >> type;
    } while (type != "1" && type != "2");

    if (type == "1")
    {
        Buyer *b = new Buyer();
        b->setAddress(address);
        b->setFirstName(firstName);
        b->setName(name);
        m_agency->addBuyer(b);
        m_agency->save();
    } else {
        Seller *s = new Seller();
        s->setAddress(address);
        s->setFirstName(firstName);
        s->setName(name);
        m_agency->addSeller(s);
        m_agency->save();
    }
    std::cout << "Customer inserted" << std::endl;
}

bool UserInterface::isNumber(std::string str)
{
    if (str.length()==0)
    {
        return false;
    }
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            std::cout << "A number value is required." << std::endl;
            return false;
        }
    }
    return true;
}

void UserInterface::otherStuff()
{
    unsigned short stuff = rand()%3;
    if (stuff == 0)
    {
        system("sl");
    }
    if (stuff == 1)
    {
        std::cout << "Let's watch Star Wars IV : A new hope, make a pause during your work" << std::endl;
        usleep(3000000);
        system("telnet towel.blinkenlights.nl");
    }
    if (stuff == 2)
    {
        system ("xcowsay I love nix");
    }
}

Buyer * UserInterface::chooseBuyer()
{
    int i = 1;
    std::string choice;
    //Display available buyers
    for (Buyer * b : m_agency->getBuyers())
    {
        std::cout << i << ") " << b->getFirstName() << " " << b->getName() << std::endl;
        ++i;
    }

    //Read keyboard
    do {
        std::cin >> choice;
    } while (!isNumber(choice) && std::stoi(choice) > m_agency->getBuyers().size());

    return m_agency->getBuyers()[std::stoi(choice)-1];
}

RealEstate *UserInterface::chooseRealEstate(Seller *s)
{
    //display all the real estates of the Seller
    int i = 1;
    std::string choice;
    std::vector <RealEstate *> vre;
    for (std::pair<RealEstate*, Seller*> re : m_agency->getRealEstates())
    {
        if (re.second->getId() == s->getId())
        {
            std::cout << i << ") " << re.first->getAddress() << " : " << re.first->getPrice() << " ; " << re.first->getSurface() << std::endl;
            vre.push_back(re.first);
        }
    }
    //Make the user choose
    do {
        std::cin >> choice;
    } while (!isNumber(choice) && std::stoi(choice) > m_agency->getRealEstates().size());

    return vre[std::stoi(choice)-1];
}

Seller* UserInterface::chooseSeller()
{
    int i = 1;
    std::string choice;
    //Display available sellers
    for (Seller * s : m_agency->getSellers())
    {
        std::cout << i << ") " << s->getFirstName() << " " << s->getName() << std::endl;
        ++i;
    }

    //Read keyboard
    do {
        std::cin >> choice;
    } while (!isNumber(choice) && std::stoi(choice) > m_agency->getSellers().size());

    return m_agency->getSellers()[std::stoi(choice)-1];
}

void UserInterface::addRealEstate()
{
    if (m_agency->getSellers().size() == 0)
    {
        std::cout << "There is not any sellers, you can not add a real estate." << std::endl;
    } else {
        std::string type;
        std::string price;
        std::string address;
        std::string surface;
        Seller * seller;

        std::cout << "What is the type of the real estate?" << std::endl;
        std::cout << "1) Flat" << std::endl;
        std::cout << "2) House" << std::endl;
        std::cout << "3) Plot" << std::endl;
        std::cout << "4) Professional local" << std::endl;
        do {
            std::cin >> type;
        } while(!isNumber(type) || (std::stoi(type) > 4) || (std::stoi(type) == 0));

        std::cout << "What is the price of the real estate?" << std::endl;
        do {
            std::getline(std::cin, price);
        } while (!isNumber(price));

        std::cout << "What is the address of the real estate?" << std::endl;
        std::getline(std::cin, address);

        std::cout << "What is the surface available for this real estate?" << std::endl;
        do {
            std::cin >> surface;
        }  while (!isNumber(surface));

        seller = chooseSeller();

        switch (std::stoi(type))
        {
        case 1:
        {
            std::string rooms;
            std::cout << "How many rooms is the flat composed of?" << std::endl;
            do {
                std::cin >> rooms;
            } while (!isNumber(rooms));

            std::string floor;
            std::cout << "On which floor is the flat? (For ground floor put 0)" << std::endl;
            do {
                std::cin >> floor;
            } while (!isNumber(floor));

            bool garage;
            std::string stringGarage;
            std::cout << "Has your flat a garage? (1 for yes, 0 for no)" << std::endl;
            std::cin >> stringGarage;
            garage = std::stoi(stringGarage);

            bool cellar;
            std::string stringCellar;
            std::cout << "Has your flat a cellar? (1 for yes, 0 for no)" << std::endl;
            std::cin >> stringCellar;
            cellar = std::stoi(stringCellar);

            bool balcony;
            std::string stringBalcony;
            std::cout << "Has your flat a balcony? (1 for yes, 0 for no)" << std::endl;
            std::cin >> stringBalcony;
            balcony = std::stoi(stringBalcony);

            std::string nbFlatBuilding;
            std::cout << "How many flats are in the building ?" << std::endl;
            do {
                std::cin >> nbFlatBuilding;
            } while (!isNumber(nbFlatBuilding));

            Flat *f = new Flat(address, std::stoi(surface), std::stoi(price), seller, std::stoi(rooms), std::stoi(floor)
                               , garage, cellar, balcony, std::stoi(nbFlatBuilding));
            m_agency->addRealEstate(seller, f);
            break;
        }
        case 2 :
        {
            std::string nbRooms;
            std::cout << "How many rooms is the house composed of?" << std::endl;
            do {
                std::cin >> nbRooms;
            } while (!isNumber(nbRooms));

            bool swimmingPool;
            std::string stringSwimmingPool;
            std::cout << "Has the house got a swimming pool? (1 for yes, 0 for no)" << std::endl;
            do {
                std::cin >> stringSwimmingPool;
            } while (!isNumber(stringSwimmingPool) && std::stoi(stringSwimmingPool) > 1);
            swimmingPool = std::stoi(stringSwimmingPool);

            bool garage;
            std::string stringGarage;
            std::cout << "Has the house got a garage? (1 for yes, 0 for no)" << std::endl;
            do {
                std::cin >> stringGarage;
            } while (!isNumber(stringGarage) && std::stoi(stringGarage) > 1);
            garage = std::stoi(stringGarage);

            House *h = new House(address, std::stoi(surface), std::stoi(price), seller, std::stoi(nbRooms), swimmingPool, garage);
            m_agency->addRealEstate(seller, h);
            break;
        }
        case 3:
        {
            bool constructible;
            std::string stringConstructible;

            std::cout << "Is the plot constructible? (1 for yes, 0 for no)"<< std::endl;
            do {
                std::cin >> stringConstructible;
            } while (!isNumber(stringConstructible) && std::stoi(stringConstructible) > 1);
            constructible = std::stoi(stringConstructible);

            Plot *p = new Plot(constructible, std::stoi(price), address, std::stoi(surface), seller);
            m_agency->addRealEstate(seller, p);
            break;
        }
        case 4:
        {
            std::string windowSizeSquareMeters;
            std::cout << "What is the size of the window (in square meters)?" << std::endl;
            do {
                std::cin >> windowSizeSquareMeters;
            } while (!isNumber(windowSizeSquareMeters));

            bool materialStorageRoom;
            std::string stringMaterialStorageRoom;

            std::cout << "Does the local have a room for storing materials? (1 for yes, 0 for no)" << std::endl;
            do {
                std::cin >> stringMaterialStorageRoom;
            } while(!isNumber(stringMaterialStorageRoom) && std::stoi(stringMaterialStorageRoom) > 1);
            materialStorageRoom = std::stoi(stringMaterialStorageRoom);

            ProfessionalLocal *pl = new ProfessionalLocal(std::stoi(windowSizeSquareMeters), materialStorageRoom, std::stoi(price),address, std::stoi(surface), seller);
            m_agency->addRealEstate(seller, pl);
            break;
        }
        default:
        {
            break;
        }
        }
        m_agency->save();
    }
}

void UserInterface::displaySeller()
{
    Seller *s = chooseSeller();
    s->display();
}

void UserInterface::displayBuyer()
{
    Buyer *b = chooseBuyer();
    b->display();
}
void UserInterface::setInfoBuyer()
{
    std::string choice;
    Buyer *b = chooseBuyer();
    while (choice != "5")
    {
        std::cout << "Press 5 and valid to quit" << std::endl;
        std::cout << "What do you want to change?" << std::endl;
        std::cout << "1) The name of this buyer" << std::endl;
        std::cout << "2) The first name of this buyer" << std::endl;
        std::cout << "3) The address of this buyer" << std::endl;
        std::cout << "4) The purchase proposal" << std::endl;
        do {
            std::cin >> choice;
        } while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5");
        if (choice == "1")
        {
            std::cout << "What is the new name?" << std::endl;
            std::string newName;
            std::cin.ignore();
            std::getline(std::cin, newName);
            b->setName(newName);
        }
        if (choice == "2")
        {
            std::cout << "What is the new first name?" << std::endl;
            std::string newFirstName;
            std::cin.ignore();
            std::getline(std::cin,newFirstName);
            b->setFirstName(newFirstName);
        }
        if (choice == "3")
        {
            std::cout << "What is the new address?" << std::endl;
            std::string newAddress;
            std::cin.ignore();
            std::getline(std::cin, newAddress);
            b->setAddress(newAddress);
        }
        if (choice == "4")
        {
            std::string stringNewPurchaseProposal;
            bool newPurchaseProposal;
            std::cout << "Did the user make a purchase proposal? (1 for yes, 0 for no)" << std::endl;
            do {
                std::cin >> stringNewPurchaseProposal;
            } while (!isNumber(stringNewPurchaseProposal) && std::stoi(stringNewPurchaseProposal) > 1);
            newPurchaseProposal = std::stoi(stringNewPurchaseProposal);
            b->setPurchaseProposal(newPurchaseProposal);
        }
    }
}

void UserInterface::setInfoSeller()
{
    std::string choice;
    Seller *s = chooseSeller();
    while (choice != "4")
    {
        std::cout << "Press 4 and valid to quit" << std::endl;
        std::cout << "What do you want to change?" << std::endl;
        std::cout << "1) The name of this seller" << std::endl;
        std::cout << "2) The first name of this seller" << std::endl;
        std::cout << "3) The address of this seller" << std::endl;
        do {
            std::cin >> choice;
        } while (choice != "1" && choice != "2" && choice != "3" && choice != "4");
        if (choice == "1")
        {
            std::cout << "What is the new name?" << std::endl;
            std::string newName;
            std::cin.ignore();
            std::getline(std::cin, newName);
            s->setName(newName);
        }
        if (choice == "2")
        {
            std::cout << "What is the new first name?" << std::endl;
            std::string newFirstName;
            std::cin.ignore();
            std::getline(std::cin,newFirstName);
            s->setFirstName(newFirstName);
        }
        if (choice == "3")
        {
            std::cout << "What is the new address?" << std::endl;
            std::string newAddress;
            std::cin.ignore();
            std::getline(std::cin, newAddress);
            s->setAddress(newAddress);
        }
    }
}

void UserInterface::setInfoRealEstate()
{
    std::string choice;
    Seller *s = chooseSeller();
    RealEstate * re = chooseRealEstate(s);
    while (choice != "6")
    {

        //RealEstate Modifs
        std::cout << "Press 6 and valid to quit" << std::endl;
        std::cout << "Press 5 if you want to set something that is not in the following list" << std::endl;
        std::cout << "What do you want to change?" << std::endl;
        std::cout << "1) The price of the real estate" <<  std::endl;
        std::cout << "2) The address of the real estate" << std::endl;
        std::cout << "3) The surface of the real estate" << std::endl;
        std::cout << "4) The seller of the real estate" << std::endl;

        do {
            std::cin >> choice;
        } while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6");
        if (choice == "1")
        {
            std::cout << "What is the new price?" << std::endl;
            std::string newPrice;
            do {
                std::cin.ignore();
                std::getline(std::cin, newPrice);
            } while (!isNumber(newPrice));
            re->setPrice(std::stoi(newPrice));
        }
        if (choice == "2")
        {
            std::cout << "What is the new address?" << std::endl;
            std::string newAddress;
            std::cin.ignore();
            std::getline(std::cin, newAddress);
            re->setAddress(newAddress);
        }
        if (choice == "3")
        {
            std::cout << "What is the new surface?" << std::endl;
            std::string newSurface;
            do {
                std::cin.ignore();
                std::getline(std::cin, newSurface);
            } while (!isNumber(newSurface));
            re->setPrice(std::stoi(newSurface));
        }
        if (choice == "4")
        {
            std::cout << "Let's choose the new seller" << std::endl;
            usleep(2000000);
            Seller * newSeller = chooseSeller();
            re->setSeller(newSeller);
        }
        //Inherited type modif
        if (choice == "5")
        {
            char c = re->getSaveType();
            if (c == 'l')  //Case profesionnallocal
            {
                std::string choice2;
                ProfessionalLocal * pe = dynamic_cast<ProfessionalLocal*>(re);
                while(choice2 != "3")
                {
                    std::cout << "Press 3 and valid to quit " << std::endl;
                    std::cout << "What do you want to change?" << std::endl;
                    std::cout << "1) The material storage room presence" <<  std::endl;
                    std::cout << "2) The size of the window" <<  std::endl;
                    do {
                        std::cin >> choice2;
                    } while (choice2 != "1" && choice2 != "2" && choice2 != "3");
                    if (choice2 == "1")
                    {
                        std::string stringNewMaterialStorageRoom;
                        bool newMaterialStorageRoom;
                        std::cout << "Does the local have a material storage room? (1 for yes, 0 for no)" << std::endl;
                        do {
                            std::cin >> stringNewMaterialStorageRoom;
                        } while (!isNumber(stringNewMaterialStorageRoom) && std::stoi(stringNewMaterialStorageRoom) > 1);
                        newMaterialStorageRoom = std::stoi(stringNewMaterialStorageRoom);
                        pe->setMaterialStorageRoom(newMaterialStorageRoom);
                    }
                    if (choice2 == "2")
                    {
                        std::string newWindowSize;
                        std::cout << "What is the new size of the window?" << std::endl;
                        do {
                            std::cin >> newWindowSize;
                        } while (!isNumber(newWindowSize));
                        pe->setWindowSizeSquareMeters(std::stoi(newWindowSize));
                    }

                }
            } else if (c == 'm') //Case house
            {
                std::string choice2;
                House * h = dynamic_cast<House *>(re);
                while(choice2 != "4")
                {
                    std::cout << "Press 4 and valid to quit" << std::endl;
                    std::cout << "What do you want to change?" << std::endl;
                    std::cout << "1) The number of rooms" << std::endl;
                    std::cout << "2) The garage presence" << std::endl;
                    std::cout << "3) The swimming pool presence" << std::endl;
                    do {
                        std::cin >> choice2;
                    } while (choice2 != "1" && choice2 != "2" && choice2 != "3" && choice2 != "4");
                    if (choice2 == "1")
                    {
                        std::string newNumberRooms;
                        std::cout << "What is the new number of rooms?" << std::endl;
                        do {
                            std::cin >> newNumberRooms;
                        } while (!isNumber(newNumberRooms));
                        h->setNbRooms(std::stoi(newNumberRooms));
                    }
                    if (choice2 == "2")
                    {
                        std::string stringNewGarage;
                        bool newGarage;
                        std::cout << "Does the house have a garage? (1 for yes, 0 for no)" << std::endl;
                        do {
                            std::cin >> stringNewGarage;
                        } while (!isNumber(stringNewGarage) && std::stoi(stringNewGarage) > 1);
                        newGarage = std::stoi(stringNewGarage);
                        h->setGarage(newGarage);
                    }
                    if (choice2 == "3")
                    {
                        std::string stringNewSwimmingPool;
                        bool newSwimmingPool;
                        std::cout << "Does the house have a swimming pool? (1 for yes, 0 for no)" << std::endl;
                        do {
                            std::cin >> stringNewSwimmingPool;
                        } while (!isNumber(stringNewSwimmingPool) && std::stoi(stringNewSwimmingPool) > 1);
                        newSwimmingPool = std::stoi(stringNewSwimmingPool);
                        h->setSwimmingPool(newSwimmingPool);
                    }
                }
            } else if(c == 't') // case plot
            {
                std::string choice2;
                Plot * p = dynamic_cast<Plot *>(re);
                while (choice2 != "0")
                {
                    std::cout << "Do you want to change the constructible value of the plot? (1 for yes, 0 for no)" << std::endl;
                    std::cin >> choice2;
                    if (choice2 == "1")
                    {
                        std::string stringNewConstructible;
                        bool newConstructible;
                        std::cout << "Does the house have a garage? (1 for yes, 0 for no)" << std::endl;
                        do {
                            std::cin >> stringNewConstructible;
                        } while (!isNumber(stringNewConstructible) && std::stoi(stringNewConstructible) > 1);
                        newConstructible = std::stoi(stringNewConstructible);
                        p->setConstructible(newConstructible);
                    }
                }
            } else if (c == 'a') //case flat
            {
                std::string choice2;
                Flat *f = dynamic_cast<Flat *>(re);
                while (choice2 != "7")
                {
                    std::cout << "Press 7 and valid to quit" << std::endl;
                    std::cout << "What do you want to change?" << std::endl;
                    std::cout << "1) The number of rooms" << std::endl;
                    std::cout << "2) The garage presence" << std::endl;
                    std::cout << "3) The cellar presence" << std::endl;
                    std::cout << "4) The balcony presence" << std::endl;
                    std::cout << "5) The number of flats in building" << std::endl;
                    std::cout << "6) The floor of the flat" << std::endl;
                    do {
                        std::cin >> choice2;
                    } while (!isNumber(choice2) && std::stoi(choice2) > 7);
                    if (choice2 == "1")
                    {
                        std::string newNumberRooms;
                        std::cout << "What is the new number of rooms?" << std::endl;
                        do {
                            std::cin >> newNumberRooms;
                        } while (!isNumber(newNumberRooms));
                        f->setNbRooms(std::stoi(newNumberRooms));
                    }
                    if (choice2 == "2")
                    {
                        std::string stringNewGarage;
                        bool newGarage;
                        std::cout << "Does the house have a garage? (1 for yes, 0 for no)" << std::endl;
                        do {
                            std::cin >> stringNewGarage;
                        } while (!isNumber(stringNewGarage) && std::stoi(stringNewGarage) > 1);
                        newGarage = std::stoi(stringNewGarage);
                        f->setGarage(newGarage);
                    }
                    if (choice2 == "3")
                    {
                        std::string stringNewCellar;
                        bool newCellar;
                        std::cout << "Does the house have a cellar? (1 for yes, 0 for no)" << std::endl;
                        do {
                            std::cin >> stringNewCellar;
                        } while (!isNumber(stringNewCellar) && std::stoi(stringNewCellar) > 1);
                        newCellar = std::stoi(stringNewCellar);
                        f->setCellar(newCellar);
                    }
                    if (choice2 == "4")
                    {
                        std::string stringNewBalcony;
                        bool newBalcony;
                        std::cout << "Does the house have a balcony? (1 for yes, 0 for no)" << std::endl;
                        do {
                            std::cin >> stringNewBalcony;
                        } while (!isNumber(stringNewBalcony) && std::stoi(stringNewBalcony) > 1);
                        newBalcony = std::stoi(stringNewBalcony);
                        f->setBalcony(newBalcony);
                    }
                    if (choice2 == "5")
                    {
                        std::string newNumberFlat;
                        std::cout << "What is the new number of flats?" << std::endl;
                        do {
                            std::cin >> newNumberFlat;
                        } while (!isNumber(newNumberFlat));
                        f->setNbFlatsInBuilding(std::stoi(newNumberFlat));
                    }
                    if(choice2 == "6")
                    {
                        std::string newFloor;
                        std::cout << "What is the new floor of the flat?" << std::endl;
                        do {
                            std::cin >> newFloor;
                        } while (!isNumber(newFloor));
                        f->setNbFlatsInBuilding(std::stoi(newFloor));
                    }
                }
            }
        }
        choice = "6";
    }
}

void UserInterface::declareVisit()
{
    if (m_agency->getBuyers().size() == 0)
    {
        std::cout << "There is no buyer, you can not declare a visit." << std::endl;
    } else if (m_agency->getSellers().size()==0)
    {
        std::cout << "There is no seller, you can not declare a visit." << std::endl;
    } else if (m_agency->getRealEstates().size() == 0)
    {
        std::cout << "There is no real estate, you can not declare a visit." << std::endl;
    } else {
        Buyer *b;
        Seller *s;
        RealEstate * re;
        b = chooseBuyer();
        s = chooseSeller();
        re = chooseRealEstate(s);
        Visit v(*b,*s,*re);
        b->addVisit(v);
    }
}

void UserInterface::displayCustomers() const
{
    if (m_agency->getBuyers().size() + m_agency->getCustomers().size() +
            m_agency->getSellers().size()==0)
    {
        std::cout << "There is not any customers" << std::endl;
    }
    if (m_agency->getSellers().size()!=0)
    {
        std::cout << "Sellers : " << std::endl;
        for (Seller *s : this->m_agency->getSellers())
        {
            std::cout << s->getFirstName() << " " << s->getName() << " is living at " << s->getAddress() << std::endl;
        }
    }
    if (m_agency->getBuyers().size()!=0)
    {
        std::cout << "Buyers : " << std::endl;
        for (Buyer * b : this->m_agency->getBuyers())
        {
            std::cout << b->getFirstName() << " " << b->getName() << " is living at " << b->getAddress() << std::endl;
        }
    }
    if (m_agency->getCustomers().size()!=0)
    {
        std::cout << "Other Customers : " << std::endl;
        for (Customer c : this->m_agency->getCustomers())
        {
            std::cout << c.getFirstName() << " " << c.getName() << " is living at " << c.getAddress() << std::endl;
        }
    }
}

void UserInterface::removeBuyer()
{
    if (m_agency->getBuyers().size() == 0)
    {
        std::cout << "There is no buyer." << std::endl;
    }
    else {
        m_agency->removeBuyer();
        m_agency->save();
    }
}

void UserInterface::removeSeller()
{
    if (m_agency->getSellers().size()==0)
    {
        std::cout << "There is no seller." << std::endl;
    }
    else {
        m_agency->removeSeller();
        m_agency->save();
    }
}

void UserInterface::removeRealEstate()
{
    if (m_agency->getRealEstates().size()==0)
    {
        std::cout << "There is no real estate" << std::endl;
    } else {
        std::cout << "Choose your seller : " << std::endl;
        m_agency->removeRealEstate(chooseRealEstate(chooseSeller()));
        m_agency->save();
    }
}

void UserInterface::displayRealEstates() const
{
    if (this->m_agency->getRealEstates().size() == 0)
    {
        std::cout << "There is not any real estates" << std::endl;
    } else {
        for (std::pair<RealEstate*,Customer*> re : this->m_agency->getRealEstates())
        {
            std::cout << "The " << re.first->getType() << " n°" << re.first->getIdentifier() << " is available for $";
            std::cout << re.first->getPrice() << " and is sold by " << re.first->getSeller()->getFirstName();
            std::cout << " " << re.first->getSeller()->getName() << std::endl;
            re.first->display();
        }
    }
}

void UserInterface::researchRealEstateWithSuperficy(int superficyMin, int superficyMax, std::vector<RealEstate*> result)
{
    for(std::pair<RealEstate*,Seller*> it : m_agency->getRealEstates())
    {
        if(it.first->getSurface() <= superficyMax && it.first->getSurface() >= superficyMin)
        {
            result.push_back(it.first);
        }
    }
}

void UserInterface::researchRealEstateWithType(char realEstateType, std::vector<RealEstate*> result)
{
    for(std::pair<RealEstate*,Seller*> it : m_agency->getRealEstates())
    {
        if(it.first->getSaveType() == realEstateType)
        {
            result.push_back(it.first);
        }
    }
}

void UserInterface::researchRealEstateWithBudget(unsigned int budget, std::vector<RealEstate*> result)
{
    for (RealEstate* re : result)
    {
        if (re->getPrice() > budget)
        {
            result.erase(std::remove(result.begin(), result.end(), re), result.end());
        }
    }
}

std::vector<RealEstate*> UserInterface::getRealEstates()
{
    std::vector<RealEstate*> v;
    for (std::pair<RealEstate *,Seller*> p : m_agency->getRealEstates())
    {
        v.push_back(p.first);
    }
    return v;
}

void UserInterface::searchRealEstate()
{
    bool insearch = true;
    bool budgetDone = false;
    bool typeDone = false;
    bool superficyDone = false;
    std::string research;
    std::vector<RealEstate*> resultResearch = getRealEstates();
    std::string budget;
    std::string superficyMin;
    std::string superficyMax;
    char realEstateType;


    while (insearch)
    {
        std::cout << "Number of real estate(s) in your criterias : " << resultResearch.size() << std::endl;
        if (resultResearch.size()==1)
        {
            std::string stringPurchaseP;
            bool purchaseP;
            std::cout << "The real estate of your dreams is : " << std::endl;
            resultResearch.front()->display();
            std::cout << "Do you want to make a purchal proposal? (1 for yes, 0 for no)" << std::endl;
            do {
                std::cin >> stringPurchaseP;
            } while (!isNumber(stringPurchaseP) && std::stoi(stringPurchaseP));
            purchaseP = std::stoi(stringPurchaseP);
            if (purchaseP)
            {
                std::cout << "Who is the buyer?" << std::endl;
                Buyer *b = chooseBuyer();
                b->setPurchaseProposal(true);
            } else {
                insearch = false;
            }
        } else if(resultResearch.size()==0) {
            std::cout << "We don't have any real estate available" << std::endl;
        } else {
            std::cout << "Press b and valid to return to the menu !" << std::endl;
            std::cout << "Press d and valid to display all the user estates you want !" << std::endl;
            std::cout << "1) What is your max budget" << std::endl;
            std::cout << "2) What type of real estate are you looking for ?" << std::endl;
            std::cout << "3) What superficy ?" << std::endl;
            std::cin >> research;
            if (research == "b" || research == "back")
            {
                insearch = false;
            }
            else if(research == "1")
            {
                std::cout << "Please enter your maximum budget." << std::endl;
                if (!budgetDone)
                {
                    do {
                        std::cin >> budget;
                    } while (!isNumber(budget) || std::stoll(budget) > INT16_MAX);
                    researchRealEstateWithBudget(std::stoi(budget), resultResearch);
                    budgetDone = true;
                } else {
                    resultResearch = getRealEstates();
                    do {
                        std::cin >> budget;
                    } while (!isNumber(budget) || std::stoll(budget) > INT16_MAX);
                    researchRealEstateWithBudget(std::stoi(budget), resultResearch);
                    if (typeDone)
                    {
                        researchRealEstateWithType(realEstateType, resultResearch);
                    }
                    if (superficyDone)
                    {
                        researchRealEstateWithSuperficy(std::stoi(superficyMin),std::stoi(superficyMax),resultResearch);
                    }
                }
            }
            else if(research == "2")
            {
                std::cout << "Press the letter corresponding to your choice" << std::endl;
                std::cout << "l for Professional Local" << std::endl;
                std::cout << "t for Plot" << std::endl;
                std::cout << "m for House" << std::endl;
                std::cout << "a for Flat" << std::endl;
                if (!typeDone)
                {
                    do {
                        std::cin >> realEstateType;
                    } while (realEstateType != 'a' && realEstateType != 'm'&& realEstateType != 'l'&& realEstateType != 't');
                    researchRealEstateWithType(realEstateType, resultResearch);
                } else
                {
                    resultResearch = getRealEstates();
                    do {
                        std::cin >> realEstateType;
                    } while (realEstateType != 'a' && realEstateType != 'm'&& realEstateType != 'l'&& realEstateType != 't');
                    if (budgetDone)
                    {
                        researchRealEstateWithBudget(std::stoi(budget),resultResearch);
                    }
                    if (superficyDone)
                    {
                        researchRealEstateWithSuperficy(std::stoi(superficyMin),std::stoi(superficyMax),resultResearch);
                    }
                }
            }
            else if(research == "3")
            {
                if (!superficyDone)
                {
                    std::cout<< "Min superficy" << std::endl;
                    do{
                        std::cin >> superficyMin;
                    }
                    while(!isNumber(superficyMin));
                    std::cout<< "Max superficy" << std::endl;
                    do {
                        std::cin >> superficyMax;
                    }
                    while(!isNumber(superficyMax) && std::stoi(superficyMin) >= std::stoi(superficyMax));
                    researchRealEstateWithSuperficy(std::stoi(superficyMin), std::stoi(superficyMax), resultResearch);
                } else {
                    resultResearch = getRealEstates();

                    std::cout<< "Min superficy" << std::endl;
                    do{
                        std::cin >> superficyMin;
                    }
                    while(!isNumber(superficyMin));
                    std::cout<< "Max superficy" << std::endl;
                    do {
                        std::cin >> superficyMax;
                    }
                    while(!isNumber(superficyMax) && std::stoi(superficyMin) >= std::stoi(superficyMax));
                    researchRealEstateWithSuperficy(std::stoi(superficyMin), std::stoi(superficyMax), resultResearch);
                    if (budgetDone)
                    {
                        researchRealEstateWithBudget(std::stoi(budget),resultResearch);
                    }
                    if (typeDone)
                    {
                        researchRealEstateWithType(realEstateType, resultResearch);
                    }
                }
            } else if (research == "d")
            {
                for(RealEstate * re : resultResearch) {
                    std::cout << "The " << re->getType() << " n°" << re->getIdentifier() << " is available for $";
                    std::cout << re->getPrice() << " and is sold by " << re->getSeller()->getFirstName();
                    std::cout << " " << re->getSeller()->getName() << std::endl;
                }
            }
            else
            {
                std::cout << "Sorry, but your request was not recognized, please enter another one." << std::endl;
            }

        }
    }

}

void UserInterface::displayMenu() const
{
    std::cout << "Press q and validate to quit the application" << std::endl;
    std::cout << "Menu : " << std::endl;
    std::cout << "1) Add a customer" << std::endl;
    std::cout << "2) Add a real estate" << std::endl;
    std::cout << "3) Declare a visit" << std::endl;
    std::cout << "4) Display all customers" << std::endl;
    std::cout << "5) Display all real restates" << std::endl;
    std::cout << "6) Display the informations about a buyer" << std::endl;
    std::cout << "7) Display the informations about a seller" << std::endl;
    std::cout << "8) Set informations about a buyer" << std::endl;
    std::cout << "9) Set informations about a seller" << std::endl;
    std::cout << "10) Set informations about a real estate" << std::endl;
    std::cout << "11) Remove a seller" << std::endl;
    std::cout << "12) Remove a buyer" << std::endl;
    std::cout << "13) Remove a real estate (which we hope, is sent and not destroyed)" << std::endl;
    std::cout << "14) Search for the real estate of your dreams" << std::endl;
    std::cout << "15) Other stuff" << std::endl;
}

void UserInterface::listen()
{
    while (!m_quit)
    {
        displayMenu();
        std::cin >> m_request;
        if (m_request == "q" || m_request == "quit" || m_request == "exit")
        {
            m_quit = true;
        }
        else if (m_request == "1")
        {
            addCustomer();
            system("clear");
        }
        else if (m_request == "2")
        {
            addRealEstate();
            system("clear");
        }
        else if (m_request == "3")
        {
            declareVisit();
        }
        else if (m_request == "4")
        {
            system("clear");
            displayCustomers();
        }
        else if (m_request == "5")
        {
            system("clear");
            displayRealEstates();
        }
        else if (m_request == "6")
        {
            system("clear");
            displayBuyer();
        }
        else if (m_request == "7")
        {
            system("clear");
            displaySeller();
        }
        else if (m_request == "8")
        {
            system("clear");
            setInfoBuyer();
        }
        else if (m_request == "9")
        {
            system("clear");
            setInfoSeller();
        }
        else if (m_request == "10")
        {
            system("clear");
            setInfoRealEstate();
        }
        else if (m_request == "11")
        {
            removeSeller();
            system("clear");
        }
        else if (m_request == "12")
        {
            removeBuyer();
            system("clear");
        }
        else if (m_request == "13")
        {
            removeRealEstate();
            system("clear");
        }
        else if (m_request == "14")
        {
            system("clear");
            searchRealEstate();
            system("clear");
        }
        else if (m_request == "15")
        {
            system("clear");
            otherStuff();
        } else {
            std::cout << "Sorry, but your request was not recognized, please enter another one." << std::endl;
        }
    }

}
