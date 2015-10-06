#include "utils.hh"

/*CONSTRUCTORA*/
House_Fabio::House_Fabio (sf::Texture& texture, sf::Music &music_jump) : sf::Sprite(texture) {
    sf::Sprite::setTextureRect(sf::IntRect(0,0, texture.getSize().x/2, texture.getSize().y));
    sf::Sprite::setPosition(WEIGHT_S/20, HEIGHT_S - SIZE*1.33);
    sf::Sprite::setScale(SIZE/float(texture.getSize().x/2), SIZE/float(texture.getSize().y));
    sf::Sprite::setOrigin(sf::Sprite::getTextureRect().width/2, sf::Sprite::getTextureRect().height/2);
    acc = 0;
    vel = VEL_MAX;
    jump_state = stop;
    faceAnimation = false;
    sound_jump = &music_jump;
}

/*MODIFICADORA*/
void House_Fabio::animation(float deltaTime) {
    acc += deltaTime;
    if (acc >= time_to_next) {
        faceAnimation = not faceAnimation;
        sf::Sprite::setTextureRect(sf::IntRect(sf::Sprite::getTextureRect().width*faceAnimation, 0, sf::Sprite::getTextureRect().width, sf::Sprite::getTextureRect().height));
        acc -= time_to_next;
        sf::Sprite::setRotation(sf::Sprite::getRotation() + ANGLE);
    }

    if (jump_state != stop) {
        sf::Sprite::setPosition(sf::Sprite::getPosition().x, sf::Sprite::getPosition().y + int(jump_state)*(GRAVITY.y*0.5f*deltaTime*deltaTime + deltaTime*vel));
        vel += int(jump_state)*GRAVITY.y*deltaTime;
    }
    if (jump_state == jump and vel <=  0)  jump_state = down;
    else if (jump_state == down and sf::Sprite::getPosition().y >= HEIGHT_S - SIZE*1.33)  {
        jump_state = stop;
        vel = 0;
    }
}

void House_Fabio::change_state() {
    if (jump_state != down) {
        jump_state = jump;
         sound_jump->play();
    }
}

/*CONSULTORA*/

int House_Fabio::gtSize() const {
    return SIZE;
}
