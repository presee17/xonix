#ifndef _Tile_
#define _Tile_

enum STATE {
    BLACK_STATE = 0,
    GREY_STATE,
    RED_STATE,
    BLUE_STATE
};

class Tile {
public:
    int x;
    int y;
    STATE state;

    Tile(int x, int y) : x(x), y(y) {
        state = BLACK_STATE;
    }
    int getx() {
        return x;
    }
    int gety() {
        return y;
    }
    STATE getState() {
        return state;
    }

    void setState(STATE state) {
        this->state = state;
    }
};
#endif