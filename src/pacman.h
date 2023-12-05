#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "tile.h"

void assignTiles(Tile (&arr) [28][31]);

int getInput();

void movePacman(int&, int, sf::RectangleShape&);
