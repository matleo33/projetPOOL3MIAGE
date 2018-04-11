#include "agency.h"

std::vector<Customer> Agency::getCustomers() const
{
    return m_customers;
}

std::map<RealEstate*, Seller> Agency::getRealEstates() const
{
    return m_realEstates;
}

void Agency::addCustomer(Customer &customer)
{
    m_customers.push_back(customer);
}

void Agency::addRealEstate(Seller &seller, RealEstate *RealEstate)
{
    m_realEstates.insert(std::make_pair(RealEstate, seller));
}

void Agency::sell(RealEstate re)
{
    m_realEstates.erase(m_realEstates.find(&re));
    std::cout << "Real estate sold" << std::endl;
}

void Agency::save()
{
    saveSellers();
    saveBuyers();
    saveRealEstates();
}

void Agency::saveSellers()
{
    std::ofstream file_sellers("../save/sellers.txt", std::ios::out | std::ios::trunc);
    if(file_sellers) {
        for(Seller it : m_sellers) {
            file_sellers << it.getName() << ":" << it.getFirstName() << ":"
                         << it.getAddress() << "\n";
        }
        file_sellers.close();
    } else {
        std::cerr << "Can not open sellers.txt" << std::endl;
    }
}

void Agency::saveBuyers()
{
    std::ofstream file_buyers("../save/buyers.txt", std::ios::out | std::ios::trunc);
    if(file_buyers) {
        for(Buyer it : m_buyers) {
            file_buyers << it.getName() << ":" << it.getFirstName() << ":"
                        << it.getAddress() << "\n";
        }
        file_buyers.close();
    } else {
        std::cerr << "Can not open buyers.txt" << std::endl;
    }
}

void Agency::saveRealEstates()
{
    std::ofstream file_realEstates("../save/realEstates.txt", std::ios::out | std::ios::trunc);
    if(file_realEstates) {
        for (std::pair<RealEstate*,Customer> it : m_realEstates) {
            if(it.first->getSaveType() == 'a') {
                Flat *f = dynamic_cast<Flat*>(it.first);
                file_realEstates << "a:" << f->getAddress() << ":" << f->getSurface() << ":" << f->getPrice() << ":"
                                 << f->getSeller().getId() << ":" << f->getNbRooms() << ":" << f->getFloor()
                                 << ":" << f->getGarage() << ":" << f->getGarage() << ":" << f->getCellar()
                                 << ":" << f->getBalcony() << ":" << f->getNbFlatsInBuilding();

            } else if(it.first->getSaveType() == 'l') {
                ProfessionalLocal *pl = dynamic_cast<ProfessionalLocal*>(it.first);
                file_realEstates << "l:" << pl->getWindowSizeSquareMeters() << ":" << pl->getMaterialStorageRoom()
                                 << ":" << pl->getPrice() << ":" << pl->getAddress() << ":" << pl->getSurface()
                                 << ":" << pl->getSeller().getId();

            } else if(it.first->getSaveType() == 'm') {
                House *h = dynamic_cast<House*>(it.first);
                file_realEstates << "h:" << h->getPrice() << ":" << h->getAddress() << ":" << h->getSurface() << ":"
                                 << h->getSeller().getId() << ":" << h->getNbRooms() << ":"
                                 << h->hasSwimmingPool() << ":" << h->hasGarage();

            } else if (it.first->getSaveType() == 't') {
                Plot *p = dynamic_cast<Plot*>(it.first);
                file_realEstates << "t:" << p->getPrice() << ":" << p->getAddress() << ":" << p->getSurface() << ":"
                                 << p->getSeller().getId() << ":" << p->getConstructible();

            } else {
                //comportement en cas d'erreur ?
            }
        }
    }
    file_realEstates.close();
}

void Agency::open()
{
    openSellers();
    openBuyers();
    openRealEstates();
}

void Agency::openSellers()
{
    std::ifstream file_sellers("../save/sellers.txt", std::ios::in);
    if(file_sellers) {
        std::string content;
        while(std::getline(file_sellers, content)) {
            std::vector<std::string> seller_infos = split(content,':');
            Seller s;
            s.setName(seller_infos[0]);
            s.setFirstName(seller_infos[1]);
            s.setAddress(seller_infos[2]);
            m_sellers.push_back(s);
        }
    } else {
        std::cerr << "Can not open sellers.txt" << std::endl;
    }
}

void Agency::openBuyers()
{
    std::ifstream file_buyers("../save/buyers.txt", std::ios::in);
    if(file_buyers) {
        std::string content;
        while(std::getline(file_buyers, content)) {
            std::vector<std::string> buyer_infos = split(content,':');
            Buyer b;
            b.setName(buyer_infos[0]);
            b.setFirstName(buyer_infos[1]);
            b.setAddress(buyer_infos[2]);
            m_buyers.push_back(b);
        }
    } else {
        std::cerr << "Can not open buyers.txt" << std::endl;
    }
}

Flat Agency::openFlat(std::vector<std::string> infos)
{
    Flat f(infos[1], std::stoi(infos[2]), std::stoi(infos[3]), findSeller(infos[4]), std::stoi(infos[5]), std::stoi(infos[6]), std::stoi(infos[7]), std::stoi(infos[8]), std::stoi(infos[9]), std::stoi(infos[10]));
    return f;
}

void Agency::openRealEstates()
{
    std::ifstream file_realEstates("../save/realEstates.txt", std::ios::in);
    if(file_realEstates) {
        std::string content;
        while(std::getline(file_realEstates, content)) {
            std::vector<std::string> realEstate_infos = split(content,':');
            if(realEstate_infos[0] == "a")
            {
                openFlat(realEstate_infos);
                //open Flat
            } else if(realEstate_infos[0] == "l") {
                //open professionnal local
            } else if(realEstate_infos[0] == "m") {
                //open house
            } else if(realEstate_infos[0] == "t") {
                //open plot
            } else {
                //Comportement en cas d'erreur ?
            }



        }
    } else {
        std::cerr << "Can not open buyers.txt" << std::endl;
    }
}

Seller Agency::findSeller(std::string id) const
{
    for(Seller s : m_sellers) {
        if(s.getId() == std::stoi(id)) {
            return s;
        }
    }
}

std::vector<Seller> Agency::getSellers()const
{
    return m_sellers;
}

std::vector<Buyer> Agency::getBuyers() const
{
    return m_buyers;
}

void Agency::addBuyer(Buyer &b)
{
    m_buyers.push_back(b);
}

void Agency::addSeller(Seller &s)
{
    m_sellers.push_back(s);
}

std::vector<std::string> Agency::split(std::string stringToSplit, char separator)
{
    std::vector<std::string> stringSplit;
    std::string::size_type stTemp = stringToSplit.find(separator);

    while(stTemp != std::string::npos)
    {
        stringSplit.push_back(stringToSplit.substr(0, stTemp));
        stringToSplit = stringToSplit.substr(stTemp + 1);
        stTemp = stringToSplit.find(separator);
    }

    stringSplit.push_back(stringToSplit);

    return stringSplit;
}
bool Agency::isNumber(std::string str)
{
    if (str.length()==0)
    {
        return false;
    }
    for (unsigned short i = 0; i < str.length(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            std::cout << "A number value is required." << std::endl;
            return false;
        }
    }
    return true;
}

void Agency::removeBuyer()
{
    int i = 1;
    std::string choice;
    for (Buyer b : m_buyers)
    {
        std::cout << i << ") " << b.getFirstName() << " " << b.getName() << std::endl;
        ++i;
    }

    do {
        std::cin >> choice;
    } while (!isNumber(choice) && std::stoi(choice) > m_buyers.size());
    //Remove all their visits
    m_buyers[std::stoi(choice) - 1].getVisits().clear();
    //Remove the seller
    m_buyers.erase(m_buyers.begin()+std::stoi(choice) - 1);
}

void Agency::removeSeller()
{
    int i = 1;
    std::string choice;
    for (Seller s : m_sellers)
    {
        std::cout << i << ") " << s.getFirstName() << " " << s.getName() << std::endl;
        ++i;
    }

    do {
        std::cin >> choice;
    } while (!isNumber(choice) && std::stoi(choice) > m_sellers.size());
    //Remove all their real estates
    for (std::pair<RealEstate*, Seller> pre : m_realEstates)
    {
        if (pre.second.getId() == m_sellers[std::stoi(choice) - 1].getId())
        {
            m_realEstates.erase(pre.first);
        }
    }
    //Remove the seller
    m_sellers.erase(m_sellers.begin()+std::stoi(choice) - 1);
}

void Agency::removeRealEstate(RealEstate re)
{
    m_realEstates.erase(m_realEstates.find(&re));
}
