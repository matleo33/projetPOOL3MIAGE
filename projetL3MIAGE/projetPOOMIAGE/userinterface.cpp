#include "userinterface.h"

UserInterface::UserInterface(Agency *agency)
    :m_quit(false), m_agency(agency),m_backToMenu(false)
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

    std::cout << "Does the new customer want to buy a real estate (press 1 and validate) or to sell one (press 2 and validate)?" << std::endl;
    do {
        std::cin >> type;
    } while (type != "1" && type != "2");

    if (type == "1")
    {
        Buyer b;
        b.setAddress(address);
        b.setFirstName(firstName);
        b.setName(name);
        m_agency->addBuyer(b);
        m_agency->save();
    } else {
        Seller s;
        s.setAddress(address);
        s.setFirstName(firstName);
        s.setName(name);
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

Buyer UserInterface::chooseBuyer()
{
    int i = 1;
    std::string choice;
    //Display available buyers
    for (Buyer b : m_agency->getBuyers())
    {
        std::cout << i << ") " << b.getFirstName() << " " << b.getName() << std::endl;
        ++i;
    }

    //Read keyboard
    do {
        std::cin >> choice;
    } while (!isNumber(choice) && std::stoi(choice) > m_agency->getBuyers().size());

    return m_agency->getBuyers()[std::stoi(choice)-1];
}

RealEstate UserInterface::chooseRealEstate(Seller s)
{
    //display all the real estates of the Seller
    int i = 1;
    std::string choice;
    std::vector <RealEstate> vre;
    for (std::pair<RealEstate*, Seller> re : m_agency->getRealEstates())
    {
        if (re.second.getId() == s.getId())
        {
            std::cout << i << ") " << re.first->getAddress() << " : " << re.first->getPrice() << " ; " << re.first->getSurface() << std::endl;
            vre.push_back(*re.first);
        }
    }
    //Make the user choose
    do {
        std::cin >> choice;
    } while (!isNumber(choice) && std::stoi(choice) > m_agency->getRealEstates().size());

    return vre[std::stoi(choice)-1];
}

Seller UserInterface::chooseSeller()
{
    int i = 1;
    std::string choice;
    //Display available sellers
    for (Seller s : m_agency->getSellers())
    {
        std::cout << i << ") " << s.getFirstName() << " " << s.getName() << std::endl;
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
    //Out of the method displaying an error message
    if (m_agency->getSellers().size() == 0)
    {
        std::cout << "There is not any sellers, you can not add a real estate." << std::endl;
    } else {
        std::string type;
        std::string price;
        std::string address;
        std::string surface;
        Seller seller;

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

        std::cout << "What is the surface available of this real estate?" << std::endl;
        do {
            std::cin >> surface;
        }  while (!isNumber(surface));

        seller = chooseSeller();

        switch (std::stoi(type))
        {
        case 1:
        {
            std::string rooms;
            std::cout << "How many rooms is the flat composed by?" << std::endl;
            do {
                std::cin >> rooms;
            } while (!isNumber(rooms));

            std::string floor;
            std::cout << "On which floor is the flat? (For ground floor put 0)" << std::endl;
            do {
                std::cin >> floor;
            } while (!isNumber(floor));

            bool garage;
            std::cout << "Has your flat a garage? (1 for yes, 0 for no)" << std::endl;
            std::cin >> garage;

            bool cellar;
            std::cout << "Has your flat a cellar? (1 for yes, 0 for no)" << std::endl;
            std::cin >> cellar;

            bool balcony;
            std::cout << "Has your flat a balcony? (1 for yes, 0 for no)" << std::endl;
            std::cin >> balcony;

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
//        case 2 :
//        {
//            House h();
//            m_agency->addRealEstate(seller, h);
//            break;
//        }
//        case 3:
//        {
//            Plot p();
//            m_agency->addRealEstate(seller, p);
//            break;
//        }
//        case 4:
//        {
//            ProfessionalLocal pl();
//            m_agency->addRealEstate(seller, pl);
//            break;
//        }
        default:
        {
            break;
        }
        }

        //RealEstate re = RealEstate((unsigned int)std::stoi(price), address, (unsigned short)std::stoi(surface), seller);
        //m_agency->addRealEstate(seller,re);
        m_agency->save();
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
        Buyer b;
        Seller s;
        RealEstate re;
        b = chooseBuyer();
        s = chooseSeller();
        re = chooseRealEstate(s);
        Visit v(b,s,re);
        b.addVisit(v);
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
        for (Seller s : this->m_agency->getSellers())
        {
            std::cout << s.getFirstName() << " " << s.getName() << " is living at " << s.getAddress() << std::endl;
        }
    }
    if (m_agency->getBuyers().size()!=0)
    {
        std::cout << "Buyers : " << std::endl;
        for (Buyer b : this->m_agency->getBuyers())
        {
            std::cout << b.getFirstName() << " " << b.getName() << " is living at " << b.getAddress() << std::endl;
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
        for (std::pair<RealEstate*,Customer> re : this->m_agency->getRealEstates())
        {
            std::cout << "The " << re.first->getType() << " n°" << re.first->getIdentifier() << " is available for $";
            std::cout << re.first->getPrice() << " and is sold by " << re.first->getSeller().getFirstName();
            std::cout << " " << re.first->getSeller().getName() << std::endl;
            re.first->display();
        }
    }
}

std::vector<RealEstate> UserInterface::researchRealEstateWithSuperficy(int superficyMin, int superficyMax)
{
    std::vector<RealEstate> result;
    for(std::pair<RealEstate*,Seller> it : m_agency->getRealEstates())
    {
        if(it.first->getSurface() <= superficyMax && it.first->getSurface() >= superficyMin)
        {
            result.push_back(*it.first);
        }
    }
    return result;
}

std::vector<RealEstate> UserInterface::researchRealEstateWithType(char realEstateType)
{
    std::vector<RealEstate> result;
    for(std::pair<RealEstate*,Seller> it : m_agency->getRealEstates())
    {
        if(it.first->getSaveType() == realEstateType)
        {
            result.push_back(*it.first);
        }
    }
    return result;
}

std::vector<RealEstate> UserInterface::researchRealEstateWithBudget(unsigned int budget)
{
    std::vector<RealEstate> result;
    for(std::pair<RealEstate*,Seller> it : m_agency->getRealEstates())
    {
        if(it.first->getPrice() <= budget)
        {
            std::cout << it.first->getPrice() << std::endl;
            result.push_back(*it.first);
        }
    }
    return result;
}

void UserInterface::searchRealEstate()
{

    //Ask for budget max
    //Ask for type of real estate (or various)
    //Ask for superficy min max
    //Ask for typical stuff related to the type chosen (Example : A balcony for a Flat)
    std::vector<RealEstate> resultResearch;
    unsigned int budget;
    std::string superficyMin;
    std::string superficyMax;
    char realEstateType;
    std::cout << "Press b and valid for back to the menu !" << std::endl;
    std::cout<< "1) What is your max budget" << std::endl;
    std::cout<< "2) What type of real estate are you looking for ?" << std::endl;
    std::cout<< "3) With superficy ?" << std::endl;

    std::cin >> m_research;

    if (m_research == "b" || m_research == "back")
    {
        m_backToMenu = true;
    }
    else if(m_research == "1")
    {
        std::cin >> budget;
        resultResearch = researchRealEstateWithBudget(budget);
    }
    else if(m_research == "2")
    {
        std::cout << "l for Professional Local" << std::endl;
        std::cout << "t for Plot" << std::endl;
        std::cout << "m for House" << std::endl;
        std::cout << "a for Flat" << std::endl;
        std::cin >> realEstateType;
        resultResearch = researchRealEstateWithType(realEstateType);
    }
    else if(m_research == "3")
    {
        std::cout<< "Min superficy" << std::endl;
        std::cin >> superficyMin;
        while(!isNumber(superficyMin))
        {
            std::cin >> superficyMin;
        }
        std::cout<< "Max superficy" << std::endl;
        std::cin >> superficyMax;
        while(!isNumber(superficyMax))
        {
            std::cin >> superficyMax;
        }
        resultResearch = researchRealEstateWithSuperficy(std::stoi(superficyMin), std::stoi(superficyMax));
    }
    else
    {
        std::cout << "Sorry, but your request was not recognized, please enter another one." << std::endl;
    }

    for(RealEstate re : resultResearch) {
        std::cout << "The " << re.getType() << " n°" << re.getIdentifier() << " is available for $";
        std::cout << re.getPrice() << " and is sold by " << re.getSeller().getFirstName();
        std::cout << " " << re.getSeller().getName() << std::endl;
    }
    if(resultResearch.empty())
    {
        std::cout << "No real estate correspond to your demand" << std::endl;
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
    std::cout << "6) Remove a seller" << std::endl;
    std::cout << "7) Remove a buyer" << std::endl;
    std::cout << "8) Remove a real estate" << std::endl;
    std::cout << "9) Search for the real estate of your dreams" << std::endl;
    std::cout << "10) Other stuff" << std::endl;
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
            removeSeller();
            system("clear");
        }
        else if (m_request == "7")
        {
            removeBuyer();
            system("clear");
        }
        else if (m_request == "8")
        {
            removeRealEstate();
            system("clear");
        }
        else if (m_request == "9")
        {
            while(!m_backToMenu)
            {
                system("clear");
                searchRealEstate();
                system("clear");
            }
        }
        else if (m_request == "10")
        {
            system("clear");
            std::cout << "Other stuff has been done." << std::endl;
        } else {
            std::cout << "Sorry, but your request was not recognized, please enter another one." << std::endl;
        }
    }

}
