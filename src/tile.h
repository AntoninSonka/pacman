#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Tile{
private:
    //sf::Texture* texture;
public:
    bool isWall = false;
    sf::Vector2i gridCoords;

    sf::RectangleShape rect;

    void setup(sf::Vector2i, char);

    
};
