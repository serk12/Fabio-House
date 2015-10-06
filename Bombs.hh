#ifndef BOMBS_HH
#define BOMBS_HH
#include "utils.hh"

class Bombs : public sf::Sprite {
private:
    static const int SIZE = 50;
    static const int time_to_next = 0.05;
    static const float ANGLE = 10;
    static const float VEL = 400;
    float acc;

public:
    /*CONSTRUCTORA*/
    Bombs(sf::Texture &texture);
    /*MODIFICADORAS*/
    bool move(float deltaTime, const sf::IntRect &pos_house);
};

#endif // BOMBS_HH
