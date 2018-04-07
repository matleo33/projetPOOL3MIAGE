#ifndef FLAT_H
#define FLAT_H


class Flat
{
private:
    unsigned short m_nbRooms;
    unsigned int m_floor;
    bool m_garage;
    bool m_cellar;
    bool m_balcony;
    unsigned int m_nbFlatsInBuilding;
public:
    Flat() = delete;

    Flat(unsigned short nbRooms, unsigned int floor, bool garage, bool cellar, bool balcony, unsigned int nbFlatsInBuilding);

    //Getters
    /*
     * Elea
     *
     * */

    //Setters
    /*
     * Elea
     *
     * */
};

#endif // FLAT_H
