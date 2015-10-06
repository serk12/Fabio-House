#ifndef BLOCS_HH
#define BLOCS_HH

#include "utils.hh"

class Block : public sf::RectangleShape {
private:
    static const int SIZE = 20;

public:
    /* constructoras */
    Block();

    /* Modificadoras */
    void spaw();

    void move();

    /* Consultoras */
    sf::Vector2f colision() const;

};

#endif // BLOCS_HH
