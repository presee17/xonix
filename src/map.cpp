#include "map.h"
#include "Tile.h"
#include "ship.h"
#include "enemy.h"

Map::Map(int max_x, int max_y) {
    this->max_x = max_x;
    this->max_y = max_y;

    coordinate = (Tile**)malloc(sizeof(Tile*)* max_x);
    for (int i = 0; i < max_y; ++i) {
        *(coordinate + i) = (Tile*)malloc(sizeof(Tile)* max_y);
    }

    for (int i = 0; i < max_x; ++i) {
        for (int j = 0; j < max_y; ++j) {
            Tile* tile = new Tile(j,i);
            coordinate[j][i] = *tile;
        }
    }

}

Map::~Map() {
    for (int i = 0; i < max_y; ++i) {
        delete[] * (coordinate + i);
    }
    delete[] coordinate;
}

bool Map::updateMap() {

    for (auto s : ship) {
        std::vector<position*> trace = s->getTrace();
        int x = trace.back()->first;
        int y = trace.back()->second;
        if (x < 0 || y < 0 || x > max_x || y > max_y) {
            trace.pop_back();
            continue;
        }
        if (s->undo) {
            setState(x, y, BLACK_STATE);
            trace.pop_back();
            continue;
        }

        if (getState(x,y) == BLACK_STATE) {
            setState(x,y, RED_STATE);
        } else if (getState(x,y) == RED_STATE) {
            s->undo = true;
        }
    }

    for (auto e : enemy) {
        e->x += e->dx;
        if (e->x < 0) e->x = 0;
        if (e->x > max_x) e->x = max_x;
        e->y += e->dy;
        if (e->y < 0) e->y = 0;
        if (e->y > max_y) e->y = max_y;

        if (coordinate[e->x][e->y].getState() == RED_STATE) {
            return false;
        }

        if (coordinate[e->x][e->y].getState() == GREY_STATE) {
            e->dx = -(e->dx); e->x += e->dx;
        }
        if (coordinate[e->x][e->y].getState() == GREY_STATE) {
            e->dy = -e->dy; e->y += e->dy;
        }
    }
    return true;
}
