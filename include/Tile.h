#ifndef _Tile_
#define _Tile_

enum STATE {
    BLACK_STATE = 0,
    BLUE_STATE,
    PURPLE_STATE,
    RED_STATE,
    GREEN_STATE,
    YELLOW_STATE,
    SKYBLUE_STATE,
    ORANGE_STATE
};
namespace sf {
    class Sprite;
    class RenderWindow;
}

class Tile {
public:
    static sf::Sprite* blue_tile;
    static sf::Sprite* purple_tile;
    static sf::Sprite* red_tile;
    static sf::Sprite* green_tile;
    static sf::Sprite* yellow_tile;
    static sf::Sprite* skyblue_tile;
    static sf::Sprite* orange_tile;
    static int tile_size;

    int x;
    int y;
    STATE state;

    sf::Sprite* sTile;

    Tile(int x, int y);

    int getx() {
        return x;
    }
    int gety() {
        return y;
    }

    void drawTile(sf::RenderWindow* window);

    STATE getState() {
        return state;
    }

    void setState(STATE state) {
        this->state = state;
    }
};
#endif