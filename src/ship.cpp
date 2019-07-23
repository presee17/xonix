#include <SFML/Graphics.hpp>
#include <time.h>

#include "ship.h"

using namespace sf;

Ship::Ship() {
    trace.push_back(new position(0, 0));
    v = 1;
    undo = false;
}

void Ship::up() {
    position* prev_pos = trace.back();
    for (int i = 1; i <= v; ++i) {
        trace.push_back(new position(prev_pos->first, prev_pos->second - i));
    }
}

void Ship::down() {
    position* prev_pos = trace.back();
    for (int i = 1; i <= v; ++i) {
        trace.push_back(new position(prev_pos->first, prev_pos->second + i));
    }
}
void Ship::left() {
    position* prev_pos = trace.back();
    for (int i = 1; i <= v; ++i) {
        trace.push_back(new position(prev_pos->first - i, prev_pos->second));
    }
}
void Ship::right() {
    position* prev_pos = trace.back();
    for (int i = 1; i <= v; ++i) {
        trace.push_back(new position(prev_pos->first + i, prev_pos->second));
    }
}

ZetShip::ZetShip() {
    v = 2;
}

BattleShip::BattleShip() {
    v = 1;
}