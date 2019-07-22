#include "map.h"
#include "Tile.h"
#include "ship.h"
#include "enemy.h"
#include <SFML/Graphics.hpp>

Map::Map(int max_x, int max_y) {
    sf::Texture tile;
    tile.loadFromFile("E:/study/1/xonix/images/tiles.png");
    Tile::blue_tile = new sf::Sprite(tile);
    Tile::purple_tile = new sf::Sprite(tile);
    Tile::red_tile = new sf::Sprite(tile);
    Tile::green_tile = new sf::Sprite(tile);
    Tile::yellow_tile = new sf::Sprite(tile);
    Tile::skyblue_tile = new sf::Sprite(tile);
    Tile::orange_tile = new sf::Sprite(tile);
    Tile::tile_size = 5;
    Tile::blue_tile->setTextureRect(sf::IntRect(0, 0, Tile::tile_size, Tile::tile_size));
    Tile::purple_tile->setTextureRect(sf::IntRect(18, 0, Tile::tile_size, Tile::tile_size));
    Tile::red_tile->setTextureRect(sf::IntRect(36, 0, Tile::tile_size, Tile::tile_size));
    Tile::green_tile->setTextureRect(sf::IntRect(54, 0, Tile::tile_size, Tile::tile_size));
    Tile::yellow_tile->setTextureRect(sf::IntRect(72, 0, Tile::tile_size, Tile::tile_size));
    Tile::skyblue_tile->setTextureRect(sf::IntRect(90, 0, Tile::tile_size, Tile::tile_size));
    Tile::orange_tile->setTextureRect(sf::IntRect(90, 0, Tile::tile_size, Tile::tile_size));
    this->max_x = max_x;
    this->max_y = max_y;

    for (int i = 0; i < max_x; ++i) {
        for (int j = 0; j < max_y; ++j) {
            Tile* t = new Tile(i, j);
            if (i == 0 || j == 0) {
                t->setState(BLUE_STATE);
            }
            coordinate.push_back(t);
        }
    }
}

Map::~Map() {
    coordinate.clear();
}

Tile* Map::getTile(int x, int y) {
    return coordinate.at(max_x * y + x);
}

int Map::getMapHorizontalSize() {
    return max_x * Tile::tile_size;
}

int Map::getMapverticalSize() {
    return max_y * Tile::tile_size;
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
            coordinate;
            coordinate.at(max_x*y + x)->setState(BLACK_STATE);
            trace.pop_back();
            continue;
        }

        if (coordinate.at(max_x*y + x)->getState() == BLACK_STATE) {
            coordinate.at(max_x*y + x)->setState(RED_STATE);
        } else if (coordinate.at(max_x*y + x)->getState() == RED_STATE) {
            s->undo = true;
        }
    }

    //for (auto e : enemy) {
    //    e->x += e->dx;
    //    if (e->x < 0) e->x = 0;
    //    if (e->x > max_x) e->x = max_x;
    //    e->y += e->dy;
    //    if (e->y < 0) e->y = 0;
    //    if (e->y > max_y) e->y = max_y;

    //    if (coordinate[e->x][e->y].getState() == RED_STATE) {
    //        return false;
    //    }

    //    if (coordinate[e->x][e->y].getState() == GREY_STATE) {
    //        e->dx = -(e->dx); e->x += e->dx;
    //    }
    //    if (coordinate[e->x][e->y].getState() == GREY_STATE) {
    //        e->dy = -e->dy; e->y += e->dy;
    //    }
    //}
    return true;
}

void Map::drawMap(sf::RenderWindow* window) {
    for (Tile* t : coordinate) {
        t->drawTile(window);
    }
}