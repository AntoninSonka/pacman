#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <string>

int main () {

    std::string map[] = {
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "X............XX............X",
        "X.XXXX.XXXXX.XX.XXXXX.XXXX.X",
        "X.XXXX.XXXXX.XX.XXXXX.XXXX.X",
        "X.XXXX.XXXXX.XX.XXXXX.XXXX.X",
        "X..........................X",
        "X.XXXX.XX.XXXXXXXX.XX.XXXX.X",
        "X.XXXX.XX.XXXXXXXX.XX.XXXX.X",
        "X......XX....XX....XX......X",
        "XXXXXX.XXXXX.XX.XXXXX.XXXXXX",
        "     X.XXXXX.XX.XXXXX.X     ",
        "     X.XX..........XX.X     ",
        "     X.XX.XXX  XXX.XX.X     ",
        "XXXXXX.XX.X      X.XX.XXXXXX",
        "..........X      X..........",
        "XXXXXX.XX.X      X.XX.XXXXXX",
        "     X.XX.XXXXXXXX.XX.X     ",
        "     X.XX..........XX.X     ",
        "     X.XX.XXXXXXXX.XX.X     ",
        "XXXXXX.XX.XXXXXXXX.XX.XXXXXX",
        "X............XX............X",
        "X.XXXX.XXXXX.XX.XXXXX.XXXX.X",
        "X.XXXX.XXXXX.XX.XXXXX.XXXX.X",
        "X...XX................XX...X",
        "XXX.XX.XX.XXXXXXXX.XX.XX.XXX",
        "XXX.XX.XX.XXXXXXXX.XX.XX.XXX",
        "X......XX....XX....XX......X",
        "X.XXXXXXXXXX.XX.XXXXXXXXXX.X",
        "X.XXXXXXXXXX.XX.XXXXXXXXXX.X",
        "X..........................X",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXX"
    };

    const int IPS = 60;
    std::chrono::milliseconds iDuration(1000 / IPS);

    sf::RenderWindow window(sf::VideoMode(800, 800), "pacman");

    while(window.isOpen()){
        auto startTime = std::chrono::high_resolution_clock::now();
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
        }
        window.clear();
        window.display();

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

        if(elapsedTime < iDuration){
            std::this_thread::sleep_for(iDuration - elapsedTime);
        }
    }
    
    return 0;
}
