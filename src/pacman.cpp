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

void movePacman(int& currentDirection, int nextDirection, sf::RectangleShape& pacman, Tile (&arr)[28][31], sf::Vector2i& pacmanPos){

    static bool isThere = true;
    static int movementProgression = 0;
    static int countPorting = 0;

    if(countPorting == 0){
        if(pacmanPos.x < 0){
            pacmanPos.x = 28;
            pacman.setPosition(sf::Vector2f(28 * 32, pacman.getPosition().y));
            countPorting++;
        }
        else if(pacmanPos.x > 27){
            pacmanPos.x = -1;
            pacman.setPosition(sf::Vector2f(-1 * 32, pacman.getPosition().y));
            countPorting++;
        }
    }
    else if(countPorting == 18){
        countPorting = 0;
    }
    else{
        countPorting++;
    }

    if(isThere){
        switch(nextDirection){
            case 1:
                if(!arr[pacmanPos.x][pacmanPos.y - 1].isWall){
                    currentDirection = nextDirection;
                }
                break;
            case 2:
                if(!arr[pacmanPos.x][pacmanPos.y + 1].isWall){
                    currentDirection = nextDirection;
                }
                break;
            case 3:
                if(!arr[pacmanPos.x - 1][pacmanPos.y].isWall){
                    currentDirection = nextDirection;
                }
                break;
            case 4:
                if(!arr[pacmanPos.x + 1][pacmanPos.y].isWall){
                    currentDirection = nextDirection;
                }
                break;
            default:
                break;
        }
        isThere = false;
        switch(currentDirection){
            case 1:
                if(arr[pacmanPos.x][pacmanPos.y - 1].isWall){
                    isThere = true;
                    currentDirection = 0;
                }
                break;
            case 2:
                if(arr[pacmanPos.x][pacmanPos.y + 1].isWall){
                    isThere = true;
                    currentDirection = 0;
                }
                break;
            case 3:
                if(arr[pacmanPos.x - 1][pacmanPos.y].isWall){
                    isThere = true;
                    currentDirection = 0;
                }
                break;
            case 4:
                if(arr[pacmanPos.x + 1][pacmanPos.y].isWall){
                    isThere = true;
                    currentDirection = 0;
                }
                break;
            default:
                break;
        }
    }
    else{
        if(movementProgression == 8){
            movementProgression = 0;
            isThere = true;
            switch(currentDirection){
                case 1:
                    pacmanPos.y--;
                    break;
                case 2:
                    pacmanPos.y++;
                    break;
                case 3:
                    pacmanPos.x--;
                    break;
                case 4:
                    pacmanPos.x++;
                    break;
                default:
                    break;
            }
        }
        else{
            movementProgression++;
            switch(currentDirection){
                case 1:
                    pacman.move(sf::Vector2f(0, -4));
                    break;
                case 2:
                    pacman.move(sf::Vector2f(0, 4));
                    break;
                case 3:
                    pacman.move(sf::Vector2f(-4, 0));
                    break;
                case 4:
                    pacman.move(sf::Vector2f(4, 0));
                    break;
                default:
                    break;
            }
        }
    }
}
