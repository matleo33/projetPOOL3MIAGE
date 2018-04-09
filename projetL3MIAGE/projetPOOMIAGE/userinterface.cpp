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

    std::cout << "Does the new customer want to buy a real estate (press 1 and valid) or to sell one (press 2 and valid)?" << std::endl;
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
    for (std::pair<RealEstate, Seller> re : m_agency->getRealEstates())
    {
        if (re.second.getId() == s.getId())
        {
            std::cout << i << ") " << re.first.getAddress() << " : " << re.first.getPrice() << " ; " << re.first.getSurface() << std::endl;
            vre.push_back(re.first);
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
    if (m_agency->getSellers().size() == 0)
    {
        std::cout << "There is not any seller, you can not add a real estate." << std::endl;
    } else {

        //Out of the method displaying an error message
        std::string price;
        std::string address;
        std::string surface;
        Seller seller;

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
        RealEstate re = RealEstate((unsigned int)std::stoi(price), address, (unsigned short)std::stoi(surface), seller);
        m_agency->addRealEstate(seller,re);
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
        std::cout << "There is not any customer" << std::endl;
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

void UserInterface::removeSeller()
{
    if (m_agency->getSellers().size()==0)
    {
        std::cout << "There is no seller." << std::endl;
    }
    else {
        m_agency->removeSeller();
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
    }
}

void UserInterface::displayRealEstates() const
{
    if (this->m_agency->getRealEstates().size() == 0)
    {
        std::cout << "There is not any real estate" << std::endl;
    } else {
        for (std::pair<RealEstate,Customer> re : this->m_agency->getRealEstates())
        {
            std::cout << "Real estate n°" << re.first.getIdentifier() << " is available for $" << re.first.getPrice() << " and is sold by " << re.first.getSeller().getFirstName();
            std::cout << " " << re.first.getSeller().getName() << std::endl;
        }
    }
}

void UserInterface::displayMenu() const
{
    std::cout << "Press q and valid to quit the application" << std::endl;
    std::cout << "Menu : " << std::endl;
    std::cout << "1) Add a customer" << std::endl;
    std::cout << "2) Add a real estate" << std::endl;
    std::cout << "3) Declare a visit" << std::endl;
    std::cout << "4) Display all customers" << std::endl;
    std::cout << "5) Display all real restates" << std::endl;
    std::cout << "6) Remove a seller" << std::endl;
    std::cout << "7) Remove a real estate" << std::endl;
    std::cout << "8) Another stuff" << std::endl;
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
        }
        else if (m_request == "2")
        {
            addRealEstate();
        }
        else if (m_request == "3")
        {
            declareVisit();
        }
        else if (m_request == "4")
        {
            displayCustomers();
        }
        else if (m_request == "5")
        {
            displayRealEstates();
        }
        else if (m_request == "6")
        {
            removeSeller();
        }
        else if (m_request == "7")
        {
            removeRealEstate();
        }
        else if (m_request == "8")
        {
            std::cout << "Another stuff has been done." << std::endl;
        } else {
            std::cout << "Sorry, but your request was not recognized, please enter another one." << std::endl;
        }
    }

}
