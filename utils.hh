#ifndef UTILS_HH
#define UTILS_HH

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <list>
#include <string>
#include "Bombs.hh"
#include "house_fabio.hh"

static const unsigned int       WEIGHT_S = 1500;
static const unsigned int       HEIGHT_S  = 532;
const sf::Vector2f                 GRAVITY(0, 550);
static const char*                string_background  = "city.png";
static const char*                string_fabioHouse  = "fabios_house.png";
static const char*                string_boom           = "rock_breaking.flac";
static const char*                string_menu           = "menu.png";
static const char*                string_explosion     = "explosion.png";
static const char*                string_end              = "letras_end.png";
static const char*                string_bomb           = "bomb_4.png";
static const char*                string_soundJump  = "jump_03.wav";
static const char*                string_song             = "fabio_lost.wav";

//cosas que hacer:
//canviar cancion
//limpiar main
#endif // UTILS_HH
