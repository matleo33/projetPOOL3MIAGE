#include <iostream>

#include "agency.h"
#include "buyer.h"
#include "seller.h"
#include "userinterface.h"
#include "visit.h"

using namespace std;

int main(int argc, char ** argv)
{
    srand(time(NULL));
    Agency agency;
    UserInterface ui(&agency);
    std::cout << "Welcome to your new Agency Handling software" << std::endl;
    while (ui.isGood())
    {
        ui.listen();
    }
    agency.save();
    std::cout << "Thank you for using our software, see you !" << std::endl;
    return 0;
}
