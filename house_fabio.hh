#ifndef HOUSE_FABIO_HH
#define HOUSE_FABIO_HH

#include "utils.hh"
enum State {
    down = 1,
    stop   =  0,
    jump  =  -1
};

class House_Fabio : public sf::Sprite {
private:
    static const float time_to_next = 0.05;
    static const float ANGLE = 15;
    static const int    SIZE     = 75;
    static const float    VEL_MAX = 350;
    float vel;
    float  acc;
    bool faceAnimation;
    State jump_state;
    sf::Music *sound_jump;
public:
    /*CONSTRUCTORA*/
    House_Fabio(sf::Texture &texture, sf::Music &music_jump);

    /*MODIFICADORA*/
    void animation(float deltaTime);

    void change_state();
    /*CONSULTORA*/
    int gtSize() const;

};

#endif // HOUSE_FABIO_HH
