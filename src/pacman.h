#pragma once

#include <SFML/System/Vector2.hpp>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "tile.h"

void assignTiles(Tile (&arr) [28][31]);

int getInput();

void movePacman(int&, int, sf::RectangleShape&, Tile (&arr)[28][31], sf::Vector2i&);
