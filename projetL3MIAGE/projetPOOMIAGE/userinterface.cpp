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
    std::cin >> name;
    std::cout << "What is the first name of the new customer?" << std::endl;
    std::cin >> firstName;
    std::cout << "What is the address of the new customer?" << std::endl;
    std::cin >> address;

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
        m_agency->addCustomer(b);
        m_agency->save();
    } else {
        Seller s;
        s.setAddress(address);
        s.setFirstName(firstName);
        s.setName(name);
        m_agency->addCustomer(s);
        m_agency->save();
    }
    std::cout << "Customer inserted" << std::endl;
}

void UserInterface::addRealEstate()
{

}

void UserInterface::declareVisit()
{

}

void UserInterface::displayCustomers() const
{
    for (Customer c : this->m_agency->getCustomers())
    {
        std::cout << c.getFirstName() << " " << c.getName() << " is living at " << c.getAddress() << std::endl;
    }
}

void UserInterface::displayRealEstates() const
{
    for (std::pair<RealEstate,Customer> re :this->m_agency->getRealEstates())
    {
        std::cout << "Real estate n°" << re.first.getIdentifier() << " is available for $" << re.first.getPrice() << " and is sold by " << re.first.getSeller().getFirstName();
        std::cout << " " << re.first.getSeller().getName() << std::endl;
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
    std::cout << "6) Another stuff" << std::endl;
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
            std::cout << "Another stuff has been done." << std::endl;
        } else {
            std::cout << "Sorry, but your request was not recognized, please enter another one." << std::endl;
        }
    }

}
