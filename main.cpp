#include "utils.hh"

enum ScreenType {
    End    = -1,
    Game_2 = 0,
    Game_1 = 1,
    Menu =  2
};


int main() {

    /* FONDO */
    sf::Texture background_t;
    if (not background_t.loadFromFile(string_background)) return 1;
    sf::Sprite background(background_t);
    background.setTextureRect(sf::IntRect(0,0, background_t.getSize().x/2,background_t.getSize().y));
    background.setScale(WEIGHT_S/float(background.getTextureRect().width),1);
    /* FONDO */

    /*CASA FABIO*/
    sf::Music  music_jump;
    music_jump.openFromFile(string_soundJump);
    sf::Texture fabio_t;
    if (not fabio_t.loadFromFile(string_fabioHouse)) return 2;
    House_Fabio house_fabio(fabio_t, music_jump);
    /*CASA FABIO*/

    /*MUSIC*
    sf::Music music;
    if(not music.openFromFile(string_song)) return 3;
    music.play();
    music.setLoop(true);
    *MUSIC */
    sf::Music boom;
    if (not boom.openFromFile(string_boom)) return 5;

    /*BOMBS*/
    std::list <Bombs *> traps_aina;
    sf::Texture traps_t;
    if(not traps_t.loadFromFile(string_bomb)) return 4;
    /*BOMBS*/

    sf::RenderWindow window(sf::VideoMode(WEIGHT_S , HEIGHT_S, 32), "game jam");
    sf::Clock clock;
    ScreenType screentype = Menu;
    unsigned int pos_background_x = 0;
    float acc = 0.0;
    int sprite_col = 0;
    int max_bombs = 5;

    while (window.isOpen()) {
        sf::Time time = clock.restart();
        float deltaTime = time.asSeconds();
        sf::Event event;
        if (screentype == Game_2 or screentype == Game_1) {
            while(window.pollEvent(event)) {
                if (event.type == sf::Event::Closed or (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)) window.close();
                else if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Space) house_fabio.change_state();
                else if ((screentype == Game_2 and event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::B and max_bombs > 0) or (screentype == Game_1)) {
                    traps_aina.push_front(new Bombs(traps_t));
                    --max_bombs;
                }
            }

            window.clear();
            window.draw(background);
            window.draw(house_fabio);
            for(std::list<Bombs *>::iterator it = traps_aina.begin(); it != traps_aina.end(); ) {
                Bombs* bombs = (*it);
                if (bombs->getPosition().x <= 0) {
                    delete bombs;
                    it = traps_aina.erase(it);
                    ++max_bombs;
                }
                else if (bombs->move(deltaTime, sf::IntRect(house_fabio.getPosition().x, house_fabio.getPosition().y, house_fabio.gtSize(), house_fabio.gtSize()))) {
                    boom.play();
                    screentype = End;
                    ++it;
                }
                else {
                    window.draw(*bombs);
                    ++it;
                }
            }
            window.display();
            house_fabio.animation(deltaTime);

            /*ANIMACION FONDO*/
            acc += deltaTime;
            if (acc >= 0.01) {
                if (pos_background_x < background_t.getSize().x/2) pos_background_x += 3;
                else pos_background_x = 0;
                background.setTextureRect(sf::IntRect(pos_background_x, 0, background_t.getSize().x/2,background_t.getSize().y));
                acc -= 0.01;
            }
            /* ANIMACION FONDO */
        }

        //FABIO PERDIO SU CASA
        else if (screentype == End) {
            sf::Texture titulo_end_t;
            if(not titulo_end_t.loadFromFile(string_end)) return 6;
            sf::Sprite title(titulo_end_t);
            title.setPosition(WEIGHT_S/3, HEIGHT_S/3);

            sf::Texture explosion_t;
            if(not explosion_t.loadFromFile(string_explosion)) return 7;
            sf::Sprite  explosion(explosion_t);
            explosion.setPosition(house_fabio.getPosition().x - house_fabio.getOrigin().x, house_fabio.getPosition().y - house_fabio.getOrigin().y);

            acc += deltaTime;
            if (acc >= 0.001) {
                sprite_col = (sprite_col + 1)%3;
                explosion.setTextureRect(sf::IntRect(explosion_t.getSize().x/3*sprite_col, 0, explosion_t.getSize().x/3, explosion_t.getSize().y));
                acc -= 0.001;
            }

            window.clear();
            window.draw(background);
            window.draw(house_fabio);
            window.draw(explosion);
            window.draw(title);
            window.display();

            while(window.pollEvent(event)) {
                if (event.type == sf::Event::Closed or (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)) window.close();
                else if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Num1) {
                    traps_aina.clear();
                    screentype = Game_1;
                }
                else if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Num2) {
                    traps_aina.clear();
                    screentype = Game_2;
                }
            }

        }

        //MENU PRINCIPAL
        else {
            sf::Texture menu_t;
            if (not menu_t.loadFromFile(string_menu)) return 8;
            sf::Sprite menu(menu_t);
            menu.setPosition(WEIGHT_S/3, HEIGHT_S/3);
            window.clear();
            window.draw(background);
            window.draw(menu);
            window.display();
            acc += deltaTime;
            if (acc >= 0.01) {
                if (pos_background_x < background_t.getSize().x/2) pos_background_x += 3;
                else pos_background_x = 0;
                background.setTextureRect(sf::IntRect(pos_background_x, 0, background_t.getSize().x/2,background_t.getSize().y));
                acc -= 0.01;
            }
            while(window.pollEvent(event)) {
                if (event.type == sf::Event::Closed or (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)) window.close();
                else if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Num2) screentype = Game_2;
                else if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Num1) screentype = Game_1;
            }
        }
    }
}

