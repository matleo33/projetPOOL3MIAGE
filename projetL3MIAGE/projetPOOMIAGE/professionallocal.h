#ifndef PROFESSIONALLOCAL_H
#define PROFESSIONALLOCAL_H

#include <iostream>

class ProfessionalLocal
{
private:
    //TAILLE VITRINE
    //PRESENCE D'UNE PIECE POUR LE STOCKAGE DES MATERIAUX
public:
    ProfessionalLocal();
    virtual std::string getType() const;
};

#endif // PROFESSIONALLOCAL_H
