#include "tile.h"

void Tile::setup(sf::Vector2i gridCoords, char ch){
    this->gridCoords = gridCoords;
    if(ch == 'X'){
        this->rect.setFillColor(sf::Color::Blue);
        this->isWall = true;
    }
    else if(ch == ' ' || ch == '.'){
        this->rect.setFillColor(sf::Color::Black);
        this->isWall = false;
    }
    this->rect.setPosition(sf::Vector2f(gridCoords.x * 32, gridCoords.y * 32));
    this->rect.setSize(sf::Vector2f(32, 32));
    
}
