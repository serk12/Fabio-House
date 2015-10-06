#include "utils.hh"

/*CONSTRUCTOR*/
Bombs::Bombs(sf::Texture &texture) : sf::Sprite(texture) {
    sf::Sprite::setPosition(WEIGHT_S - SIZE, HEIGHT_S - SIZE*1.75);
    sf::Sprite::setScale(SIZE/float(texture.getSize().x), SIZE/float(texture.getSize().y));
    sf::Sprite::setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    acc = 0;
}

bool Bombs::move(float deltaTime, const sf::IntRect &pos_house) {
    acc += deltaTime;
    if (acc >= time_to_next) {
        sf::Sprite::setRotation(sf::Sprite::getRotation() + ANGLE);
        sf::Sprite::setPosition(sf::Sprite::getPosition().x - VEL*deltaTime, sf::Sprite::getPosition().y);
        acc -= time_to_next;
    }
    return pos_house.top >= HEIGHT_S - pos_house.width*1.5 and pos_house.left + pos_house.width - pos_house.width/2 >= sf::Sprite::getPosition().x and sf::Sprite::getPosition().x >= pos_house.width/3;
}
