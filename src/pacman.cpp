#include "pacman.h"

void assignTiles(Tile (&arr) [28][31]){
    std::string map[31] = {
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
    for(int i = 0; i < 28; i++){
        for(int j = 0; j < 31; j++){
            arr[i][j].setup(sf::Vector2i(i, j), map[j][i]);
        }
    }
}

int getInput(){
    static int direction = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        direction = 1;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        direction = 2;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        direction = 3;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        direction = 4;
    }
    return direction;
}

void movePacman(int& currentDirection, int nextDirection, sf::RectangleShape& pacman){
    
    //TODO udelat pohyb pomoci move metody a testovat pri tom kolize
    //TODO potom az to bude, udelat fluid movement pomoci jiny funkce a testovat jestli tam je, pokud tam bude, pouzit tuhle funkci

}
