#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <string>
#include "pacman.h"
#include "tile.h"

int main () {
    //28x31

    Tile arr[28][31];

    assignTiles(arr);

    const int IPS = 60;
    std::chrono::milliseconds iDuration(1000 / IPS);

    sf::RenderWindow window(sf::VideoMode(28 * 32, 31 * 32), "pacman");

    sf::RectangleShape pacman;

    pacman.setSize(sf::Vector2f(32, 32));
    pacman.setPosition(sf::Vector2f(14 * 32, 23 * 32));
    pacman.setFillColor(sf::Color::Yellow);
    
    int currentDirection = 0;

    while(window.isOpen()){
        auto startTime = std::chrono::high_resolution_clock::now();
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
        }
        int nextDirection = getInput();
        window.clear();
        for(int i = 0; i < 28; i++){
            for(int j = 0; j < 31; j++){
                window.draw(arr[i][j].rect);
            }
        }
        window.draw(pacman);
        window.display();

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

        if(elapsedTime < iDuration){
            std::this_thread::sleep_for(iDuration - elapsedTime);
        }
    }
    
    return 0;
}
