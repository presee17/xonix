#ifndef _Map_
#define _Map_

#include <vector>
#include "Tile.h"

class Ship;
class Enemy;

class Map {
public:
    Map(int max_x, int max_y);
    ~Map();
    int getMax_x() {
        return max_x;
    }
    int getMax_y() {
        return max_y;
    }
    Tile** getCoordinate() {
        return coordinate;
    }
    bool updateMap();

    Tile& getTile(int x, int y) {
        return coordinate[x][y];
    }
    STATE getState(int x, int y) {
        return coordinate[x][y].getState();
    }
    void setState(int x, int y, STATE state) {
        coordinate[x][y].setState(state);
    }
    std::vector<Ship*> ship;
    std::vector<Enemy*> enemy;
private:
    int max_x;
    int max_y;
    Tile** coordinate;
};
#endif