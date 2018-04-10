#include "agency.h"

std::vector<Customer> Agency::getCustomers() const
{
    return m_customers;
}

std::map<RealEstate, Seller> Agency::getRealEstates() const
{
    return m_realEstates;
}

void Agency::addCustomer(Customer &customer)
{
    m_customers.push_back(customer);
}

void Agency::addRealEstate(Seller &seller, RealEstate &RealEstate)
{
    m_realEstates.insert(std::make_pair(RealEstate, seller));
}

void Agency::sell(RealEstate re)
{
    m_realEstates.erase(m_realEstates.find(re));
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
        for (std::pair<RealEstate,Customer> it : m_realEstates) {
            if(it.first.getSafeType() == 'a') {
                Flat f = dynamic_cast<Flat&>(it.first);
                std::cout << 'a' << std::endl;

            } else if(it.first.getSafeType() == 'l') {
                ProfessionalLocal pl = dynamic_cast<ProfessionalLocal&>(it.first);
                std::cout << 'l' << std::endl;

            } else if(it.first.getSafeType() == 'm') {
                House h = dynamic_cast<House&>(it.first);
                std::cout << 'm' << std::endl;

            } else if (it.first.getSafeType() == 't') {
                Plot p = dynamic_cast<Plot&>(it.first);
                std::cout << 't' << std::endl;

            } else {
                //comportement en cas d'erreur ?
            }
        }
    }
    //file_realEstates << it.first.getIdentifier() << ":" << it.first.getSeller().getId() << ":" << "\n" << std::endl;

    file_realEstates.close();
}

void Agency::open()
{
    openSellers();
    openBuyers();
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
    for (std::pair<RealEstate, Seller> pre : m_realEstates)
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
    m_realEstates.erase(m_realEstates.find(re));
}
